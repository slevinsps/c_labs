CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb
CFLAGS2 := -std=c99 -Wall -Werror -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe : main.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS) $^ -o $@
tests.exe : tests.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS) $^ -o $@
test_speed.exe : test_speed.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS2) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS2) -c $<
clean :
	RM *.o *.exe