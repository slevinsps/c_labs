# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# define SEP "., ?!" 

const char *strchr1(const char *str, char symbol)
{
    const char *c = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == symbol)
        {
            c = &(str[i]);
            break;
        }
    }
    return c;
}

int count_words(const char *str)
{
    int n = 0;
    int len = strlen(str);
    for (int i = 0;i < len;i++)
    {
        if (!strchr1(SEP, str[i]) && (i == 0 || strchr1(SEP, str[i-1])))
            n++;
    }
    return n;
}

void split_words(char *str, char **words)
{
    int k = 0;
    int len = strlen(str);
    for (int i = 0;i < len;i++)
    {
        if (!strchr1(SEP, str[i])) 
        {
            if (i == 0 || str[i-1] == 0)
            {
                words[k] = &(str[i]);
                k++;
            }
        }
        else
            str[i] = 0;
    }    
} 