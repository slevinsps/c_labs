#include <stdio.h>
#include "print_array.h"
#include "defines.h"

void print_array(FILE *f, int *pb, int size)
{
	for (int i = 0; i<size;i++)
	{
		printf("%d ",*(pb+i));
	}
}
