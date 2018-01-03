CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb


libarr.dll: func.o
	gcc -shared -o libarr.dll func.o
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -D ARR_EXPORTS -c $<
clean :
	RM *.o *.exe