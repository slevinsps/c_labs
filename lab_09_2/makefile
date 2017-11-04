CC := gcc
CFLAGS := -std=c99 -Wall -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : main.o find_replace.o standart_func.o
	$(CC) $(CFLAGS) $^ -o $@

test.exe : main.o find_replace.o standart_func.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
