#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define OK 0
#define NOT_ALL_ARGUMENTS -1
#define NO_FILE -2

int strlen1(const char *string)
{
	int k = 0;
	while (string[k] != 0)
		k++;
	return k;
}
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

size_t strspn1( const char *string1, const char *string2 )
{
	int res = 0;
	for (int i = 0; check_affiliation(string1[i], string2); i++)
		res += 1;
	return res;
}


char *strdup1(const char *str1)
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
	int len1 = strlen1(*s1);
	int len2 = strlen1(s2);
	
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
size_t  getline(char **lineptr, size_t *n, int delimiter, FILE *stream)
{
	int buf_size = 5;
    char buf[buf_size];
	*lineptr = malloc(sizeof(char));
	(*lineptr)[0] = 0;
	//int k = 0;
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
	*n = 1;
	return *n;
} 


int main(int argc, char **argv)
{
	FILE *f1;
	FILE *f2;
	size_t n = 5;
	char *s;
	int err = OK;
	
	if (argc < 7)
    {
        fprintf(stderr, "app.exe <in.txt> <out.txt> –s <search> –r <replace>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else 
	{
		f1 = fopen(argv[1], "r");
        if (f1 == NULL)
        {
            fprintf(stderr, "%s\n", strerror(errno));
            err = NO_FILE;
        }
        else
		{
			f2 = fopen(argv[2], "w");
			
			getline(&s, &n, 5, f1);
			while (strlen(s) > 0)
			{
				str_replace(&s, argv[4], argv[6]);
				fprintf(stdout,"%s\n",s);
				getline(&s, &n, 5, f1);
				//fprintf(stdout,"%s\n",s);
				//str_replace(s, argv[4], argv[6]);
				
			}
		}

	}
	//char *strtext = "129thjhjhhjh7";
    //char digit[] = "1234567890"; 
	
	/* FILE *f = fopen("text.txt","r");
	getline(&s, &n, 5, f);
	str_replace(s, "aa", "bbb");
	printf("%s",s); */
	//getline(&s, &n, 5, f);
	//char *ss = "7sdsdsdsdk;jlkjkljkj915";
	//printf("%I64d   %I64d \n",strlen1(s),strlen1(ss));
	//strcut1(&s, ss);
	//printf("%s",s);
	//printf("%I64d",strspn1( strtext, digit ));
	/*
	while(fgets(s,25,f))
	{
		printf("@");
		printf("## %s\n",s);
	} */
	
	return err;
}