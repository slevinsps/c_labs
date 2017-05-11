#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2

int sum_proizved(int* pb, int* pe)
{
	int sum = 0;
	int *left_border = pb;
	int *right_border = pe;
	while(pe>=left_border)
	{
		if (*left_border < 0)
		{
			while(right_border>=pb)
			{
				if (*right_border > 0)
				{
					sum += (*right_border)*(*left_border);
					right_border--;
					break;
				}
				right_border--;	
			}
		}			
		left_border++;
	}	
	return sum;
}

int main(int argc, char** argv)
{
	FILE *f;
	int a[100];
	int sum;
	int err = 0;
	int x;
	int k = 0;
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
				if (fscanf(f,"%d",&x) == 1)
				{
					*pb = x;
					*pe = x; 
					k++;
				}
				
				
				while((fscanf(f,"%d",&x) == 1) && (k <= 100))
				{
					pe++;
					*pe = x;
					k++;
				}
				sum = sum_proizved(pb, pe);
				printf("The sum of products of positive and negative elements = %d",sum);
			}
		}
	return err;
}
