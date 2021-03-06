#include <stdlib.h>
    
#include "defines.h"

// Освобождение памяти почему-то не работает с 2мя звездами
void free_matrix_rows(double **data, int n)
{
    for (int i = 0;i < n; i++)
    {
        free((data)[i]);        
    }
    free(data);    
}
  
// Выделение памяти  
double **allocate_matrix_row(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*));
    if (!data)
        return NULL;
    for (int i = 0;i < n;i++)
    {
        data[i] = (double*)malloc(m * sizeof(double));
        if (!data[i])
        {
            free_matrix_rows(data, n);
            return NULL;
        } 
    }
    return data;
}
