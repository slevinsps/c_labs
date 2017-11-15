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