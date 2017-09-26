#include <stdlib.h>
#include <assert.h>
#include "defines.h"
#include "binary_sort.h"

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
        
void* binary_search(void *first,void *right, size_t size,comparator compare)
{
    assert(first<right);
    void *l,*r,*m;
    l = first;
    r = (char*)right-size;
    while (l<=r)
    {
        m = (char*)l+(((char*)r-(char*)l)/(2));   
        while (((char*)m-(char*)first)%size !=0)
        {
            m = (char*)m - 1;
        }
        if (compare((char*)m,((char*)right))>0)
        {
            r = (char*)m - size;
        }
        else
        {
            l = (char*)m + size;
        }   
    }
    return l;
}

void mysort(void * first, size_t number, size_t size, comparator compare)
{
    void *l, *right2;
    void *right = (char*)first+size;
    while((char*)right < (char*)first+number*size)
    {
        right2 = (char*)right-size;
        l = binary_search(first,right,size,compare);
        
        while (l<=right2)
        {
            
            swap(((char*)right2 + size), ((char*)right2), size);
            right2= (char*)right2 - size;
        }
        
        right = (char*)right + size;
    }
}