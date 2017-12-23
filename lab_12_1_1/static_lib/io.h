#ifndef IO
#define IO
#include <stdio.h>

int read_array(FILE *f, int *pb, int **pe, int k);
void print_array(const int *pb, const int *pe, FILE *f);

#endif // IO