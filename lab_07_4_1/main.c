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
#define ARRAY_EMPTY -5

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

void binary_insert(int *const pb,int *const pe)
{
	int n = pe - pb;
	int l,r,x,m;
	for (int i = 1; i<n; i++)
	{
		l = 0;
		r = i - 1;
		x = *(pb+i);
		while (l<=r)
		{
			m = (l+r)/2;
			if (*(pb+m)>x)
				r = m - 1;
			else
				l = m + 1;
		}
		for (int j = i-1; j>=l; j--)
		{
			*(pb+j+1) = *(pb+j);
		} 
		*(pb+l) = x;
	}
}

int sort_min_max(int *pb, int const *const pe, int **ppb, int **ppe)
{
    int n;
    int *k;    
    int *min = pb; 
    int *max = pb;
	int *a2;
    int err = 0;
	
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
	if (*ppe == *ppb)
    {
        err = ARRAY_EMPTY;
    }
	return err;
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
            if (err == FILE_EMPTY)
            {
                printf("File is empty");    
            }
            else
            {
                err = sort_min_max(pb,pe,&ppb,&ppe);
				if (err == ARRAY_EMPTY)
				{
					printf("Array is empty");    
				}
				else
				{
					binary_insert(ppb,ppe);
					print_array(ppb, ppe);
				}
            }
            fclose(f);
        }      
    }    
    return err;
}