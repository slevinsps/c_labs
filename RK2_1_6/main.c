#include <stdio.h>
#include <string.h>
#include <errno.h>

#define OK 0
#define INCORRECT_SIZE -1
#define ARRAY_EMPTY -2
#define INCORRECT_ELEMENT -3
 
int read_array(FILE *f, int *pb, int n)
{
	int *pe = pb;
	int err = OK;
	while(pe-pb<=n && fscanf(f,"%d",pe) == 1)
	{
		pe = pe + 1;
	}
	if (pe-pb < n)
		err = INCORRECT_ELEMENT;
	if (pe-pb == 0)
		err = ARRAY_EMPTY;
	return err;	
}

void replace(int *pb, int size)
{
	int replace_element;
	int flag = 0;
	while (flag == 0)
	{
		flag = 1;
		for (int i = 0; i < size-1; i++)
		{
			if ((*(pb + i) < 0 && *(pb + i+1) >= 0))
			{
				replace_element = *(pb + i);
				*(pb + i) = *(pb + i + 1);
				*(pb + i + 1) = replace_element;
				flag = 0;
			}
		}
	}
}

void print_array(FILE *f, int *pb, int size)
{
	for (int i = 0; i<size;i++)
	{
		printf("%d ",*(pb+i));
	}
}

int main(int argc, char** argv)
{
	int size;
	int err = OK;
	FILE *f;
	
	if(argc != 2)
	{
		fprintf(stderr,"main.exe <filename>");
	}
	else
	{
		f = fopen(argv[1],"r");
		if (f == NULL)
		{
			fprintf(stderr,"%s",strerror(errno));
		}
		else
		{
			if (fscanf(f,"%d",&size) != 1)
			{
				printf("Incorrect array size");
				err = INCORRECT_SIZE;
			}
			else
			{
				int a[size];
				int *pb =a;
				err = read_array(f,pb,size);
				switch(err)
				{
					case ARRAY_EMPTY:
					{
						printf("Array is empty");
						err = ARRAY_EMPTY;
						break;
					}
					case INCORRECT_ELEMENT:
					{
						printf("Incorrect element in array");
						err = INCORRECT_ELEMENT;
						break;
					}
					case OK:
					{
						replace(pb,size);
						print_array(stdout,pb,size);
					}
				}
			}
		}
		
	}
	return err;
}