#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

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
    
int read_array(FILE *f, int **pb, int **pe, int k)
{
    int err = OK;
    while((fscanf(f,"%d",*pe) == 1) && (*pe-*pb < k))
    {
        *pe = *pe + 1;  
    }
    
    if (*pe == *pb)
    {
        err = FILE_EMPTY;
    }
    return err;        
}
  

void print_array(const int* pb,const int* pe,FILE *f)
{
    while (pe>=pb)
    {
        fprintf(f,"%d ",*pb);
        pb = pb +1;
    }
}
    
void swap(void *a, void *b,size_t size)                                                                                                                     
{                                                     
    char *a1 = a, *b1 = b;
    char tmp;
    for (int i=1;i<=size;i++)
    {
        tmp = *a1;
        *a1 = *b1;
        *b1 = tmp;
        a1++;
        b1++;                
    }
}
void binary_search(void *first,int i, size_t size)
{
	char *l,*r,*m;
	l = (char*)first;
    r = (char*)first+(i-1)*size;
    while (l<=r)
    {
        m = l+((r-l)/2);
        if (compare((char*)m,((char*)first+i*size))>0)
            r = m - 1;
        else
            l = m + 1;
    }
	return *l;
}
void binary_insert(void * first, size_t number, size_t size,int (*compare)(const void*, const void*))
{
    int l;
    for (int i = 1; i<number; i++)
    {
        l = binary_search(first,i,size);
        for (int j = i-1; j>=l; j--)
        {
            swap(((char*)first + (j+1)*size), ((char*)first + j*size), size);
        }
    }
}

 
void search_min_max(int *pb, int const *const pe, int **ppb, int *n)
{
    int *k;  
    int *min = pb; 
    int *max = pb;
    *n = 0;
    while(pe>pb)
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
    *n = max-min-1;
    *ppb = min + 1;
}


int rewrite_array(int *min,int n,int **new_begin)
{
    int err = OK;
    int *new_end = *new_begin;
     for(int i=1;i<=n;i++)
    {
        
        *new_end = *min;
        min = min + 1;
        new_end = new_end + 1;
    }    
    if (new_end == *new_begin)
    {
        err = ARRAY_EMPTY;
    }
    return err;
}


