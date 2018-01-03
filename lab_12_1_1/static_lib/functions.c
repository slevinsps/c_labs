#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "defines.h"
#include "functions.h"
    
int count_numbers(FILE *f)
{
    int k = 0;
    int n;
    while (fscanf(f, "%d", &n) == 1)
    {
        k++;
    }
    return k;
}    
    
int key(const int *pb, const int *pe, int **new_begin, int **new_end)
{
    const int *k;  
    const int *min = pb; 
    const int *max = pb;
    int err = OK;
    if (pe == pb)
    {
        err = FILE_EMPTY;
    }
    else
    {
        while (pe > pb)
        {
            if (*pb > *max)
            {
                max = pb;    
            }
            if (*pb < *min)
            {
                min = pb;
            }
            pb = pb + 1;
        }
        if (min > max)
        {
            k = min;
            min = max;
            max = k;
        }    
        min = min + 1;
        if (min >= max)
        {
            err = ARRAY_EMPTY;
        }
        else
        {
            
            if (*new_begin != NULL)
            {    
                *new_end = *new_begin;
                while (min < max)
                {
                    **new_end = *min;
                    min = min + 1;
                    *new_end = *new_end + 1;
                } 
            }
            else
            {
                err = MEMORY_ERROR;
            }            
        }
    }
    return err;
}
