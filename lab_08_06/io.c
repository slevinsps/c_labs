#include <stdio.h>
#include "defines.h"
#include "create_free_matrix.h"
        
int read_matrix(FILE *f,double ***matrix1,int *n1, int *m1)
{	
    int err = OK;
    if (fscanf(f,"%d %d",n1,m1)==2 && *n1>=0 && *m1>=0)
    {
		*matrix1 = allocate_matrix_row(*n1,*m1);
		if (matrix1)
		{
			for (int i = 0; i<*n1;i++)
			{
				for (int j = 0; j<*m1;j++)
				{
					if (feof(f) == 0 && fscanf(f,"%lf",&(*matrix1)[i][j]) != 1)
					{
						err = INVALID_NUMBER;
						break;
					}
				}
				if (err == INVALID_NUMBER)
				{
					free_matrix_rows(*matrix1,*n1);
					break;
				}
			}  
		}
		else
			err = MEMORY_ERROR;
    }    
    else
    {
        err = INVALID_ARGUMENT_MATRIX;
    }
    return err;
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