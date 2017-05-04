CC=g++
#CXX=g++
EXEC=bcm2835
RM=rm -f
CPPFLAGS=-Wall -pthread -std=gnu++11
LDFLAGS=-g -L.
LDLINK=-c
LDLIBS=-lm -lstdc++ -lbcm2835 

#-lbcm_lib

# CPPFLAGS=-g -pthread -Wall -I$(DIR)
# LDLIBS=-lm -lbcm2835 -lstdc++
# LDFLAGS=-g

SRCSC=bcm_lib.c
SRCSCC=main.cpp pin.cpp gpio.cpp
OBJS=$(subst .c,.o,$(SRCSC)) $(subst .cpp,.o,$(SRCSCC)) 

	

all: pin gpio bcm_lib bcm2835
	
# pin: pin.o

gpio: gpio.cpp gpio.h
	@echo "compiling gpio.o"
	$(CC) $(CPPFLAGS) $(LDLINK) gpio.cpp -o gpio.o
	
pin: pin.cpp pin.h
	@echo "compiling pin.o"
	$(CC) $(CPPFLAGS) $(LDLINK) pin.cpp -o pin.o
	
# bcm_lib: bcm_lib.o
	
bcm_lib: bcm_lib.c bcm_lib.h
	@echo "compilin bcm_lib -> objs=" $(OBJS)
	$(CC) $(CPPFLAGS) $(LDLINK) bcm_lib.c -o bcm_lib.o 
# $(LDLIBS)

$(EXEC): $(OBJS)
	@echo "compiling bcm"
	$(CC) $(LDLIBS) $(LDFLAGS) -o bcm2835  $(OBJS)

depend: .depend

.depend: $(SRCSC) $(SRCSCC)
	$(RM) ./.depend
	$(CC) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	@echo "clean" $(OBJS)
	$(RM) $(OBJS) $(EXEC)

distclean: clean
	$(RM) *~ .depend

include .depend
