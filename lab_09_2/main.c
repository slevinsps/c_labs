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
	char *s = NULL;
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
			/* char *s1 = malloc(3);
			s1[0] = 0;
			//s1[1] = 0;
			char s2[3];
			s2[0] = 0;
			strcat1(&s1,s2);
			printf("%s",s1); */
			my_getdelim(&s, &n, '\n', f1);

			//fprintf(stdout,"%s\n",s);
			//str_replace(&s, argv[4], argv[6]);
			
			//int l = 0;
			char *s1;
			while (!feof(f1))
			{
				//
				s1 = str_replace(s, argv[4], argv[6]);
				if (s)
				{
					
					fprintf(f2,"%s\n",s1);
					free(s1);
				}
				//my_getline(&s, &n, f1);
				my_getdelim(&s, &n, '\n', f1);
				
				//fprintf(stdout,"%s\n",s);
				//str_replace(s, argv[4], argv[6]);
				//if (l++>55)
					//break;
			}  
			fclose(f1);
			fclose(f2);
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