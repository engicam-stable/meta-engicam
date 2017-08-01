/*
 *
 * Copyright (C) 2012 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 */
#ifdef CSR_WIFI_SDIO_EVALUATION_TEST

#include "csr_time.h"

#include "csr_wifi_hip_unifi.h"
#include "csr_wifi_hip_card_sdio.h"

#include "unifi_priv.h"

#define PRINT                                                       unifi_warning

#define NUMBER_OF_ITERATIONS                                        1000

#define DATA_PACKET_LENGTH                                          1500
#define PACKET_LENGTH                                               100

#define NANOSECONDS                                                 (CSR_SCHED_MILLISECOND * 1000 * 1000)
#define MICROSECONDS_IN_NANOSECONDS                                 (1000)

#define SDIO_CLOCK_HZ                                               50000000
#define SDIO_LINES                                                  4

#define SDIO_CMD_IN_BITS                                            48
#define SDIO_RES_IN_BITS                                            48
#define SDIO_GAP_IN_BITS                                            4

#define SDIO_CMD_IN_NANOSECONDS                                     ((SDIO_CMD_IN_BITS + SDIO_GAP_IN_BITS + SDIO_RES_IN_BITS) * (NANOSECONDS / SDIO_CLOCK_HZ))

#define SDIO_CMD53_START_END_IN_BITS                                2
#define SDIO_CMD53_CRC_IN_BITS                                      16

#define SDIO_CMD53_GAP_READ_IN_NANOSECONDS                          113 /* Gaps between data blocks found by test */
#define SDIO_CMD53_GAP_WRITE_IN_NANOSECONDS                         246 /* Gaps between data blocks found by test */

#define SDIO_CMD53_NUMBER_OF_BLOCKS(_len, _blockSize)               ((_len) / (_blockSize) > 0?((_len) / (_blockSize)) : 1)
#define SDIO_CMD53_DATA_BITS_PER_LINE(_len)                         ((_len) * 8 / SDIO_LINES)
#define SDIO_CMD53_BITS_PER_LINE(_len, _blockSize)                  (SDIO_CMD53_DATA_BITS_PER_LINE(_len) + \
                                                                     (SDIO_CMD53_START_END_IN_BITS + SDIO_CMD53_CRC_IN_BITS) * SDIO_CMD53_NUMBER_OF_BLOCKS(_len, _blockSize))

#define SDIO_CMD53_READ_IN_NANOSECONDS(_len, _blockSize)            (SDIO_CMD_IN_NANOSECONDS + \
                                                                     (SDIO_CMD53_BITS_PER_LINE(_len, _blockSize) * (NANOSECONDS / SDIO_CLOCK_HZ)) + \
                                                                     SDIO_CMD53_GAP_READ_IN_NANOSECONDS * SDIO_CMD53_NUMBER_OF_BLOCKS(_len, _blockSize))

#define SDIO_CMD53_WRITE_IN_NANOSECONDS(_len, _blockSize)           (SDIO_CMD_IN_NANOSECONDS + \
                                                                     (SDIO_CMD53_BITS_PER_LINE(_len, _blockSize) * (NANOSECONDS / SDIO_CLOCK_HZ)) + \
                                                                     SDIO_CMD53_GAP_WRITE_IN_NANOSECONDS * SDIO_CMD53_NUMBER_OF_BLOCKS(_len, _blockSize))

#define SDIO_CMD52_IN_MICROSECONDS                                  ((SDIO_CMD_IN_NANOSECONDS + 500) / MICROSECONDS_IN_NANOSECONDS)
#define SDIO_CMD53_WRITE_IN_MICROSECONDS(_dataLength, _blockSize)   ((SDIO_CMD53_WRITE_IN_NANOSECONDS(_dataLength, _blockSize) + 500) / MICROSECONDS_IN_NANOSECONDS)
#define SDIO_CMD53_READ_IN_MICROSECONDS(_dataLength, _blockSize)    ((SDIO_CMD53_READ_IN_NANOSECONDS(_dataLength, _blockSize) + 500) / MICROSECONDS_IN_NANOSECONDS)

