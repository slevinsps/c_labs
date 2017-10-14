#include <stdio.h>

#include "defines.h"
#include "create_free_matrix.h"
   
// Суммировние матриц   
int sum_matrix(double **matrix1, double **matrix2, int n1, int m1, int n2, int m2, double ***matrix3)
{
    if (n1 != n2 || m1 != m2)
		return DONT_EQUAL_SIZE;
	
	double **res = allocate_matrix_row(n1, m1);
	if (!res)
		return MEMORY_ERROR;
	*matrix3 = res;

	for (int i = 0; i < n1;i++)
	{
		for (int j = 0; j < m1;j++)
		{
			res[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
    return OK;
}