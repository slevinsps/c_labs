#include "defines.h"
#include "create_free_matrix.h"

int multiply_matrix(double **matrix1, double **matrix2, int n1, int m1,int n2, int m2,double ***matrix3)
{
    int err = OK;
    if (m1 == n2)
    {
        *matrix3 = allocate_matrix_row(n1,m2);
		if (matrix3)
		{
			for (int ii = 0; ii<n1; ii++)
			{
				for (int i = 0; i<m2;i++)
				{
					(*matrix3)[ii][i] = 0;
					for (int j = 0; j<n2;j++)
					{
						(*matrix3)[ii][i] += matrix1[ii][j] * matrix2[j][i];
					}
				}        
			}  
		}
		else
		{
			err = MEMORY_ERROR;
		}
    }    
    else
        err = DONT_RIGHT_SIZE;
    return err;
}