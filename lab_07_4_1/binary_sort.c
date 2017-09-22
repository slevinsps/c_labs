#include <stdlib.h>
#include <assert.h>
#include "defines.h"
    
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
    assert(first<right);
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
    while(right < first+number*size)
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