URCUDIR ?= /usr/local

CC := gcc
LD := gcc

CFLAGS += -I$(URCUDIR)/include
CFLAGS += -D_REENTRANT
CFLAGS += -Wall -Winline
#CFLAGS += --param inline-unit-growth=1000
CFLAGS += -mrtm

ifdef DEBUG
	CFLAGS += -O0 -g3
else
	CFLAGS += -DNDEBUG
	CFLAGS += -O3
endif

IS_HAZARD_PTRS_HARRIS = -DIS_HAZARD_PTRS_HARRIS
IS_HARRIS = -DIS_HARRIS
IS_RCU = -DIS_RCU
IS_RLU = -DIS_RLU
IS_RCU_ARRAY = -DIS_RCU_ARRAY

LDFLAGS += -L$(URCUDIR)/lib
LDFLAGS += -lpthread

BINS = bench-rcu bench-rlu bench-arcu

.PHONY:	all clean

all: $(BINS)

rlu.o: rlu.c rlu.h
	$(CC) $(CFLAGS) $(DEFINES) -c -o $@ $<

new-urcu.o: new-urcu.c
	$(CC) $(CFLAGS) $(DEFINES) -c -o $@ $<

hazard_ptrs.o: hazard_ptrs.c
	$(CC) $(CFLAGS) $(DEFINES) -c -o $@ $<

hash-list.o: hash-list.c
	$(CC) $(CFLAGS) $(DEFINES) -c -o $@ $<

bench-rcu.o: bench.c
	$(CC) $(CFLAGS) $(IS_RCU) $(DEFINES) -c -o $@ $<

bench-rlu.o: bench.c
	$(CC) $(CFLAGS) $(IS_RLU) $(DEFINES) -c -o $@ $<

bench-arcu.o: bench.c
	$(CC) $(CFLAGS) $(IS_RCU_ARRAY) $(DEFINES) -c -o $@ $<

bench-rcu: new-urcu.o hazard_ptrs.o rlu.o hash-list.o bench-rcu.o
	$(LD) -o $@ $^ $(LDFLAGS)

bench-arcu: new-urcu.o hazard_ptrs.o rlu.o hash-list.o bench-arcu.o
	$(LD) -o $@ $^ $(LDFLAGS)

bench-rlu: new-urcu.o hazard_ptrs.o rlu.o hash-list.o bench-rlu.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(BINS) *.o
