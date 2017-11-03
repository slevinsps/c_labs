#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "find_replace.h"
#include "defines.h"



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
            //fprintf(stderr, "%s\n", strerror(errno));
			printf("NO FILE\n");
            err = NO_FILE;
        }
        else
		{
			f2 = fopen(argv[2], "w");
			
			my_getline(&s, &n, f1);
			while (strlen(s) > 0)
			{
				str_replace(&s, argv[4], argv[6]);
				fprintf(f2,"%s\n",s);
				my_getline(&s, &n, f1);
				//fprintf(stdout,"%s\n",s);
				//str_replace(s, argv[4], argv[6]);
				
			}
		}
	}
	//char *strtext = "129thjhjhhjh7";
    //char digit[] = "1234567890"; 
	
	/* FILE *f = fopen("text.txt","r");
	my_getline(&s, &n, 5, f);
	str_replace(s, "aa", "bbb");
	printf("%s",s); */
	//my_getline(&s, &n, 5, f);
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