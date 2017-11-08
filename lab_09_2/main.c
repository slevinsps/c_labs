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
			char *s1;
			while (1)
			{
				err = my_getdelim(&s, &n, '\n', f1);

				//err = my_getline(&s, &n, f1);
				//err = my_getdelim(&s, &n, '\n', f1);
				//err = getdelim(&s, &n, '!', f1);
				if (err == ERROR)
				{
					break;
				}
				else
				{
					err = OK;
					s1 = str_replace(s, argv[4], argv[6]);
					if (s1)
					{
						fprintf(f2,"%s\n",s1);
						free(s1);
						s1 = NULL;
					}
					if (feof(f1))
						break;
				}
				
			}  
			free(s);
			fclose(f1);
			fclose(f2);
		}
	}
	return err;
}