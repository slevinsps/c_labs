#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NUMBER_ITEMS 100
    
#define OK 0
#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2
#define NUMBER_ITEMS_EXCEEDED -3
#define NUMBER_UNCORRECT -4

int sum_proizved(const int* pb,const int* pe)
{
	pe = pe - 1;
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
    int k = 0;
    int err = OK;
    if (fscanf(f,"%d",*pb) == 1)
    {
        *pe = *pb; 
		//printf("%d\n",**pe);
		*pe = *pe + 1;
		
        k++;
		while((fscanf(f,"%d",*pe) == 1) && (k <= NUMBER_ITEMS))
		{
			//printf("%d\n",**pe);
			*pe = *pe + 1;
			
			k++;
		}

		if (k > NUMBER_ITEMS)
		{
			err = NUMBER_ITEMS_EXCEEDED;
		}
	}
	else
	{
		err = NUMBER_UNCORRECT;
	}
    return err;        
}

    
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
				if (err == NUMBER_UNCORRECT)
				{
					printf("First element in array uncorrect or array is empty");	
				}
				else
				{
					if (err == NUMBER_ITEMS_EXCEEDED)
					{
						printf("The number of elements exceeded %d Only %d elements will be taken into account\n",NUMBER_ITEMS,NUMBER_ITEMS);
					}
					sum = sum_proizved(pb, pe);
					printf("The sum of products of positive and negative elements = %d",sum);
				}
            }
            fclose(f);
        }    
    return err;
}
