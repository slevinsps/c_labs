#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"

int check_affiliation(char ch, const char *string2)
{
	int len = strlen1(string2);
	for (int i = 0; i < len; i++)
	{
		if (ch == string2[i])
			return 1;
	}
	return 0;
}

size_t my_strspn(const char *string1, const char *string2)
{
	int res = 0;
	for (int i = 0; check_affiliation(string1[i], string2); i++)
		res += 1;
	return res;
}


char *my_strdup(const char *str1)
{
	int len = strlen1(str1);
	char *res = malloc((len + 1) * sizeof(char));
	if (res)
	{
		for (int i = 0;i < len; i++)
		{
			res[i] = str1[i];
		}
		res[len] = 0;
	}
	else
		return NULL;
	return res;
}