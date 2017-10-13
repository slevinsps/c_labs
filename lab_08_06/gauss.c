#include <stdio.h>
#include <math.h>
    
#include "create_free_matrix.h"
#include "io.h"
#include "defines.h"

void creat_edin(double **edin, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        if (i == j)
            edin[i][j] = 1;
        else
            edin[i][j] = 0;
        }
    } 
}    

void gauss_divide(double *row,int number, double *chislo, int n1)
{
    double div = row[number];
    *chislo = *chislo / div; // изменение значения элемента единичной матрицы
    
    for (int i = 0; i < n1; i++)
    {
        row[i] = row[i] / div;
    }    
}

void subtraction(double *row1, double *row2, int number, double *chislo1, double *chislo2, int n1)
{
    double sub = row1[number];
    
    for (int i = 0;i < n1;i++)
    {
        row1[i] = row1[i] - sub * row2[i];
    }
    *chislo1 = *chislo1 - sub * (*chislo2); // изменение значения элемента единичной матрицы
}

int choos_not_zero_element(double ***matrix1,int column,int n,double **edin,int column_edin,double *arr_operations)
{    
    // функция меняет строки местами, для того, чтобы вверху оставался не нулевой элемент
    double eps = 0.000000000001;
    int err = OK;
    double k;
    int bool1 = 0;
    double *row;
    for(int i = column;i < n;i++)
    {
        if (fabs((*matrix1)[i][column]) > eps)
        {
            bool1 = 1;
            row = (*matrix1)[i];
            (*matrix1)[i] = (*matrix1)[column];
            (*matrix1)[column] = row;
            k = edin[i][column_edin];
            edin[i][column_edin] = edin[column][column_edin]; 
            edin[column][column_edin] = k;
            *arr_operations = i; // запись в массив операций
            break;
        }
    }
    if (!bool1)
    {
        err = DETERMINATE_0;
    }       
    return err;
}

int gauss(double **matrix1, double ***edin, int n1, int m1)
{
    /// Пытался сделать сохранение операций, чтоб с остальными стобцами просто применить их
    /// сделал это, но не уверен, что это сделало программу легче, хотелось бы услышать ваше мнение
    int err = OK;
    if (n1 == m1)    
    {
        double arr_operations[n1+n1*n1+n1]; // в этот массив сохраняются операции
        int k = -1;
        *edin =  allocate_matrix_row(n1, m1);
		if (*edin)
		{
			creat_edin(*edin, n1);
			//print_matrix(stdout,matrix1,n1,n1);
			//printf("\n");
			for (int j = 0;j < n1;j++)
			{            
				k++;
				err = choos_not_zero_element(&matrix1, j, n1, *edin, 0, &arr_operations[k]);
				//print_matrix(stdout,matrix1,n1,n1);
				//printf("выше выбор\n");
				if (err == DETERMINATE_0)
				{                
					break;                
				}
				else
				{
					k++;
					arr_operations[k] = matrix1[j][j];
					gauss_divide(matrix1[j], j, &(*edin)[j][0], n1);
					//print_matrix(stdout,matrix1,n1,n1);
					//printf("выше деление\n");
					for (int v = 0; v < n1; v++)
					{
						if (v != j)
						{
							k++;
							arr_operations[k] = matrix1[v][j];
							subtraction(matrix1[v], matrix1[j], j, &(*edin)[v][0], &(*edin)[j][0],  n1);        
							//print_matrix(stdout,matrix1,n1,n1);
							//printf("выше вычитание\n");
						}
					}
				}                    
			}
		}
		else		
		{
			err = MEMORY_ERROR;
		}
        if (err == OK)
        {
            double tmp;
            for (int i = 1; i < n1; i++)
            {
                k = 0;
                for (int j = 0; j < n1; j++)
                {
                    tmp = (*edin)[j][i];
                    
                    (*edin)[j][i] = (*edin)[(int)arr_operations[k]][i];
                    (*edin)[(int)arr_operations[k]][i] = tmp;
                    k++;
                    (*edin)[j][i] /= arr_operations[k];
                    k++;
                    for (int v = 0; v < n1; v++)
                    {
                        if (v != j)
                        {                            
                            (*edin)[v][i] -= arr_operations[k]*(*edin)[j][i];        
                            k++;
                        }
                    }    
                }    
            }    
        }    
    }    
    else
        err = DONT_EQUAL_SIZE;
    return err;
}