#define TIME_SCALE_1                                                (7)
#define TIME_SCALE_2                                                (13)
#define TIME_SCALE_3                                                (48)

static CsrCharString TIME_SCALE_1_TEXT[]     =                      "VERY FAST";
static CsrCharString TIME_SCALE_2_TEXT[]     =                      "FAST";
static CsrCharString TIME_SCALE_3_TEXT[]     =                      "OK";
static CsrCharString TIME_SCALE_4_TEXT[]     =                      "SLOW";

#define CALCULATE_DATA_SIZE(_packetLength, _blockSize)              ((_packetLength) % (_blockSize) == 0?(_packetLength) : ((_packetLength) / (_blockSize) + 1) * (_blockSize))

#define CMD52_WRITE(_card, _data)                                   CsrSdioF0Write8(_card->sdio_if, SDIO_FN0_BLOCK_SIZE, _data)
#define CMD52_READ(_card, _data)                                    CsrSdioF0Read8(_card->sdio_if, 0x1, _data)

#define CMD53_WRITE(_card, _data, _size)                            CsrSdioWrite(_card->sdio_if, 0x1, _data, _size)
#define CMD53_READ(_card, _data, _size)                             CsrSdioRead(_card->sdio_if, 0x1, _data, _size)

#define PRINT_SCALE(_card, _t_1, _t_2, _t_3)                        PRINT(_card->ospriv, "%s <= %u us < %s <= %u us < %s <= %u us < %s\n", \
                                                                          TIME_SCALE_1_TEXT, _t_1, \
                                                                          TIME_SCALE_2_TEXT, _t_2, \
                                                                          TIME_SCALE_3_TEXT, _t_3, \
                                                                          TIME_SCALE_4_TEXT)

#define PRINT_RESULT_CMD52(_card, _test, _min, _max, _avg, _res)    PRINT(_card->ospriv, "%s -             - min: %5u us - max: %5u us - avg: %5u us (%s)\n", _test, _min, _max, _avg, _res);
#define PRINT_RESULT(_card, _test, _bytes, _min, _max, _avg, _res)  PRINT(_card->ospriv, "%s - %5u bytes - min: %5u us - max: %5u us - avg: %5u us (%s)\n", _test, _bytes, _min, _max, _avg, _res);

typedef struct SdioResults
{
    CsrTime   start;
    CsrTime   end;
    CsrTime   time;
    CsrUint32 size;
} SdioResults;

static CsrCharString* time2ScaleText(CsrTime time, CsrUint32 time2, CsrUint8 numberOfOperations)
{
    CsrInt32 t;

    t = (time - time2) / numberOfOperations;

    if (t <= TIME_SCALE_1)
    {
        return TIME_SCALE_1_TEXT;
    }
    else if (t <= TIME_SCALE_2)
    {
        return TIME_SCALE_2_TEXT;
    }
    else if (t <= TIME_SCALE_3)
    {
        return TIME_SCALE_3_TEXT;
    }
    else
    {
        return TIME_SCALE_4_TEXT;
    }
}


static void updateSdioResults(SdioResults *sdioResults, CsrTime start, CsrTime end)
{
    sdioResults->start = start;
    sdioResults->end = end;
    sdioResults->time = end - start;
}


static CsrResult writeCmd52(card_t *card, SdioResults *sdioResults)
{
    CsrResult r;
    CsrTime start, end;
    CsrUint8 data = 0x47;

    start = CsrTimeGet(NULL);
    r = CMD52_WRITE(card, data);
    end = CsrTimeGet(NULL);

    updateSdioResults(sdioResults, start, end);

    return r;
}


static CsrResult readCmd52(card_t *card, SdioResults *sdioResults)
{
    CsrResult r;
    CsrTime start, end;
    CsrUint8 data = 0x47;

    start = CsrTimeGet(NULL);
    r = CMD52_READ(card, &data);
    end = CsrTimeGet(NULL);

    updateSdioResults(sdioResults, start, end);

    return r;
}


