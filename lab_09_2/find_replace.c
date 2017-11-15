#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
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
    int count;
    for(int i = 0; i < len1 - len2 + 1; i++ )
    {
		count = 1;
        for (int j = i; j < i+len2; j++ )
        {
            if (source[j] != search[j-i])
            {
                count = 0;
            }
        }
        if (count)
        {
            *pos1 = i;
            *pos2 = i + len2;
            return 1;
        }
    }
    return 0;
}

void copy_string(char **new_source, const char *source)
{
	int len_res = strlen1(source);
	*new_source = malloc(len_res+1);
    for (int i = 0; i < len_res + 1; i++)
    {
        (*new_source)[i] = source[i];        
    }
}

// замена подстроки в строке
// source - исходная строка
// search - подстрока, которую нужно заменить в source
// replace - подстрока, на которую нужно заменить search
char* str_replace(const char *source, const char *search, const char *replace)
{
    if ((source == NULL) || (search == NULL) || (replace == NULL))
        return NULL;
    
    char *s = NULL;
    int len1;
    
    int len2 = strlen1(search);
    int len3 = strlen1(replace);
    int len_res = strlen1(source);
    
    int pos1 = 0;
    int pos2 = 0;
	
    char *new_source, *tmp;
	copy_string(&new_source, source);
	if (!*new_source)
		return NULL;
    
    while (find_underline(new_source, search, &pos1, &pos2))
    {
        len1 = strlen1(new_source);
        len_res = len1 - len2 + len3;
        s = calloc(len_res+1,sizeof(char));
        if (!s)
			return NULL;
		memcpy(s, new_source, pos1);
        memcpy(s + pos1, replace, len3);
        memcpy(s +pos1 + len3, new_source + pos2, len_res - ( pos1 + len3));

        tmp = realloc(new_source,len_res+1);
		if (!tmp)
			return NULL;
		new_source = tmp;
        for (int i = 0; i < len_res; i++)
        {
            new_source[i] = s[i];
        }
        free(s);
        new_source[len_res] = 0;
    } 
    return new_source;
}

// выделение строки в тексте
// lineptr - полученная строка
// n - количество считанных бит
// delimiter - разделитель строк
// stream - файл с текстом
size_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream)
{
    
    if ((lineptr == NULL) || (n == NULL) || (!stream))
        return ERROR;
    
    if (*lineptr == NULL || *n == 0)
    {
        *n = 1;
        *lineptr = malloc(*n*sizeof(char));
        if (*lineptr == NULL)
        {
            return ERROR;
        }
    }
    
    char delim = (char)delimiter;
    int buf;
    
    size_t n_new = 0;

        
    while (!feof(stream))
    { 
        buf = fgetc(stream);
        if (buf == EOF)
        {
            (*lineptr)[n_new] = 0;
            if (n_new == 0) 
                return ERROR;
            else
                return n_new;
        }
                
        if (buf == delim)
        {
            strcat1(lineptr, buf, n_new, n);
            
            (*lineptr)[n_new+1] = 0;
            return n_new+1;
        }
        strcat1(lineptr, buf, n_new, n);
        n_new++;        
    }
	return n_new;
}

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    return(my_getdelim(lineptr, n, '\n', stream));
}
