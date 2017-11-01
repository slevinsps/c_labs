#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "free_all.h"

int read_matrix(FILE *f,double ***res, int *n,int *m)
{
	if (fscanf(f,"%d %d",n,m) == 2)
	{
		*res = allocate(*n, *m);
		if (!*res)
			return MEMORY_ERROR;
		for (int i = 0; i < *n; i++ )
		{
			for (int j = 0; j < *m; j++ )
			{
				if (fscanf(f,"%lf",&((*res)[i][j])) != 1)
				{
					return INVALI_NUMBER;
				}
				
			}
		}
	}
	else
	{
		return INVALID_SIZE;
	}
	return OK;
}

void print_mat(double **matrix, int n,int m) 
{
	for (int i = 0; i < n; i++ )
	{
		for (int j = 0; j < m; j++ )
		{
			printf("%f ",matrix[i][j]);
		}
		printf("\n");
	} 	
	
}