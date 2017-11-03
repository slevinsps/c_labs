#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "defines.h"

int find_underline(const char *source, const char *search, int *pos1, int *pos2)
{
	//printf("%s\n",source);
	int len1 = strlen1(source);
	//printf("%d \n",len1);
	int len2 = strlen1(search);
	int count = 1;
	for(int i = 0; i < len1 - len2+1; i++ )
	{
		for(int j = i; j < i+len2; j++ )
		{
			if (source[j] != search[j-i])
			{
				count = 0;
				break;
			}
		}
		if (count)
		{
			
			*pos1 = i;
			*pos2 = i + len2;
			//printf("%d   %d\n",*pos1,*pos2);
			/* for(int r = *pos1; r < *pos2; r++ )
				printf("%c",source[r]);
			printf("\n@@@@   %s \n",search); */
			
			//printf("%d   %d\n",*pos1,*pos2);
			return 1;
		}
		else
		{
			count = 1;
		}
	}

	return 0;
}



void str_replace(char **source, const char *search, const char *replace)
{
	char *s;
	int len1;
	int len2 = strlen1(search);
	int len3 = strlen1(replace);
	int len_res;
	int pos1 = 0;
	int pos2 = 0;
	while (find_underline(*source, search, &pos1, &pos2))
	{
		//printf("%s\n",s);
		len1 = strlen1(*source);
		len_res = len1 - len2 + len3;
		//printf("%%  %d\n", pos1 + len3);
		s = malloc(len_res+2);
		//printf("%d    %d\n",pos1, pos2);
		
		//printf("dsd\n");
		
		for (int i = 0; i < pos1; i++ )
		{
			s[i] = (*source)[i];
		}
		
		for (int i = pos1; i < pos1 + len3; i++ )
		{
			s[i] = replace[i-pos1];
		}
		
		int j = pos2;
		for (int i = pos1 + len3; i < len_res; i++ )
		{
			
			s[i] = (*source)[j];
			j++;
		}
		//printf("%s\n",source);
		s[len_res] = 0;
		free((*source));
		
		(*source) = s;
		//printf("%s\n",(*source));
		
		
	}
}

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	int buf_size = 5;
    char buf[buf_size];
	*lineptr = malloc(sizeof(char));
	(*lineptr)[0] = 0;
	// int k = 0;
	while (fgets(buf, buf_size-1, stream))
	{ 
		//printf("@%s\n",buf);
		if (buf[strlen1(buf)-1] == '\n')
		{	
			buf[strlen1(buf)-1] = 0;
			strcat1(lineptr, buf);
			break;
		}
		else
			strcat1(lineptr, buf);
	}
	//printf("%s",*lineptr);
	*n = strlen1(*lineptr);
	return *n;
} 
