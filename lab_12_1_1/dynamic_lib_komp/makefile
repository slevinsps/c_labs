CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif


app.exe : main.o libarr.dll
	gcc -o app.exe  main.o -L. -larr -Wl,-rpath,. 
test.exe : tests.o libarr.dll
	$(CC) $(CFLAGS) tests.c -L. -larr -o test.exe
test_speed.exe : test_speed.o libarr.dll
	$(CC) $(CFLAGS) test_speed.c -L. -larr -o test_speed.exe

libarr.dll: functions.o io.o binary_sort.o
	gcc -shared -o libarr.dll functions.o io.o binary_sort.o
	
main.o : main.c
	$(CC) $(CFLAGS) -c $<
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -D ARR_EXPORTS -c $<
clean :
	RM *.o *.exe