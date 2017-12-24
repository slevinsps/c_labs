#include <stdio.h>
#include <stdlib.h>
#include "func.h"


ARR_DLL int ARR_DECL fibonachi(int *array, int n)
{
	if (!array || n <= 0)
		return -1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			array[i] = 0;
		if (i == 1)
			array[i] = 1;
		if (i > 1)
			array[i] = array[i - 1] + array[i - 2];
	}
	return 0;
}

ARR_DLL int ARR_DECL move_elements(int *array1, int *array2, int n)
{
	if (!array1 || !array2 || n < 1)
		return -1;
	int counter = 0;
	int flag;
	for(int i = 0; i < n; i++)
	{
		flag = 1;
		for(int j = 0; j < counter; j++)
		{
			if (array2[j] == array1[i])
			{
				flag = 0;
				break;
			}				
		}
		if (flag)
		{
			array2[counter] = array1[i];
			counter++;
		}
	}
	return counter;
}	


int main(void)
{
	/* int n = 18;
	int *arr = malloc(n*sizeof(int));
	fidonachi(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	} */
	/* int arr1[6] = {5,1,1,1,1,1};
	int arr2[6] = {0,0,0,0,0,0};
	move_elements(arr1, arr2, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ",arr2[i]);
	} */
}