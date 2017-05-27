#include "replace.h"
#include "defines.h"

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