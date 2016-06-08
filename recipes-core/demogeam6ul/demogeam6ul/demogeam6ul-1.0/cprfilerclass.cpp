#include "cprfilerclass.h"
#include <QProcess>
#include <QDebug>
#include <QFile>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


cPrfilerClass::cPrfilerClass(QObject *parent) : QThread(parent)
{
    running = true;

    // Recover CPU model
    this->recoverCpuInfo();
    this->recoverMemTotal();
}

QString cPrfilerClass::findInfo(const QString &ref, const QString &filename) // Find a string in a file
{
    if (!QFile::exists(filename))
    {
        return "";
    }

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        return "";
    }

    QTextStream in(&file);
    QString info = in.readAll();
    QStringList  fields = info.split("\n");
    QString findLine = "";
    foreach (const QString &field, fields)
    {
        if (field.startsWith(ref))
        {
            findLine = field;

            break;
        }
    }

    file.close();

    return findLine;
}

void cPrfilerClass::recoverCpuInfo()
{
    QString dummy = this->findInfo("Hardware", "/proc/cpuinfo");
    dummy.replace(QString("(Device Tree)"), QString(""));
    dummy.replace(QString("Hardware\t: "), QString(""));
    this->_cpuType = dummy.trimmed();
}

QString cPrfilerClass::getMemFree()
{
    QString dummy = this->findInfo("MemFree:", "/proc/meminfo");
    dummy.replace(QString("MemFree: "), QString(""));
    return dummy.trimmed();
}

void cPrfilerClass::recoverMemTotal()
{
    QString dummy = this->findInfo("MemTotal:", "/proc/meminfo");
    dummy.replace(QString("MemTotal: "), QString(""));
    this->_memTotal = dummy.trimmed();
}

QString cPrfilerClass::cpuPercentage()
{
    QString ret;

    mMutex.lock();

    ret = QString::number(m_percent,'f',1) + " %";

    mMutex.unlock();

    return ret;
}

QString cPrfilerClass::vMEMVAlue()
{
    QString ret;

    mMutex.lock();

    ret = QString::number(m_VM,'f',1) + "KB";

    mMutex.unlock();

    return ret;
}

void cPrfilerClass::run()
{
    double percent;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;
    unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle,lastUsage=0;

    FILE* file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &lastTotalUser, &lastTotalUserLow, &lastTotalSys, &lastTotalIdle);
    fclose(file);

    while(running)
    {
        file = fopen("/proc/stat", "r");
        fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow, &totalSys, &totalIdle);
        fclose(file);

        if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
                totalSys < lastTotalSys || totalIdle < lastTotalIdle){
            //Overflow detection. Just skip this value.
            percent = -1.0;
        }
        else
        {
            total = (totalUser - lastTotalUser) +
                    (totalUserLow - lastTotalUserLow) +
                    (totalSys - lastTotalSys);

            percent = total;
            if(total==0)
            {
                percent=lastUsage;
            }
            else
            {
                total += (totalIdle - lastTotalIdle);
                percent /= total;
                percent *= 100;
            }
        }


        lastTotalUser = totalUser;
        lastTotalUserLow = totalUserLow;
        lastTotalSys = totalSys;
        lastTotalIdle = totalIdle;
        lastUsage=percent;
        int vmm=getVMValue();

        mMutex.lock();

        m_percent = percent;
        m_VM = vmm;

        mMutex.unlock();

        QThread::msleep(500);
    }
}

int cPrfilerClass::parseLine(char* line){
     int i = strlen(line);
     while (*line < '0' || *line > '9') line++;
     line[i-3] = '\0';
     i = atoi(line);
     return i;
 }


int cPrfilerClass::getVMValue()
{ //Note: this value is in KB!
      FILE* file = fopen("/proc/self/status", "r");
      int result = -1;
      char line[128];


      while (fgets(line, 128, file) != NULL){
          if (strncmp(line, "VmRSS:", 6) == 0){
              result = parseLine(line);
              break;
          }
      }
      fclose(file);
      return result;
  }

