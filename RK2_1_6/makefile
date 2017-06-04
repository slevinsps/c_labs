CC := gcc
CFLAGS :=  -std=c99 -Wall -Werror -O0 -fprofile-arcs -ftest-coverage
main.exe : main.o read_array.o print_array.o replace.o
	$(CC) $(CFLAGS) $^ -o $@ 
%.o: %.c
	$(CC) $(CFLAGS) -c $<
gcov: main.c read_array.c print_array.c replace.c
	gcov main.c read_array.c print_array.c replace.c
clean:
	rm *.o *.exe *.gcno *.gcda *.gch *.gcov