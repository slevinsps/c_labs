#include "defines.h"
#include "create_free_matrix.h"

int multiply_matrix(double **matrix1, double **matrix2, int n1, int m1, int n2, int m2, double ***matrix3)
{
    if (m1 != n2)
		return DONT_RIGHT_SIZE;
	
	double** res = allocate_matrix_row(n1, m2);
	if (!res)
		return MEMORY_ERROR;
	*matrix3 = res;
   
	for (int ii = 0; ii < n1; ii++)
	{
		for (int i = 0; i < m2; i++)
		{
			res[ii][i] = 0;
			for (int j = 0; j < n2; j++)
			{
				res[ii][i] += matrix1[ii][j] * matrix2[j][i];
			}
		}        
	}  
    return OK;
}