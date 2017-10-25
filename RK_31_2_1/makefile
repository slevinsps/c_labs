CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

main.exe : main.o io.o func.o free_all.o
	$(CC) $(CFLAGS) $^ -o $@

test.exe : test.o io.o func.o free_all.o
	$(CC) $(CFLAGS) $^ -o $@	
	
%.o : %.c %.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	RM *.o *.exe