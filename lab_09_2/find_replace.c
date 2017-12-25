#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include <unistd.h>
#include "defines.h"

#define LEN_STR_BEGIN 120
#define LEN_STR_BEGIN2 320

// нахождение подстроки в строке    
// source - исходная строка
// search - подстрока, кторую нужно найти в source
// pos1 - начало вхождения подстроки
// pos2 - конец вхождения подстроки
int find_underline(const char *source, const char *search, int *pos1, int *pos2, int pos_begin)
{
    int len1 = strlen1(source);
    int len2 = strlen1(search);     

    int i = pos_begin;
    int j = pos_begin;
    *pos1 = -1;
    while (i < len1 - len2 + 1 && *pos1 == -1)
    {
        *pos1 = i;
        j = i;
        while (j < i + len2 && *pos1 != -1)
        {
            if (source[j] != search[j - i])
            {
                *pos1 = -1;
            }
            j++;
        }
        i++;
    }
    if (*pos1 != -1)
    {
        *pos2 = *pos1 + len2;
        return 1;
    }
	*pos1 = 0;
	*pos2 = 0;
    return 0;
}


char *my_strdup(const char *str1)
{
    int len = strlen1(str1);
    char *res = malloc((len + 1) * sizeof(char));
    if (res)
    {
        for (int i = 0; i < len; i++)
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
char *str_replace(const char *source, const char *search, const char *replace)
{
    if ((source == NULL) || (search == NULL) || (replace == NULL))
        return NULL;

    int len1;
    
    int len2 = strlen1(search);
    int len3 = strlen1(replace);
    int len_res = strlen1(source);
    
    int pos1 = 0;
    int pos2 = 0;
    
    char *new_source;
    new_source = my_strdup(source);
    if (!*new_source)
        return NULL;
    int pos_begin = 0;
    while (find_underline(new_source, search, &pos1, &pos2, pos_begin))
    {
        len1 = strlen1(new_source);
        len_res = len1 - len2 + len3;
	
		char *s = malloc(len_res + 1);
        memmove(s, new_source, pos1);
		memmove(s + pos1, replace, len3);
		memmove(s + pos1 + len3, new_source + pos2, len1 - pos2 + 1);
		
		new_source = realloc(new_source, len_res + 1);
		memmove(new_source, s, len_res + 1);

        free(s);
		pos_begin = pos1 + len3;
    }
    return new_source;
}

char *str_replace1(const char *source, const char *search, const char *replace)
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
    int j;
    
    char *new_source = malloc(len_res + 1);

    for (int i = 0; i <= len_res; i++)
    {
        new_source[i] = source[i];        
    }
    int pos_begin = 0;
    while (find_underline(new_source, search, &pos1, &pos2, pos_begin))
    {
        len1 = strlen1(new_source);
        len_res = len1 - len2 + len3;
        s = malloc(len_res + 1);
        
        for (int i = 0; i < pos1; i++)
        {
            s[i] = new_source[i];
        }
        
        for (int i = pos1; i < pos1 + len3; i++)
        {
            s[i] = replace[i - pos1];
        }
        
        j = pos2;
        for (int i = pos1 + len3; i < len_res; i++)
        {
            s[i] = (new_source)[j];
            j++;
        }    
        s[len_res] = 0;
        new_source = realloc(new_source, len_res + 1);
        for (int i = 0; i < len_res; i++)
        {
            new_source[i] = s[i];
        }
        free(s);
        new_source[len_res] = 0;
        pos_begin = pos1 + len3;
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
        *n = LEN_STR_BEGIN;
        char *tmp = realloc(*lineptr, *n * sizeof(char));
		if (!tmp)
			return ERROR;
		*lineptr = tmp;
    }
	
    int buf;
    
    size_t n_new = 0;
    char *tmp;
    
	if ((buf = fgetc(stream)) == EOF)
		return ERROR;
	if (buf != delimiter)
	{
		do
		{
			if (n_new >= *n)
			{
				*n *= MULTIPLY;
				tmp = (char *) realloc(*lineptr, *n * sizeof(char));
				if (!tmp)
					return ERROR;
				*lineptr = tmp;
			}
			(*lineptr)[n_new] = buf;
			n_new++;         
		} while ((buf = fgetc(stream)) != EOF && buf != delimiter);
	}
	
    if (n_new >= *n)
    {
        *n = 2 * n_new;
        tmp = realloc(*lineptr, *n);
        if (!tmp)
            return ERROR;
        *lineptr = tmp;
    }

    (*lineptr)[n_new] = 0;
    if (buf == delimiter)
    {
        (*lineptr)[n_new] = delimiter;
        n_new++;
        if (n_new >= *n)
        {
            *n = 2 * n_new;
            tmp = realloc(*lineptr, *n);
            if (!tmp)
                return ERROR;
            *lineptr = tmp;
        }
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
    if ((lineptr == NULL) || (n == NULL) || (!stream))
        return ERROR;
    
    if (*lineptr == NULL || *n == 0)
    {
        *n = LEN_STR_BEGIN2;
		
        char *tmp = realloc(*lineptr, *n * sizeof(char));
		if (!tmp)
			return ERROR;
		*lineptr = tmp;
    }
	
	
    char *buf_string = calloc(LEN_STR_BEGIN, sizeof(char));
	if (!buf_string)
		return ERROR;
    size_t n_new = 0;
    char *tmp;
    int len = 0;
    
	if ((fgets(buf_string, LEN_STR_BEGIN, stream)) == NULL)
	{
		free(buf_string);
		return ERROR;
    }
	
    do
    { 
        len = strlen1(buf_string);
        if (n_new + len > *n)
        {
            *n = n_new + len;
            tmp = realloc(*lineptr, *n);
            if (!tmp)
                return ERROR;
            *lineptr = tmp;
        }
        for (int i = 0; i < len; i++)
        {
            (*lineptr)[n_new] = buf_string[i];
            n_new++;     
        }
        if (buf_string[len - 1] == '\n')
		{
            break;
		}
    } while ((fgets(buf_string, LEN_STR_BEGIN, stream)) != NULL);
	
	if (n_new >= *n)
    {
		*n = n_new + 1;
		tmp = realloc(*lineptr, *n);
        if (!tmp)
            return ERROR;
		*lineptr = tmp;
	}
    (*lineptr)[n_new] = 0;
	if (n_new == 0)
	{
		n_new = ERROR;
	}
	free(buf_string);

    return n_new;
}
