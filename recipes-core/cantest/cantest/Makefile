CFLAGS=-I.
LDFLAGS=
LDLIBS=

EXEC = cantest
OBJS = cansend.o lib.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

romfs:
	$(ROMFSINST) -e CONFIG_USER_CAN_TEST /usr/bin/cantest

clean:
	-rm -f $(EXEC) *.elf *.gdb *.o

