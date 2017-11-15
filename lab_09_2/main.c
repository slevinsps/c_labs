#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "find_replace.h"
#include "defines.h"



/* 
int main(int argc, char **argv)
{
    FILE *f1;
    FILE *f2;
    size_t n = 0;        
    char *s = NULL;
    int err = OK;
    int res;
	if (argc != 7 || strcmp(argv[3], "-s") != 0 || strcmp(argv[5], "-r") != 0)
    {
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
            char *s1;
			while ((res = my_getdelim(&s, &n, '\n', f1)) != -1)
            {
                s1 = str_replace(s, argv[4], argv[6]);
                if (!s1)
                {
					err = -4;
					break;
                    
                }
				else
				{
					fprintf(f2,"%s",s1);
                    free(s1);
				}
            }  
            free(s);
            fclose(f1);
            fclose(f2);
        }
    }
    return err;
}

 */


int main(int argc, char **argv)
{
    char *line = NULL;
    char *res = NULL;
    int rc = OK;
    FILE * f;
    FILE * g;
    int n = 0;
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
} 