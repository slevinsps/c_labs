#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_affiliation(char ch, const char *string2)
{
	int len = strlen(string2);
	for (int i = 0; i < len; i++)
	{
		if (ch == string2[i])
			return 1;
	}
	return 0;
}

size_t strspn1( const char *string1, const char *string2 )
{
	int res = 0;
	for (int i = 0; check_affiliation(string1[i], string2); i++)
		res += 1;
	return res;
}


char *strdup1(const char *str1)
{
	int len = strlen(str1);
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


void read_line(char **str, FILE *f)
{
    int buf_size = 5;
    int size = 0;
    int count = 0;
    int k = 1;
    char buf[buf_size];
    *str = malloc(sizeof(char));
    while (buf[0] != '\n')
    {
        fgets(buf, buf_size, f);
        printf("@@@  %s\n",buf);
        
        if (buf[0] != '\n')
        {
            printf("@@@");
            //printf("! %s\n",buf);
            count = 0;
            *str = realloc(*str,buf_size * k - (k-1));
            
            for (int i = size; i < size + buf_size; i++)
            {    
                (*str)[i] = buf[count];
                count++;
            }
            k++;
            size += buf_size;    
        }
    } 
    //fgets(buf, buf_size, f);
    //printf("%s\n",buf);
    for (int i = 0; i < buf_size * k- (k-1);i++)
    {
        printf("%c",(*str)[i]);
    }
}

int strcat1(char **s1, char *s2)
{
	int len1 = strlen(*s1);
	int len2 = strlen(s2);
	
	*s1 = realloc(*s1,len1 + len2);
	if (*s1)
	{
		for (int i = len1; i < len1 + len2; i++)
		{
			//printf("%d\n",i-len1);
			(*s1)[i] = s2[i - len1];
		}
	}
	(*s1)[len1 + len2] = 0;
	
	return 0;
}





char* str_replace(const char *source, const char *serach, const char *replace);
{
	len1 = strlen(source);
	for (int i = 0; i < len1)
	{
		
	
}
size_t  getline(char **lineptr, size_t *n, int delimiter, FILE *stream)
{
	int buf_size = 5;
    char buf[buf_size];
	*lineptr = malloc(sizeof(char));
	(*lineptr)[0] = 0;
	int k = 0;
	while (fgets(buf, buf_size, stream))
	{ 
		if (buf[strlen(buf)-1] == '\n')
		{	
			buf[strlen(buf)-1] = 0;
			strcat1(lineptr, buf);
			break;
		}
		else
			strcat1(lineptr, buf);
	}
	printf("%s",*lineptr);
	*n = 1;
	return *n;
} 


int main(void)
{
	//char *strtext = "129thjhjhhjh7";
    //char digit[] = "1234567890"; 
	size_t n = 5;
	char *s;
	FILE *f = fopen("text.txt","r");
	getline(&s, &n, 5, f);
	printf("\n");
	getline(&s, &n, 5, f);
	//char *ss = "7sdsdsdsdk;jlkjkljkj915";
	//printf("%I64d   %I64d \n",strlen(s),strlen(ss));
	//strcut1(&s, ss);
	//printf("%s",s);
	//printf("%I64d",strspn1( strtext, digit ));
	/*
	while(fgets(s,25,f))
	{
		printf("@");
		printf("## %s\n",s);
	} */
	
	return 0;
}