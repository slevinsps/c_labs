CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : main.o io.o create_free_matrix.o gauss.o multiply_matrix.o sum_matrix.o
	$(CC) $(CFLAGS) $^ -o $@
test.exe : tests.o io.o create_free_matrix.o gauss.o multiply_matrix.o sum_matrix.o
	$(CC) $(CFLAGS) $^ -o $@
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
