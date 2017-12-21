CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

app.exe : main.o my_snprintf.o
	$(CC) $(CFLAGS) $^ -o $@
test.exe : test.o my_snprintf.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
