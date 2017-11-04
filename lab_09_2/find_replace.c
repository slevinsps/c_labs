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
	for(int i = 0; i < len1 - len2+2; i++ )
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



char* str_replace(const char *source, const char *search, const char *replace)
{
	
	char *s = NULL;
	int len1;
	int len2 = strlen1(search);
	int len3 = strlen1(replace);
	int len_res = strlen1(source);
	int pos1 = 0;
	int pos2 = 0;
	int j;
	char *new_source = malloc(len_res+1);
	
	return NULL;
	for (int i = 0; i < len_res; i++)
	{
		new_source[i] = source[i];		
	}
	new_source[len_res] = 0;
	
	while (find_underline(new_source, search, &pos1, &pos2))
	{
		//printf("%s\n",s);
		len1 = strlen1(new_source);
		len_res = len1 - len2 + len3;
		//printf("%%  %d\n", pos1 + len3);
		s = malloc(len_res+1);
		//printf("%d    %d\n",pos1, pos2);
		
		//printf("dsd\n");
		
		for (int i = 0; i < pos1; i++ )
		{
			s[i] = new_source[i];
		}
		
		for (int i = pos1; i < pos1 + len3; i++ )
		{
			s[i] = replace[i-pos1];
		}
		
		j = pos2;
		for (int i = pos1 + len3; i < len_res; i++ )
		{
			
			s[i] = (new_source)[j];
			j++;
		}

		//printf("%s\n",source);
		
		s[len_res] = 0;
		new_source = realloc(new_source,len_res+1);
		for (int i = 0; i < len_res; i++)
		{
			new_source[i] = s[i];
		}
		free(s);
		new_source[len_res] = 0;
		//printf("%s\n",(*source));
	} 
	return new_source;
}

size_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream)
{
	char delim = (char)delimiter;
	int buf_size = 5;
    char buf[buf_size];
	*lineptr = realloc(*lineptr,sizeof(char));
	if (!*lineptr)
		return 0;
	(*lineptr)[0] = 0;
	int len_dop;
	while (fgets(buf, buf_size, stream))
	{ 
		//printf("%d  %s\n",strlen1(buf),buf);
		/* for (int i = 0; i < buf_size; i++)
		{
			if (delim != '/n' && buf[i] == '/n')
				buf[i] = ' ';
		} */
		for (int i = 0; i < buf_size-1; i++)
		{
			if (buf[i] == delim)
			{
				len_dop = strlen1(buf);
				//printf("!!! %d    %d \n",i,ftell(stream));
				
				//printf(" %d\n",strlen1(buf)-(i));
				//printf(" %d\n",ftell(stream)-(strlen1(buf)-(i)));
				//if (buf_size - i > 2)
				//{
					//printf("%d\n",ftell(stream)-1);
					
				//}
				//buf[i] = 0;
				buf[i] = 0;
				
				if (strlen1(buf) != 0)
					strcat1(lineptr, buf);
				//printf("%d ^^^^ %d\n",strlen1(*lineptr),strlen1(buf));
				
				
				
				
				*n = strlen1(*lineptr);
				//printf("@@ %d\n", ftell(stream)-(len_dop-i));
				fseek( stream , ftell(stream)-(len_dop-i)+1 , SEEK_SET );
				//printf("%d\n",*n);
				return *n;
			}
		}
		strcat1(lineptr, buf);
	}
	//printf("%s",*lineptr);
	//*n = strlen1(*lineptr);
	return 0;
} 
