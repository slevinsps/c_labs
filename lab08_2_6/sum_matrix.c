#include "defines.h"
#include "create_free_matrix.h"
    
int sum_matrix(double **matrix1, double **matrix2, int n1, int m1,int n2, int m2,double ***matrix3)
{
    int err = OK;
    if (n1 == n2 && m1 == m2)
    {
        *matrix3 = allocate_matrix_row(n1,m1);
        for (int i = 0; i<n1;i++)
        {
            for (int j = 0; j<m1;j++)
            {
                (*matrix3)[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    else
    {
        err = DONT_EQUAL_SIZE;
    }    
    return err;
}