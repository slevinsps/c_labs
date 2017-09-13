#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "defines.h"

int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b; 
}
    


unsigned long long tick(void)
{
 unsigned long long d;
 __asm__ __volatile__ ("rdtsc" : "=A" (d) );
 return d;
}
    
int main(int argc, char** argv)
{
    FILE *f1;
    FILE *f2;
    int *a, *a2;

    int err = OK;
    int *pb;
    int *pe;
    int k;
    int *ppb;
    int n;
    int *new_begin;
    char* pstr;
    unsigned long long tb, te;
    
    if (argc != 4)
    {
        fprintf(stderr, "main1.exe <file_input-name> <file_output-name> <filter>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else
    {
        f1 = fopen(argv[1], "r");
        if (f1 == NULL)
        {
            fprintf(stderr, "%s\n",strerror(errno));
            err = NO_FILE_1;
        }
        else
        {
            f2 = fopen(argv[2], "w");
            if (f2 == NULL)
            {
                fprintf(stderr, "%s\n",strerror(errno));
                err = INCORRECT_OUTPUT_NAME;
            }
            else
            {
                k = count_numbers(f1);
                rewind(f1);
                
                a = malloc(k*sizeof(int));
                if (a != NULL)
                {
                    pb = a;
                    pe = a;
                    err = read_array(f1, &pb, &pe,k);
                    if (err == FILE_EMPTY)
                    {
                        fprintf(stderr,"File is empty");    
                    }
                    else
                    {
                        pstr = argv[3];
                        if(pstr[0] == 'y' && pstr[1] == 0)
                        {
                            search_min_max(pb,pe,&ppb,&n);
                            a2 = malloc((n)*sizeof(int));
                            if (a2 != NULL)
                            {
                                new_begin = a2;
                                err = rewrite_array(ppb,n,&new_begin);
                                
                                if (err == ARRAY_EMPTY)
                                {
                                    fprintf(stderr,"Array is empty");    
                                }
                                else
                                {
                                    tb = tick();
                                    //qsort(new_begin,n,sizeof(int),compare_int);
                                    binary_insert(new_begin,n,sizeof(int),compare_int);
                                    te = tick();
                                    printf("test 'time': %I64d\n", (te - tb) / n);
                                    
                                    print_array(new_begin, new_begin+n-1,f2);
                                }
                                free(a2);
                            }
                            else
                            {
                                printf("Memory error\n");
                                err = MEMORY_ERROR;
                            }    
                        }
                        else
                        {
                            if(pstr[0] == 'n' && pstr[1] == 0)
                            {
                                binary_insert(pb,pe-pb,sizeof(int),compare_int);
                                print_array(pb, pe-1,f2);
                            }
                            else
                            {
                                fprintf(stderr, "Enter filter value: y/n");
                                err = INCORRECT_FILTER;
                            }
                        }
                        free(a);
                    }
                }
                else
                {
                    printf("Memory error\n");
                    err = MEMORY_ERROR;
                }
                fclose(f2);
            }
            fclose(f1);
        }      
    }    
    return err;
}