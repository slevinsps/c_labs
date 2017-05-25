#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "read_array.h"
#include "sum_proizved.h"

#define NUMBER_ITEMS 100
    
#define OK 0
#define NO_FILE -1
#define FILE_EMPTY -2
#define NOT_ALL_ARGUMENTS -3
#define NUMBER_ITEMS_EXCEEDED -4
    
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
    
