CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif


app.exe : main.o libarr.a
	$(CC) $(CFLAGS) main.c -L. -larr -o app.exe
test.exe : tests.o libarr.a
	$(CC) $(CFLAGS) tests.c -L. -larr -o test.exe
test_speed.exe : test_speed.o libarr.a
	$(CC) $(CFLAGS) test_speed.c -L. -larr -o test_speed.exe

libarr.a: functions.o io.o binary_sort.o
	ar rc libarr.a functions.o io.o binary_sort.o
	ranlib libarr.a
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe