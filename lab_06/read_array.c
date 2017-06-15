#include <stdio.h>
#include "read_array.h"
#include "defines.h"

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
        *pe = *pe - 1;
        err = NUMBER_ITEMS_EXCEEDED;
    }
    return err;        
}
    