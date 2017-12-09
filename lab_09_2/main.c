#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "find_replace.h"
#include "defines.h"

        
int main(int argc, char **argv) // основной main
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
			fseek(f1, 0, SEEK_END);
			int pos = ftell(f1);
			if (pos > 0)
			{
				fseek(f1, 0, SEEK_SET);
				f2 = fopen(argv[2], "w");
				if (f2 == NULL)
				{
					printf("NO FILE 2\n");
					err = NO_FILE;
				}
				else
				{
	
					
					//while (my_getdelim(&s, &n, '\n', f1) != ERROR)
					while (my_getline(&s, &n, f1) != ERROR)
					{
						char *s1;
						s1 = str_replace(s, argv[4], argv[6]);
						if (!s1)
						{
							err = ERROR_IN_REPLACE;
							break; 
						}
						else
						{ 
							fprintf(f2,"%s",s1);
							free(s1);
						}
					}
					free(s);
					fclose(f2);
				}
			}
			else
			{
				printf("File is empty\n");
				err = NO_FILE;
			}
            fclose(f1);  
        }
    }
    return err;
}
