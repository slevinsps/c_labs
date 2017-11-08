#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"

int strlen1(const char *string)
{
    int k = 0;
    if (string)
    {    
        while (string[k] != 0)
            k++;
    }
    return k;
}

int strcat1(char **s1, char c, int n_new, size_t *n)
{
    if (n_new > *n)
    {
        *n = n_new;
        *s1 = realloc(*s1,*n+1);
        if (!*s1)
            return MEMORY_ERROR;
    }
    (*s1)[n_new] = c;    
    return OK;
}

