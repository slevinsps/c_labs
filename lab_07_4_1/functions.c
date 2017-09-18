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
    while (pe>pb)
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
    
void* binary_search(void *first,void *right, size_t size,int (*compare)(const void*, const void*))
{
    void *l,*r,*m;
    l = first;
    r = right-size;
    while (l<=r)
    {
        m = l+((r-l)/(2));   
        while ((m-first)%size !=0)
        {
            m--;
        }
        if (compare((char*)m,((char*)right))>0)
        {
            r = m - size;
        }
        else
        {
            l = m + size;
        }   
    }
    return l;
}
    
void binary_insert(void * first, size_t number, size_t size,int (*compare)(const void*, const void*))
{
    void *l, *right2;
    void *right = first+size;
    for (int i = 1; i<number; i++)
    {
        right2 = right-size;
        l = binary_search(first,right,size,compare);
        
        while (l<=right2)
        {
            
            swap(((char*)right2 + size), ((char*)right2), size);
            right2-=size;
        }
        
        right+=size;
    }
}

void search_min_max(int *pb, int const *const pe, int **ppb, int **ppe)
{
    int *k;  
    int *min = pb; 
    int *max = pb;
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
    *ppb = min + 1;
    *ppe = max;
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


