#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "read_array.h"
#include "sum_proizved.h"
#include "defines.h"
    
int main(int argc, char** argv)
{
    FILE *f;
    int a[NUMBER_ITEMS];
    int sum;
    int err = OK;
    int *pb = a;
    int *pe = a;
    
    if (argc != 2)
    {
        fprintf(stderr, "main1.exe <file-name>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            fprintf(stderr, "%s\n",strerror(errno));
            err = NO_FILE;
        }
        else
        {
            err = read_array(f, &pb, &pe);
            if (err == FILE_EMPTY)
            {
                printf("File is empty");    
            }
            else
            {
                if (err == NUMBER_ITEMS_EXCEEDED)
                {
                    printf("The number of elements exceeded %d Only %d elements will be taken into account\n",NUMBER_ITEMS,NUMBER_ITEMS);
                }
                sum = sum_proizved(pb, pe - 1);
                printf("The sum of products of positive and negative elements = %d",sum);
            }
            fclose(f);
        }      
    }    
    return err;
}
    
