#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "io.h"
    
int read_array(FILE *f, int *pb, int **pe, int k)
{
    int err = OK;
    while ((fscanf(f, "%d", *pe) == 1) && (*pe - pb < k))
    {
        *pe = *pe + 1;  
    }  
    if (*pe == pb)
    {
        err = FILE_EMPTY;
    }
    return err;        
}
    
void print_array(const int *pb, const int *pe, FILE *f)
{
    while (pe > pb)
    {
        fprintf(f, "%d ", *pb);
        pb = pb + 1;
    }
}