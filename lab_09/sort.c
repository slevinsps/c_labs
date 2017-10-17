# include <stdio.h>
# include <string.h>
# include <stdlib.h>



void sort(char **words, int n)
{
	char* tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (strcmp(words[i],words[j]) > 0)
			{
				tmp = words[i];
				words[i] = words[j];
				words[j] = tmp;
			}
		}
	}
}	
