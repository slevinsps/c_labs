#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#include "add_task.h"

#define SIZE_BUF 200
# define SEP "\"., ?!\n" 
# define NOT_ALL_ARGUMENTS -1
# define NO_FILE -2
# define OK 0


/* Условие задачи */
// Из файла f1 считывается текст, в котором вычленяются
// слова, затем они сортируются по алфавиту и записываются
// в файл f2
int main(int argc, char **argv)
{
	FILE *f1;
	FILE *f2;
	
	int err = OK;
	int n = 0;
    char **words = NULL;	
	if (argc != 3)
    {
        printf("./app.exe input.txt output.txt \n");
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
				read_text(f1, &words, &n);
				node_t *head = malloc(sizeof(node_t));
				node_t *res_sort;
				node_t *copy;
				load_list_int(head, words, n);
				res_sort = sort(head, comp1);
				printf("Done!\n");			
				print_list(f2, res_sort);
				while (res_sort)
				{
					copy = res_sort;
					res_sort = res_sort->next;
					free(copy);
				}
				free(words);
				fclose(f2);
			}
			fclose(f1);
		}
	}
	return err;
}



