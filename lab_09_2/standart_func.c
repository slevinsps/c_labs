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


int strcat1(char **s1, char *s2)
{
	int len1 = strlen1(*s1);
	int len2 = strlen1(s2);
	// printf("%d    %d\n",len1,len2);
	*s1 = realloc(*s1,len1 + len2);
	if (*s1)
	{
		for (int i = len1; i < len1 + len2; i++)
		{
			//printf("%d\n",i-len1);
			(*s1)[i] = s2[i - len1];
		}
		(*s1)[len1 + len2] = 0;
	}
	else 
		return MEMORY_ERROR;
	
	
	return OK;
}

