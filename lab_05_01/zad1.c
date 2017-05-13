#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NUMBER_ITEMS 100
    
#define OK 0
#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2
#define NUMBER_ITEMS_EXCEEDED -3

int sum_proizved(const int* pb,const int* pe)
{
    int sum = 0;
    const int *left_border = pb;
    const int *right_border = pe;
    while(pe>=left_border && right_border>=pb)
    {
        if (*left_border < 0)
        {
            if (*right_border > 0)
            {
                sum += (*right_border)*(*left_border);
                right_border--;
                left_border++;
            }
            else
            {
                right_border--;   
                
            }
        }
        else
        {
            left_border++;
        }
    }    
    return sum;
}

int read_array(FILE *f, int **pb, int **pe)
{
    int x;
    int k = 0;
    int warning = OK;
    if (fscanf(f,"%d",&x) == 1)
    {
        **pb = x;
        **pe = x; 
        k++;
    } 
    while((fscanf(f,"%d",&x) == 1) && (k <= NUMBER_ITEMS))
    {
        *pe = *pe + 1;
        **pe = x;
        k++;
    }
    if (k > NUMBER_ITEMS)
    {
        warning = NUMBER_ITEMS_EXCEEDED;
    }
    return warning;        
}

    
int main(int argc, char** argv)
{
    FILE *f;
    int a[NUMBER_ITEMS];
    int sum;
    int err = OK;
    int warning;
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
                warning = read_array(f, &pb, &pe);
                sum = sum_proizved(pb, pe);
                if (warning == NUMBER_ITEMS_EXCEEDED)
                {
                    printf("The number of elements exceeded %d Only %d elements will be taken into account\n",NUMBER_ITEMS,NUMBER_ITEMS);
                }
                printf("The sum of products of positive and negative elements = %d",sum);
            }
            fclose(f);
        }    
    return err;
}
