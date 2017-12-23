#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "io.h"
#include "binary_sort.h"
#include "defines.h"
//#define ARR_DLL __declspec(dllimport)
//#define ARR_DECL __cdecl   

/* typedef  int(*comparator)(const void*, const void*); 

ARR_DLL void ARR_DECL swap(void *a, void *b, size_t size);
ARR_DLL void* ARR_DECL binary_search(void *first, void *right, size_t size, comparator compare);
ARR_DLL void  ARR_DECL mysort(void *first, size_t number, size_t size, comparator compare);	

ARR_DLL int ARR_DECL count_numbers(FILE *f);
ARR_DLL int ARR_DECL key(const int *pb, const int *pe, int **new_begin, int **new_end);
ARR_DLL int ARR_DECL rewrite_array(int *min, int *max, int **new_begin, int **new_end);	
	
ARR_DLL int ARR_DECL read_array(FILE *f, int *pb, int **pe, int k);
ARR_DLL void ARR_DECL print_array(const int *pb, const int *pe, FILE *f);
	 */
int compare_int(const void *p, const void *q)
{
    const int *a = p;    
    const int *b = q;
    return *a - *b;     
}
            
int main(int argc, char **argv)
{    
    FILE * f1;
    FILE * f2;
    int *a;
    int err = OK;
    int *pb;
    int *pe;
    int k;
    int *new_begin;
    int *new_end;
    char *pstr;
    
    if (argc < 3 || argc > 4)
    {
        fprintf(stderr, "app.exe <file_input-name> <file_output-name> <filter or nothing>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else    
    {
        f1 = fopen(argv[1], "r");
        if (f1 == NULL)
        {
            fprintf(stderr, "%s\n", strerror(errno));
            err = NO_FILE_1;
        }
        else
        {
            f2 = fopen(argv[2], "w");
            if (f2 == NULL)
            {
                fprintf(stderr, "%s\n", strerror(errno));
                err = INCORRECT_OUTPUT_NAME;
            }
            else
            {
                k = count_numbers(f1);
                rewind(f1);
                if (k == 0)
				{
					err = ARRAY_EMPTY;
					printf("В файле нет элементов");
				}
				else
				{
					a = malloc(k * sizeof(int));
					if (a != NULL)
					{
						pb = a;
						pe = a;
						err = read_array(f1, pb, &pe, k);
						if (err == FILE_EMPTY)
						{
							fprintf(stderr, "File is empty");    
						}
						else
						{                        
							if (argc == 4)
							{
								pstr = argv[3];
								if (pstr[0] == 'f' && pstr[1] == 0)
								{
									new_begin = malloc((pe - pb) * sizeof(int));
									err = key(pb, pe, &new_begin, &new_end);    
									if (err == ARRAY_EMPTY)
									{
										fprintf(stderr, "Array is empty");    
									}
									if (err == MEMORY_ERROR)
									{
										fprintf(stderr, "Memory error");    
									}
									if (err == OK)
									{
										mysort(new_begin, new_end - new_begin, sizeof(int), compare_int);
										print_array(new_begin, new_end, f2);
										free(new_begin);
									}
								}
								else
								{
									err = -11;
									printf("Incorrect key");
								}
							}
							else
							{
								mysort(pb, pe - pb, sizeof(int), compare_int);
								print_array(pb, pe, f2);                        
							}
						}					
						free(a);
					}                                
					else
					{
						printf("Memory error\n");
						err = MEMORY_ERROR;
					}
				}
				fclose(f2);
            }
            fclose(f1);
        }      
    }    
    return err;
}