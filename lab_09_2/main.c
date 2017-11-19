#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "find_replace.h"
#include "defines.h"
#include "getdelim.h"



int main(int argc, char **argv)
{
    FILE *f1;
    FILE *f2;
    size_t n = 0;        
    char *s = NULL;
    int err = OK;
	
	if (argc != 7 || strcmp(argv[3], "-s") != 0 || strcmp(argv[5], "-r") != 0)
    {
		printf("./app.exe input.txt output.txt -s <SEARCH> -r <REPLACE>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else 
    {
        f1 = fopen(argv[1], "r");
        if (f1 == NULL)
        {
            printf("NO FILE 1\n");
            err = NO_FILE;
        }
        else
        {
            f2 = fopen(argv[2], "w");
			if (f2 == NULL)
			{
				printf("NO FILE 2\n");
				err = NO_FILE;
			}
			else
			{
				char *s1;
				while (my_getdelim(&s, &n, '\n', f1) != ERROR)
				{
					s1 = str_replace(s, argv[4], argv[6]);
					//if (!s1)
					//{
					//	err = ERROR_IN_REPLACE;
					//	break; 
					//}
					//else
					//{ 
						
						fprintf(f2,"%s",s1);
						//free(s1);
					//}
				}
				fclose(f2);
				free(s);
			}
            fclose(f1);  
        }
    }
    return err;
}

/*
int main(int argc, char **argv)
{
    char *line = NULL;
    char *res = NULL;
    int rc = OK;
    FILE * f;
    FILE * g;
    size_t n = 0;
    int  read = 0;
    setbuf(stdout, NULL);

    if (argc != 7 || strcmp(argv[3], "-s") != 0 || strcmp(argv[5], "-r") != 0)
    {
        rc = -1;
    }
    else
    {
        f = fopen(argv[1], "r");

        if (f)
        {
            g = fopen(argv[2], "w");

            if (g)
            {
                while ((read = my_getdelim(&line, &n, '\n', f)) != -1)
                {
                    res = str_replace(line, argv[4], argv[6]);
                    if (!res)
                    {
                        //printf("Replace error\n");
                        rc = -3;
                        break;
                    }
                    else
                    {
                        fprintf(g, "%s", res);
                        free(res);
                    }
                }
                free(line);
            }
            else
            {
                fprintf(stdout, "Couldn't open %s because of %s \n", argv[2], strerror(errno));
                rc = -5;
            }
            fclose(g);
        }
        else
        {
            fprintf(stdout, "Couldn't open %s because of %s \n", argv[1], strerror(errno));
            rc = -7;
        }

        fclose(f);
    }
    //ferror?
    return rc;
} */