static CsrResult writeCmd53(card_t *card, SdioResults *sdioResults, CsrUint32 size)
{
    CsrResult r;
    CsrTime start, end;

    CsrUint8 *data = CsrMemAllocDma(size);
    CsrMemSet(data, 0, size);

    start = CsrTimeGet(NULL);
    r = CMD53_WRITE(card, data, size);
    end = CsrTimeGet(NULL);

    updateSdioResults(sdioResults, start, end);

    CsrMemFreeDma(data);

    return r;
}


static CsrResult readCmd53(card_t *card, SdioResults *sdioResults, CsrUint32 size)
{
    CsrResult r;
    CsrTime start, end;

    CsrUint8 *data = CsrMemAllocDma(size);
    CsrMemSet(data, 0, size);

    start = CsrTimeGet(NULL);
    r = CMD53_READ(card, data, size);
    end = CsrTimeGet(NULL);

    updateSdioResults(sdioResults, start, end);

    CsrMemFreeDma(data);

    return r;
}


static CsrResult sequenceWorkFlow(card_t *card, SdioResults *sdioResults, CsrUint32 blockSize, CsrBool chaining)
{
    CsrTime start, end;
    CsrResult r = CSR_RESULT_SUCCESS;

    CsrUint32 sizeData = CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize);
    CsrUint8 *data = CsrMemAllocDma(sizeData);

    CsrUint32 sizePacket = CALCULATE_DATA_SIZE(PACKET_LENGTH, blockSize);
    CsrUint8 *dataPacket = CsrMemAllocDma(sizePacket);

    start = CsrTimeGet(NULL);

#ifdef CSR_WIFI_SDIO_USE_QUEUE
    if (chaining)
    {
        CsrWifiSdioQueueStart();
    }
