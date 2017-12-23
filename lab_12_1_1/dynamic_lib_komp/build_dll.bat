gcc -std=c99 -Wall -Werror -D ARR_EXPORTS -c functions.c io.c binary_sort.c  functions.h io.h binary_sort.h

gcc -shared functions.o io.o binary_sort.o  -o arr.dll
