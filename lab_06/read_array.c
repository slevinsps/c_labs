#include <stdio.h>
#include "read_array.h"

#define NUMBER_ITEMS 100 

#define OK 0
#define FILE_EMPTY -2
#define NUMBER_ITEMS_EXCEEDED -4

int read_array(FILE *f, int **pb, int **pe)
{
    int err = OK;
    while((*pe-*pb <= NUMBER_ITEMS) && (fscanf(f,"%d",*pe) == 1))
    {
        *pe = *pe + 1;
    }
    
    if (*pe == *pb)
    {
        err = FILE_EMPTY;
    }
    
    if (*pe-*pb > NUMBER_ITEMS)
    {
        err = NUMBER_ITEMS_EXCEEDED;
    }
    return err;        
}