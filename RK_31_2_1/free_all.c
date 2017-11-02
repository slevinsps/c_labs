#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
void free_matrix(double **res,int n)    
{
    for (int i = 0; i < n;i++)
    {
        free(res[i]);
    }
    free(res);
}

double **allocate(int n, int m)
{
    double **res = calloc(n,sizeof(double*));
    if (!res)
        return NULL;
    for (int i = 0; i < n; i++ )
    {
        res[i] = malloc(m*sizeof(double));
        if (!res)
        {
            free_matrix(res,n);
            return NULL;
        }
    }
    return res;
}