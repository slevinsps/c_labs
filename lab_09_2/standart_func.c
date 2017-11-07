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
		*n = n_new*2;
		*s1 = realloc(*s1,*n);
		if (!*s1)
			return MEMORY_ERROR;
	}
	for (int i = n_new - len2; i < n_new; i++)
	{
		(*s1)[i] = s2[i - n_new + len2];
	}		
	return OK;
}

