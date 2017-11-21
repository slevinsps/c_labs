#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include <unistd.h>
#include "defines.h"


// нахождение подстроки в строке
// source - исходная строка
// search - подстрока, кторую нужно найти в source
// pos1 - начало вхождения подстроки
// pos2 - конец вхождения подстроки
int find_underline(const char *source, const char *search, int *pos1, int *pos2)
{
    int len1 = strlen1(source);
    int len2 = strlen1(search);     
    int count = 0;
    int i = 0;
    int j = 0;
	
	while(i < len1 - len2 + 1 && !count)
    {
		count = 1;
		j = i;
		while(j < i + len2 && count)
        {
			
            if (source[j] != search[j-i])
            {
                count = 0;
            }
			j++;
        }
		i++;
    }
	i--;
	if (count)
    {
        *pos1 = i;
        *pos2 = i + len2;
        return 1;
    }
    return 0;
}


char *my_strdup(const char *str1)
{
	int len = strlen1(str1);
	char *res = malloc((len+1)*sizeof(char));
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

// замена подстроки в строке
// source - исходная строка
// search - подстрока, которую нужно заменить в source
// replace - подстрока, на которую нужно заменить search
char* str_replace(const char *source, const char *search, const char *replace)
{
    if ((source == NULL) || (search == NULL) || (replace == NULL))
        return NULL;

    int len1;
    
    int len2 = strlen1(search);
    int len3 = strlen1(replace);
    int len_res = strlen1(source);
    
    int pos1 = 0;
    int pos2 = 0;
	
    char *new_source, *tmp;
	new_source = my_strdup(source);
	if (!*new_source)
		return NULL;
    
    while (find_underline(new_source, search, &pos1, &pos2))
    {
        len1 = strlen1(new_source);
        len_res = len1 - len2 + len3;
		tmp = realloc(new_source,len_res+1);
		if (!tmp)
			return NULL;
		new_source = tmp;
		
		memmove(new_source + pos1 + len3, new_source + pos2, len_res - ( pos1 + len3));
        memmove(new_source + pos1, replace, len3);
		
        new_source[len_res] = 0;
    }
    return new_source;
}

// выделение строки в тексте
// lineptr - полученная строка
// n - количество считанных бит
// delimiter - разделитель строк
// stream - файл с текстом
ssize_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream)
{
    
    if ((lineptr == NULL) || (n == NULL) || (!stream))
        return ERROR;
	
    if (*lineptr == NULL || *n == 0)
    {
        *n = 2;
        *lineptr =(char *) realloc(*lineptr,*n*sizeof(char));
        if (*lineptr == NULL)
        {
            return ERROR;
        }
    }
    int buf;
    
    size_t n_new = 0;
	char *tmp;
        
    while ((buf = fgetc(stream)) != EOF && buf != delimiter)
    { 
        if (n_new > *n)
		{
			*n *= MULTIPLY;
			tmp = realloc(*lineptr,*n);
			if (!tmp)
				return ERROR;
			//free(*lineptr);
			*lineptr = tmp;
		}
		(*lineptr)[n_new] = buf;
        n_new++; 		
    }
	(*lineptr)[n_new] = 0;
	if (buf == delimiter)
    {
        (*lineptr)[n_new] = delimiter;
		n_new++;
		(*lineptr)[n_new] = 0;
    }
	if (buf == EOF)
    {
		if (n_new == 0)
		{
			n_new = ERROR;
		}
    }
	return n_new;
}

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    return(my_getdelim(lineptr, n, '\n', stream));
}
