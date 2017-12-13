CC := gcc
CFLAGS := -std=c99 -Wall -Werror

app.exe : main.o func.o
	$(CC) $(CFLAGS) $^ -o $@
	
test.exe : test.o func.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	RM *.o *.exe