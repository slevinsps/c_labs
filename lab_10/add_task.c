#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

#define SIZE_BUF 200
# define SEP "\"., ?!\n" 

const char *strchr1(const char *str, char symbol)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == symbol)
        {
            return str + i;
        }
    }
    return NULL;
}

int count_words(const char *str)
{
    int n = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!strchr1(SEP, str[i]) && (i == 0 || strchr1(SEP, str[i - 1])))
            n++;
    }
    return n;
}

void split_words(char *str, char **words, int ind)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!strchr1(SEP, str[i])) 
        {
            if (i == 0 || str[i - 1] == 0)
            {
                words[ind] = &(str[i]);
                ind++;
            }
        }
        else
            str[i] = 0;
    }
}

int load_list_int(node_t *head, char **words, int n)
{
    head->data = words[0];
    head->next = NULL;
    node_t *tmp;
    for (int i = 1; i < n; i++)
    {
        tmp = malloc(sizeof(node_t));
		if (!tmp)
			return -1;
        tmp->next = NULL;
        tmp->data = words[i];
        
        head->next = tmp;
        head = head->next;
    }    
	return 0;
}

int read_text(FILE *f, char ***words, int *n)
{
	int ind;
	char *string = malloc(SIZE_BUF);
	if (!string)
		return -1;
	int size_arr = 0;
	while (fgets(string, SIZE_BUF, f))
    {
        ind = *n;
        *n += count_words(string);
		if (*n > size_arr)
		{
			size_arr = *n * 2;
			*words = realloc(*words, size_arr * sizeof(char *));	
		}
		split_words(string, *words, ind);
        string = malloc(SIZE_BUF);
    }
	return 0;
}

int comp1(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
} 

void print_list(FILE *f, node_t *head)
{
    while (head)
    {
        fprintf(f, "%s\n", (char *)(head->data));
        head = head->next;
    }
}