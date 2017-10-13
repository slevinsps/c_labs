#include <stdio.h>
#include "defines.h"
#include "create_free_matrix.h"
        
int read_matrix(FILE *f,double ***matrix1,int *n1, int *m1)
{
    if (fscanf(f, "%d %d", n1, m1) != 2)
    {
        return -1;
    }
    if ((*n1 <= 0) || (*m1 <= 0))
    {
        return -2;
    }
	*matrix1 = allocate_matrix_row(*n1,*m1);
    for (int i = 0; i < *n1; i++)
    {
        for (int j = 0; j < *m1; j++)
        {
            if (fscanf(f, "%lf", &(*matrix1)[i][j]) != 1)
            {
                return -3;
            }
        }
    }
    return 0;
}

void print_matrix(FILE *f,double **matrix1,int n1, int m1)
{
	fprintf(f,"%d %d",n1,m1);
    for (int i = 0; i<n1;i++)
    {
		fprintf(f,"\n");
        for (int j = 0; j<m1;j++)
        {
            fprintf(f,"%f ",matrix1[i][j]);
        }       
    }
}