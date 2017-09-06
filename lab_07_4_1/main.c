#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_ITEMS 5  
#define OK 0
#define NO_FILE -1
#define FILE_EMPTY -2
#define NOT_ALL_ARGUMENTS -3
#define NUMBER_ITEMS_EXCEEDED -4


int count_numbers(FILE *f)
{
	int k = 0;
	int n;
	while (fscanf(f,"%d",&n) == 1)
	{
		k++;
	}
	
	return k;
}
int read_array(FILE *f, int **pb, int **pe)
{
    int err = OK;
    while(fscanf(f,"%d",*pe) == 1)
    {
        *pe = *pe + 1;
    }
	*pe = *pe + 1;
    
    if (*pe == *pb)
    {
        err = FILE_EMPTY;
    }
    
    if (*pe-*pb > NUMBER_ITEMS)
    {
        *pe = *pe - 1;
        err = NUMBER_ITEMS_EXCEEDED;
    }
    return err;        
}
  

void print_array(const int* pb,const int* pe)
{
    while (pe>pb)
    {
        printf("%d ",*pb);
        pb = pb +1;
    }
    printf("\n");
}


void bubble_sort(int *const pb,int *const pe)
{
   
    int elem;
    int n = pe - pb;
    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<=n; j++) 
        {
            if (*(pb+i) > *(pb+j))
            {
                elem = *(pb+i);
                *(pb+i) = *(pb+j);
                *(pb+j) = elem;
            }
        }
    }
}

void sort_min_max(int *pb, int const *const pe, int **ppb, int **ppe)
{
    int n;
    int *k;    
    int *min = pb; 
    int *max = pb;
	int *a2, *begin, *end;
        
    while(pe>pb)
    {
        if (*pb > *max)
        {
            max = pb;

        }
        
        if (*pb < *min)
        {
            min = pb;
        }
        
        pb = pb + 1;
    }
    if (min > max)
    {
        k = min;
        min = max;
        max = k;
    }
	n = max-min;
	a2 = malloc((n)*sizeof(int));
 	*ppb = a2;
	*ppe = a2;
	min = min + 1;
	
 	for(int i=1;i<n;i++)
	{
		**ppe = *min;
		
		min = min + 1;
		*ppe = *ppe + 1;
		
	}
    bubble_sort(*ppb, *ppe);

}


int main(int argc, char** argv)
{
    FILE *f;
    int *a;

    int err = OK;
    int *pb;
    int *pe;
    int k;
	int *ppb;
	int *ppe;
	
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
			k = count_numbers(f);
			rewind(f);
			
			a = malloc(k*sizeof(int));
			pb = a;
			pe = a;
            err = read_array(f, &pb, &pe);
			//printf("%p   %p",pb,pe);
			sort_min_max(pb,pe,&ppb,&ppe);
			//print_array(pb,pe);
			print_array(ppb, ppe);
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
            }
            fclose(f);
        }      
    }    
    return err;
}