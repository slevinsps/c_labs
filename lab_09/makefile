CC := gcc
CFLAGS := -std=c99 -Wall -Werror

ifeq ($(mode), debug)
	CFLAGS += -g3
endif
    
ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe : main.o str.o sort.o
	$(CC) $(CFLAGS) $^ -o $@
tests.exe: tests.o str.o
	$(CC) $(CFLAGS) $^ -o $@
test_sort.exe: test_sort.o sort.o
	$(CC) $(CFLAGS) $^ -o $@ 
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
clean :
	RM *.o *.exe
