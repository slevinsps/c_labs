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

int strcat1(char **s1, char *s2, int n_new, size_t *n)
{
	int len2 = strlen1(s2);
	if (n_new > *n)
	{
		*s1 = realloc(*s1,n_new + len2+1);
		if (!*s1)
			return MEMORY_ERROR;
		*n = n_new;
	}
	for (int i = n_new - len2; i < n_new; i++)
	{
		(*s1)[i] = s2[i - n_new + len2];
	}		
	return OK;
}

