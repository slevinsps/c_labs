#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "defines.h"

typedef  int(*comparator)(const void*, const void*); 
typedef int (__cdecl *count_numbers)(FILE *f);
typedef int (__cdecl *key)(const int *pb, const int *pe, int **new_begin, int **new_end);
typedef void (__cdecl *rewrite_array)(int *min, int *max, int **new_begin, int **new_end);
typedef int (__cdecl *read_array)(FILE *f, int *pb, int **pe, int k);
typedef int (__cdecl *print_array)(const int *pb, const int *pe, FILE *f);
typedef void (__cdecl *mysort)(void *first, size_t number, size_t size, comparator compare);


int compare_int(const void *p, const void *q)
{
    const int *a = p;    
    const int *b = q;
    return *a - *b;     
}
            
int main(int argc, char **argv)
{    
	HMODULE hlib;
	count_numbers count_numbers_b;
	key key_b;
	read_array read_array_b;
	print_array print_array_b;
	mysort mysort_b;
	
	
	hlib = LoadLibrary("libarr.dll");
	if (!hlib)
    {
        printf("Cannot open library.\n");
        return -1;
    }
	
	count_numbers_b = (count_numbers) GetProcAddress(hlib, "count_numbers");
    if (!count_numbers_b)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return -1;
    }
	key_b = (key) GetProcAddress(hlib, "key");
    if (!key_b)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return -1;
    }
	read_array_b = (read_array) GetProcAddress(hlib, "read_array");
    if (!read_array_b)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return -1;
    }
	print_array_b = (print_array) GetProcAddress(hlib, "print_array");
    if (!print_array_b)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return -1;
    }
	mysort_b = (mysort) GetProcAddress(hlib, "mysort");
    if (!mysort_b)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return -1;
    }
	
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
                k = count_numbers_b(f1);
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
						err = read_array_b(f1, pb, &pe, k);
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
									err = key_b(pb, pe, &new_begin, &new_end);    
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
										mysort_b(new_begin, new_end - new_begin, sizeof(int), compare_int);
										print_array_b(new_begin, new_end, f2);
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
								mysort_b(pb, pe - pb, sizeof(int), compare_int);
								print_array_b(pb, pe, f2);                        
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
	FreeLibrary(hlib);
    return err;
}