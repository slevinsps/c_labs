#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "defines.h"
#include "binary_sort.h"

ARR_DLL void ARR_DECL swap(void *a, void *b, size_t size)                                                                                                                     
{                                                     
    char *a1 = a, *b1 = b;
    char tmp;
    for (int i = 1;i <= size;i++)
    {
        tmp = *a1;
        *a1 = *b1;
        *b1 = tmp;
        a1++;
        b1++;                
    }
}
            
ARR_DLL void* ARR_DECL binary_search(void *first, void *right, size_t size, comparator compare)
{
    assert(first < right);
    char *l, *r, *m;
    l = first;
    r = (char*)right - size;
    while (l <= r)
    {
        m = l + ((r - l) / 2);   
        while ((m - (char*)first) % size != 0)
        {
            m = m - 1;
        }
        if (compare(m, ((char*)right)) > 0)
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

ARR_DLL void ARR_DECL mysort(void *first, size_t number, size_t size, comparator compare)
{
    char *l, *right2;
    char *right = (char*)first + size;
    while (right < (char*)first + number * size)
    {
        right2 = right - size;
        l = binary_search(first, right, size, compare);
        
        while (l <= right2)
        {
            swap((right2 + size), (right2), size);
            right2 = right2 - size;
        }
        
        right = right + size;
    }
}