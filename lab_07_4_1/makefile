CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : main.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS) $^ -o $@
test.exe : tests.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS) $^ -o $@
test_speed.exe : test_speed.o functions.o io.o binary_sort.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe