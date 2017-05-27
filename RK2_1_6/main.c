#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "read_array.h"
#include "replace.h"
#include "print_array.h"
#include "defines.h"

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
			fclose(f);		
		}				
	}
	return err;
}