#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "defines.h"
#include "functions.h"
    
int count_numbers(FILE *f)
{
    int k = 0;
    int n;
    while (fscanf(f,"%d",&n) == 1)
    {
        k++;
    }
    
    return k;
}    

int key(const int *pb,const int *pe,int **ppb, int **ppe)
{
    const int *k;  
    const int *min = pb; 
    const int *max = pb;
    assert(pe > pb);
    while(pe > pb)
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
    while (*ppb < min+1)
    {
        *ppb += 1;
    }
    while (*ppe < max)
    {
        *ppe += 1;
    }
    return 0;
}


int rewrite_array(int *min,int *max,int **new_begin, int **new_end)
{
    int err = OK;
    *new_end = *new_begin;
    if (min == max)
    {
        err = ARRAY_EMPTY;
    }
    else
    {
        while(min < max)
        {
            
            **new_end = *min;
            min = min + 1;
            *new_end = *new_end + 1;
        }     
    }
    return err;
}


