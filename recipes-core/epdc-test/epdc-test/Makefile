CC ?=$(CROSS_COMPILE)gcc
CFLAGS ?= -O2 -Wall -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common  

INCLUDES +=  

LFLAGS +=  

SOURCES=mxc_epdc_v2_fb_test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mxc_epdc_fb_test

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS)  $(CFLAGS)-o $@ $(LDFLAGS) $(LIBS) 

.c:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ 

clean:
	$(RM) *.o *~ $(EXECUTABLE)
