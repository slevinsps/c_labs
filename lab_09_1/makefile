CC := gcc
CFLAGS := -std=gnu99 -Wall -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : main.o func.o
	$(CC) $(CFLAGS) $^ -o $@

test.exe : test.o func.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
