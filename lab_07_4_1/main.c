#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_ITEMS 5  
#define OK 0
#define NO_FILE_1 -1
#define FILE_EMPTY -2
#define NOT_ALL_ARGUMENTS -3
#define NUMBER_ITEMS_EXCEEDED -4
#define ARRAY_EMPTY -5
#define INCORRECT_OUTPUT_NAME -6
#define INCORRECT_FILTER -7

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
	

    
    if (*pe == *pb)
    {
        err = FILE_EMPTY;
    }
    return err;        
}
  

void print_array(const int* pb,const int* pe,FILE *f)
{
	fprintf(f,"Sorted array:\n");
    while (pe>=pb)
    {
        fprintf(f,"%d ",*pb);
        pb = pb +1;
    }
    fprintf(f,"\n");
}

void swap(void *a, void *b,size_t size)                                                                                                                     
{
	size_t __size = (size);                                                      
	char *__a = (a), *__b = (b);
	for (int i=1;i<=__size;i++)
	{
		*__a = *__b;
		__a++;
		__b++;				
	}
}

 
 
void binary_insert(void * first, size_t number, size_t size,int (*compare)(const void*, const void*))
{
	int l,r,m;
	void *tmp;
	tmp = malloc(size);
	for (int i = 1; i<number; i++)
	{
		l = 0;
		r = i - 1;
		while (l<=r)
		{
			m = (l+r)/2;
			if (compare(((char*)first+m*size),((char*)first+i*size)))
				r = m - 1;
			else
				l = m + 1;
		}
		for (int j = i-1; j>=l; j--)
		{
			swap(tmp, ((char*)first + (j+1)*size), size);
            swap(((char*)first + (j+1)*size), ((char*)first + j*size), size);
            swap(((char*)first + j*size), tmp, size);
		} 
	}
}


int intSort(const void *a, const void *b) {
    return *((int*)a) > *((int*)b);
}
 
void search_min_max(int *pb, int const *const pe, int **ppb, int *n)
{
    int *k;  
    int *min = pb; 
    int *max = pb;
	*n = 0;
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
	*n = max-min-1;
	*ppb = min + 1;
}


int rewrite_array(int *min,int n,int **new_begin)
{
	int err = OK;
	int *new_end = *new_begin;
 	for(int i=1;i<=n;i++)
	{
		
		*new_end = *min;
		min = min + 1;
		new_end = new_end + 1;
	}	
	if (new_end == *new_begin)
    {
        err = ARRAY_EMPTY;
    }
	return err;
}


int compare_int(const void* p, const void* q)
{
	const int *a = p;
	const int *b = q;
	return *a - *b; 
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
				pb = a;
				pe = a;
				err = read_array(f1, &pb, &pe);
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
						new_begin = a2;
						err = rewrite_array(ppb,n,&new_begin);
						
						if (err == ARRAY_EMPTY)
						{
							fprintf(stderr,"Array is empty");    
						}
						else
						{
							binary_insert(new_begin,n,sizeof(int),intSort);
							print_array(new_begin, new_begin+n-1,f2);
						}
						free(a2);
					}
					else
					{
						if(pstr[0] == 'n' && pstr[1] == 0)
						{
							binary_insert(pb,pe-pb,sizeof(int),intSort);
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
				fclose(f2);
			}
			fclose(f1);
        }      
    }    
    return err;
}