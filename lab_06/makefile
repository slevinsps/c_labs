CC := gcc
CFLAGS := -std=c99 -Wall -Werror

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe : zad1.o read_array.o sum_proizved.o
	$(CC) $(CFLAGS) $^ -o $@
tests.exe: tests.o sum_proizved.o
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
