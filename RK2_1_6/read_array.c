#include <stdio.h>
#include "read_array.h"
#include "defines.h"
 
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