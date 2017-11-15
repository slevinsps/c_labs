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
	char *tmp;
    if (n_new > *n)
    {
        *n = n_new;
        tmp = realloc(*s1,*n+1);
		if (!tmp)
			return MEMORY_ERROR;
		*s1 = tmp;
    }
    (*s1)[n_new] = c;    
    return OK;
}