#endif /* CSR_WIFI_SDIO_USE_QUEUE */

    /* Simulate sending data */
    sdioResults->size = sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate flushing */
    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate reading acks */
    sdioResults->size += sizePacket;
    if ((r = CMD53_READ(card, dataPacket, sizePacket)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizePacket;
    if ((r = CMD53_READ(card, dataPacket, sizePacket)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate sending data */
    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate flushing */
    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate sending data */
    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    sdioResults->size += sizeData;
    if ((r = CMD53_WRITE(card, data, sizeData)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    /* Simulate flushing */
    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

    if ((r = CMD52_WRITE(card, 0x47)) != CSR_RESULT_SUCCESS)
    {
        goto free_data;
    }

#ifdef CSR_WIFI_SDIO_USE_QUEUE
    if (chaining)
    {
        r = CsrWifiSdioQueueFlush();
    }
#endif /* CSR_WIFI_SDIO_USE_QUEUE */

    end = CsrTimeGet(NULL);

    updateSdioResults(sdioResults, start, end);

free_data:
    CsrMemFreeDma(dataPacket);
    CsrMemFreeDma(data);

    return r;
}


static void calculateMinMaxTotal(SdioResults *sdioResults, CsrTime *min, CsrTime *max, CsrTime *total)
{
    *min = CSRMIN(*min, sdioResults->time);
    *max = CSRMAX(*max, sdioResults->time);
    *total += sdioResults->time;
}


static void sdio_evaluation_test(card_t *card)
{
    CsrResult r;
    CsrTime cmdTime, cmd52Time, cmd53Time;
    CsrUint8 numberOfOperations;

    SdioResults *sdioResultsCmd52Write;
    SdioResults *sdioResultsCmd52Read;
    SdioResults *sdioResultsCmd53Write;
    SdioResults *sdioResultsCmd53Read;
    SdioResults *sdioResultsCmd53WriteL;
    SdioResults *sdioResultsCmd53ReadL;
    SdioResults *sdioResultsCmd53WriteG;
    SdioResults *sdioResultsCmd53ReadG;
    SdioResults *sdioResultsMtuWrite;
    SdioResults *sdioResultsMtuRead;
    SdioResults *sdioResultsSeq;
    SdioResults *sdioResultsSeqChaining;

    CsrUint32 blockSize = card->sdio_if->blockSize;
    CsrUint32 count = 0;

    CsrTime sdioCmd52WriteMin = 0xFFFFFFFF;
    CsrTime sdioCmd52WriteMax = 0x0;
    CsrTime sdioCmd52WriteTotal = 0x0;
    CsrTime sdioCmd52WriteAvg = 0x0;

    CsrTime sdioCmd52ReadMin = 0xFFFFFFFF;
    CsrTime sdioCmd52ReadMax = 0x0;
    CsrTime sdioCmd52ReadTotal = 0x0;
    CsrTime sdioCmd52ReadAvg = 0x0;

    CsrTime sdioCmd53WriteMin = 0xFFFFFFFF;
    CsrTime sdioCmd53WriteMax = 0x0;
    CsrTime sdioCmd53WriteTotal = 0x0;
    CsrTime sdioCmd53WriteAvg = 0x0;

    CsrTime sdioCmd53ReadMin = 0xFFFFFFFF;
    CsrTime sdioCmd53ReadMax = 0x0;
    CsrTime sdioCmd53ReadTotal = 0x0;
    CsrTime sdioCmd53ReadAvg = 0x0;

    CsrTime sdioCmd53WriteLMin = 0xFFFFFFFF;
    CsrTime sdioCmd53WriteLMax = 0x0;
    CsrTime sdioCmd53WriteLTotal = 0x0;
    CsrTime sdioCmd53WriteLAvg = 0x0;

    CsrTime sdioCmd53ReadLMin = 0xFFFFFFFF;
    CsrTime sdioCmd53ReadLMax = 0x0;
    CsrTime sdioCmd53ReadLTotal = 0x0;
    CsrTime sdioCmd53ReadLAvg = 0x0;

    CsrTime sdioCmd53WriteGMin = 0xFFFFFFFF;
    CsrTime sdioCmd53WriteGMax = 0x0;
    CsrTime sdioCmd53WriteGTotal = 0x0;
    CsrTime sdioCmd53WriteGAvg = 0x0;

    CsrTime sdioCmd53ReadGMin = 0xFFFFFFFF;
    CsrTime sdioCmd53ReadGMax = 0x0;
    CsrTime sdioCmd53ReadGTotal = 0x0;
    CsrTime sdioCmd53ReadGAvg = 0x0;

    CsrTime sdioMtuWriteMin = 0xFFFFFFFF;
    CsrTime sdioMtuWriteMax = 0x0;
    CsrTime sdioMtuWriteTotal = 0x0;
    CsrTime sdioMtuWriteAvg = 0x0;

    CsrTime sdioMtuReadMin = 0xFFFFFFFF;
    CsrTime sdioMtuReadMax = 0x0;
    CsrTime sdioMtuReadTotal = 0x0;
    CsrTime sdioMtuReadAvg = 0x0;

    CsrTime sdioSeqMin = 0xFFFFFFFF;
    CsrTime sdioSeqMax = 0x0;
    CsrTime sdioSeqTotal = 0x0;
    CsrTime sdioSeqAvg = 0x0;

#ifdef CSR_WIFI_SDIO_USE_QUEUE
    CsrTime sdioSeqChainingMin = 0xFFFFFFFF;
    CsrTime sdioSeqChainingMax = 0x0;
    CsrTime sdioSeqChainingTotal = 0x0;
    CsrTime sdioSeqChainingAvg = 0x0;
#endif

    sdioResultsCmd52Write  = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd52Read   = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53Write  = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53Read   = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53WriteL = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53ReadL  = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53WriteG = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsCmd53ReadG  = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsMtuWrite    = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsMtuRead     = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsSeq         = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);
    sdioResultsSeqChaining = (SdioResults *) CsrPmemZalloc(sizeof(SdioResults) * NUMBER_OF_ITERATIONS);

    PRINT(card->ospriv, "##############################################################################################\n");
    PRINT(card->ospriv, "###########                          SDIO Evaluation Test                          ###########\n");
    PRINT(card->ospriv, "##############################################################################################\n");
    PRINT(card->ospriv, "Number of runs for each test: %u times\n", NUMBER_OF_ITERATIONS);
    PRINT(card->ospriv, "Block size: %u bytes\n", blockSize);
    PRINT(card->ospriv, "\n");

    CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_MAX_HZ);

    do
    {
        /* CMD52 write */
        if ((r = writeCmd52(card, &sdioResultsCmd52Write[count])) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "writeCmd52 failed:%d - count:%d\n", r, count);
            goto free_data;
        }

        /* CMD52 read */
        if ((r = readCmd52(card, &sdioResultsCmd52Read[count])) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "readCmd52 failed:%d - count:%d\n", r, count);
            goto free_data;
        }

        /* CMD53 write with data size = block size - 1 */
        sdioResultsCmd53WriteL[count].size = blockSize - 1;
        if ((r = writeCmd53(card, &sdioResultsCmd53WriteL[count], sdioResultsCmd53WriteL[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "writeCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53WriteL[count].size);
            goto free_data;
        }

        /* CMD53 read with data size = block size - 1 */
        sdioResultsCmd53ReadL[count].size = blockSize - 1;
        if ((r = readCmd53(card, &sdioResultsCmd53ReadL[count], sdioResultsCmd53ReadL[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "readCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53ReadL[count].size);
            goto free_data;
        }

        /* CMD53 write with data size = block size */
        sdioResultsCmd53Write[count].size = blockSize;
        if ((r = writeCmd53(card, &sdioResultsCmd53Write[count], sdioResultsCmd53Write[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "writeCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53Write[count].size);
            goto free_data;
        }

        /* CMD53 read with data size = block size */
        sdioResultsCmd53Read[count].size = blockSize;
        if ((r = readCmd53(card, &sdioResultsCmd53Read[count], sdioResultsCmd53Read[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "readCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53Read[count].size);
            goto free_data;
        }

        if (blockSize <= 512)
        {
            /* CMD53 write with data size = block size + 1 */
            sdioResultsCmd53WriteG[count].size = blockSize + 1;
            if ((r = writeCmd53(card, &sdioResultsCmd53WriteG[count], sdioResultsCmd53WriteG[count].size)) != CSR_RESULT_SUCCESS)
            {
                PRINT(card->ospriv, "writeCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53WriteG[count].size);
                goto free_data;
            }

            /* CMD53 read with data size = block size + 1 */
            sdioResultsCmd53ReadG[count].size = blockSize + 1;
            if ((r = readCmd53(card, &sdioResultsCmd53ReadG[count], sdioResultsCmd53ReadG[count].size)) != CSR_RESULT_SUCCESS)
            {
                PRINT(card->ospriv, "readCmd53 failed:%d - count:%d - block size:%u\n", r, count, sdioResultsCmd53ReadG[count].size);
                goto free_data;
            }
        }

        /* CMD53 write with data size = MTU */
        sdioResultsMtuWrite[count].size = CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize);
        if ((r = writeCmd53(card, &sdioResultsMtuWrite[count], sdioResultsMtuWrite[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "writeCmd53 failed:%d - count:%d - size:%u\n", r, count, sdioResultsMtuWrite[count].size);
            goto free_data;
        }

        /* CMD53 read with data size = MTU */
        sdioResultsMtuRead[count].size = CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize);
        if ((r = readCmd53(card, &sdioResultsMtuRead[count], sdioResultsMtuRead[count].size)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "readCmd53 failed:%d - count:%d - size:%u\n", r, count, sdioResultsMtuRead[count].size);
            goto free_data;
        }

        /* Sequence work flow */
        sdioResultsSeq[count].size = blockSize;
        if ((r = sequenceWorkFlow(card, &sdioResultsSeq[count], sdioResultsSeq[count].size, FALSE)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "sequenceWorkFlow failed:%d - count:%d - size:%u\n", r, count, sdioResultsSeq[count].size);
            goto free_data;
        }

#ifdef CSR_WIFI_SDIO_USE_QUEUE
        /* Sequence work flow with chaining */
        sdioResultsSeqChaining[count].size = blockSize;
        if ((r = sequenceWorkFlow(card, &sdioResultsSeqChaining[count], sdioResultsSeqChaining[count].size, TRUE)) != CSR_RESULT_SUCCESS)
        {
            PRINT(card->ospriv, "sequenceWorkFlow with chaining failed:%d - count:%d - size:%u\n", r, count, sdioResultsSeqChaining[count].size);
            goto free_data;
        }
#endif

        count++;
    } while (count < NUMBER_OF_ITERATIONS);

    count = 0;
    do
    {
        calculateMinMaxTotal(&sdioResultsCmd52Write[count], &sdioCmd52WriteMin, &sdioCmd52WriteMax, &sdioCmd52WriteTotal);
        calculateMinMaxTotal(&sdioResultsCmd52Read[count], &sdioCmd52ReadMin, &sdioCmd52ReadMax, &sdioCmd52ReadTotal);

        calculateMinMaxTotal(&sdioResultsCmd53WriteL[count], &sdioCmd53WriteLMin, &sdioCmd53WriteLMax, &sdioCmd53WriteLTotal);
        calculateMinMaxTotal(&sdioResultsCmd53ReadL[count], &sdioCmd53ReadLMin, &sdioCmd53ReadLMax, &sdioCmd53ReadLTotal);
        calculateMinMaxTotal(&sdioResultsCmd53Write[count], &sdioCmd53WriteMin, &sdioCmd53WriteMax, &sdioCmd53WriteTotal);
        calculateMinMaxTotal(&sdioResultsCmd53Read[count], &sdioCmd53ReadMin, &sdioCmd53ReadMax, &sdioCmd53ReadTotal);

        if (blockSize <= 512)
        {
            calculateMinMaxTotal(&sdioResultsCmd53WriteG[count], &sdioCmd53WriteGMin, &sdioCmd53WriteGMax, &sdioCmd53WriteGTotal);
            calculateMinMaxTotal(&sdioResultsCmd53ReadG[count], &sdioCmd53ReadGMin, &sdioCmd53ReadGMax, &sdioCmd53ReadGTotal);
        }

        calculateMinMaxTotal(&sdioResultsMtuWrite[count], &sdioMtuWriteMin, &sdioMtuWriteMax, &sdioMtuWriteTotal);
        calculateMinMaxTotal(&sdioResultsMtuRead[count], &sdioMtuReadMin, &sdioMtuReadMax, &sdioMtuReadTotal);

        calculateMinMaxTotal(&sdioResultsSeq[count], &sdioSeqMin, &sdioSeqMax, &sdioSeqTotal);

#ifdef CSR_WIFI_SDIO_USE_QUEUE
        calculateMinMaxTotal(&sdioResultsSeqChaining[count], &sdioSeqChainingMin, &sdioSeqChainingMax, &sdioSeqChainingTotal);
#endif
        count++;
    } while (count < NUMBER_OF_ITERATIONS);

    sdioCmd52WriteAvg  = sdioCmd52WriteTotal / NUMBER_OF_ITERATIONS;
    sdioCmd52ReadAvg   = sdioCmd52ReadTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53WriteLAvg = sdioCmd53WriteLTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53ReadLAvg  = sdioCmd53ReadLTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53WriteAvg  = sdioCmd53WriteTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53ReadAvg   = sdioCmd53ReadTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53WriteGAvg = sdioCmd53WriteGTotal / NUMBER_OF_ITERATIONS;
    sdioCmd53ReadGAvg  = sdioCmd53ReadGTotal / NUMBER_OF_ITERATIONS;
    sdioMtuWriteAvg    = sdioMtuWriteTotal / NUMBER_OF_ITERATIONS;
    sdioMtuReadAvg     = sdioMtuReadTotal / NUMBER_OF_ITERATIONS;
    sdioSeqAvg         = sdioSeqTotal / NUMBER_OF_ITERATIONS;
#ifdef CSR_WIFI_SDIO_USE_QUEUE
    sdioSeqChainingAvg = sdioSeqChainingTotal / NUMBER_OF_ITERATIONS;
#endif

    PRINT(card->ospriv, "##### CMD52 #####\n");
    PRINT_SCALE(card,
                TIME_SCALE_1 + (SDIO_CMD_IN_NANOSECONDS + 500) / MICROSECONDS_IN_NANOSECONDS,
                TIME_SCALE_2 + (SDIO_CMD_IN_NANOSECONDS + 500) / MICROSECONDS_IN_NANOSECONDS,
                TIME_SCALE_3 + (SDIO_CMD_IN_NANOSECONDS + 500) / MICROSECONDS_IN_NANOSECONDS);
    PRINT_RESULT_CMD52(card, "CMD52 write:        ", sdioCmd52WriteMin, sdioCmd52WriteMax, sdioCmd52WriteAvg, time2ScaleText(sdioCmd52WriteAvg, SDIO_CMD52_IN_MICROSECONDS, 1));
    PRINT_RESULT_CMD52(card, "CMD52 read:         ", sdioCmd52ReadMin, sdioCmd52ReadMax, sdioCmd52ReadAvg, time2ScaleText(sdioCmd52ReadAvg, SDIO_CMD52_IN_MICROSECONDS, 1));

    PRINT(card->ospriv, "\n");

    PRINT(card->ospriv, "##### CMD53 #####\n");
    cmdTime = SDIO_CMD53_WRITE_IN_MICROSECONDS(sdioResultsCmd53Write[0].size, blockSize);
    PRINT_SCALE(card, TIME_SCALE_1 + cmdTime, TIME_SCALE_2 + cmdTime, TIME_SCALE_3 + cmdTime);
    PRINT_RESULT(card, "CMD53 write:        ", sdioResultsCmd53WriteL[0].size, sdioCmd53WriteLMin, sdioCmd53WriteLMax, sdioCmd53WriteLAvg, time2ScaleText(sdioCmd53WriteLAvg, cmdTime, 1));
    PRINT_RESULT(card, "CMD53 write:        ", sdioResultsCmd53Write[0].size, sdioCmd53WriteMin, sdioCmd53WriteMax, sdioCmd53WriteAvg, time2ScaleText(sdioCmd53WriteAvg, cmdTime, 1));
    if (blockSize <= 512)
    {
        PRINT_RESULT(card, "CMD53 write:        ", sdioResultsCmd53WriteG[0].size, sdioCmd53WriteGMin, sdioCmd53WriteGMax, sdioCmd53WriteGAvg, time2ScaleText(sdioCmd53WriteGAvg, cmdTime, 1));
    }

    PRINT(card->ospriv, "\n");

    cmdTime = SDIO_CMD53_READ_IN_MICROSECONDS(sdioResultsCmd53Read[0].size, blockSize);
    PRINT_SCALE(card, TIME_SCALE_1 + cmdTime, TIME_SCALE_2 + cmdTime, TIME_SCALE_3 + cmdTime);
    PRINT_RESULT(card, "CMD53 read:         ", sdioResultsCmd53ReadL[0].size, sdioCmd53ReadLMin, sdioCmd53ReadLMax, sdioCmd53ReadLAvg, time2ScaleText(sdioCmd53ReadLAvg, cmdTime, 1));
    PRINT_RESULT(card, "CMD53 read:         ", sdioResultsCmd53Read[0].size, sdioCmd53ReadMin, sdioCmd53ReadMax, sdioCmd53ReadAvg, time2ScaleText(sdioCmd53ReadAvg, cmdTime, 1));
    if (blockSize <= 512)
    {
        PRINT_RESULT(card, "CMD53 read:         ", sdioResultsCmd53ReadG[0].size, sdioCmd53ReadGMin, sdioCmd53ReadGMax, sdioCmd53ReadGAvg, time2ScaleText(sdioCmd53ReadGAvg, cmdTime, 1));
    }

    PRINT(card->ospriv, "\n");

    cmdTime = SDIO_CMD53_WRITE_IN_MICROSECONDS(sdioResultsMtuWrite[0].size, blockSize);
    PRINT_SCALE(card, TIME_SCALE_1 + cmdTime, TIME_SCALE_2 + cmdTime, TIME_SCALE_3 + cmdTime);
    PRINT_RESULT(card, "CMD53 write:        ", sdioResultsMtuWrite[0].size, sdioMtuWriteMin, sdioMtuWriteMax, sdioMtuWriteAvg, time2ScaleText(sdioMtuWriteAvg, cmdTime, 1));

    PRINT(card->ospriv, "\n");

    PRINT_SCALE(card, TIME_SCALE_1 + cmdTime, TIME_SCALE_2 + cmdTime, TIME_SCALE_3 + cmdTime);
    cmdTime = SDIO_CMD53_READ_IN_MICROSECONDS(sdioResultsMtuRead[0].size, blockSize);
    PRINT_RESULT(card, "CMD53 read:         ", sdioResultsMtuRead[0].size, sdioMtuReadMin, sdioMtuReadMax, sdioMtuReadAvg, time2ScaleText(sdioMtuReadAvg, cmdTime, 1));

    PRINT(card->ospriv, "\n");

    PRINT(card->ospriv, "#### Sequence ####\n");
    numberOfOperations = 18;
    cmd52Time = (SDIO_CMD_IN_NANOSECONDS * 6 + 500) / MICROSECONDS_IN_NANOSECONDS;
    cmd53Time = (SDIO_CMD53_WRITE_IN_NANOSECONDS(CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize), blockSize) * 10 +
                 SDIO_CMD53_READ_IN_NANOSECONDS(CALCULATE_DATA_SIZE(PACKET_LENGTH, blockSize), blockSize) * 2 + 500) / MICROSECONDS_IN_NANOSECONDS;
    cmdTime = cmd52Time + cmd53Time;
    PRINT_SCALE(card,
                TIME_SCALE_1 * numberOfOperations + cmdTime,
                TIME_SCALE_2 * numberOfOperations + cmdTime,
                TIME_SCALE_3 * numberOfOperations + cmdTime);

#ifdef CSR_WIFI_SDIO_USE_QUEUE
    PRINT_RESULT(card, "Sequence:           ", sdioResultsSeq[0].size, sdioSeqMin, sdioSeqMax, sdioSeqAvg, time2ScaleText(sdioSeqAvg, cmdTime, numberOfOperations));
    PRINT_RESULT(card, "Sequence (chaining):", sdioResultsSeqChaining[0].size, sdioSeqChainingMin, sdioSeqChainingMax, sdioSeqChainingAvg, time2ScaleText(sdioSeqChainingAvg, cmdTime, numberOfOperations));
#else
    PRINT_RESULT(card, "Sequence:           ", sdioResultsSeq[0].size, sdioSeqMin, sdioSeqMax, sdioSeqAvg, time2ScaleText(sdioSeqAvg, cmdTime, numberOfOperations));
#endif

    PRINT(card->ospriv, "\n");
    PRINT(card->ospriv, "Where Sequence: 4xCMD53 write with %u bytes each\n", CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize));
    PRINT(card->ospriv, "                2xCMD52 write\n");
    PRINT(card->ospriv, "                2xCMD53 read  with %u bytes each\n", CALCULATE_DATA_SIZE(PACKET_LENGTH, blockSize));
    PRINT(card->ospriv, "                4xCMD53 write with %u bytes each\n", CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize));
    PRINT(card->ospriv, "                2xCMD52 write\n");
    PRINT(card->ospriv, "                2xCMD53 write with %u bytes each\n", CALCULATE_DATA_SIZE(DATA_PACKET_LENGTH, blockSize));
    PRINT(card->ospriv, "                2xCMD52 write\n");

free_data:
    CsrPmemFree(sdioResultsCmd52Write);
    CsrPmemFree(sdioResultsCmd52Read);
    CsrPmemFree(sdioResultsCmd53Write);
    CsrPmemFree(sdioResultsCmd53Read);
    CsrPmemFree(sdioResultsCmd53WriteL);
    CsrPmemFree(sdioResultsCmd53ReadL);
    CsrPmemFree(sdioResultsCmd53WriteG);
    CsrPmemFree(sdioResultsCmd53ReadG);

    CsrPmemFree(sdioResultsMtuWrite);
    CsrPmemFree(sdioResultsMtuRead);

    CsrPmemFree(sdioResultsSeq);
    CsrPmemFree(sdioResultsSeqChaining);

    PRINT(card->ospriv, "##############################################################################################\n");
}


void unifi_sdio_evaluation_test(card_t *card)
{
    sdio_evaluation_test(card);
}


#endif /* CSR_WIFI_SDIO_EVALUATION_TEST */
