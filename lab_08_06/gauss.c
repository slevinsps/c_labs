#include <stdio.h>
#include <math.h>
#include <assert.h>
    
#include "create_free_matrix.h"
#include "io.h"
#include "defines.h"

// Заполняет единичную матрицу
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

// Делит строчку исходной матрицы на диагональный элемент матрицы
// также делит элемент столбца единичной матрицы

// double *row  -  строка матрицы
// int number  -  номер элемента строки, на который нужно делить
// double *chislo  -  элемент единичной матрицы
// int n1  -  размер матрицы

void gauss_divide(double *row, int number, double *chislo, int n1)
{
	assert(number >= 0);
    double div = row[number];
    *chislo = *chislo / div; // изменение значения элемента единичной матрицы
    
    for (int i = 0; i < n1; i++)
    {
        row[i] = row[i] / div;
    }    
}

// Вычитает одну строчку исходной матрицы из другой
// также вычитает один элемент столбца единичной матрицы из другого

// double *row1  - 1ая строка матрицы
// double *row2  - 2ая строка матрицы
// int number  -  номер элемента строки, на который нужно умножить строку
// double *chislo1  -  1ый элемент единичной матрицы
// double *chislo2  -  2ой элемент единичной матрицы
// int n1  -  размер матрицы

void subtraction(double *row1, double *row2, int number, double *chislo1, double *chislo2, int n1)
{
	assert(number >= 0);
    double sub = row1[number];
    
    for (int i = 0;i < n1;i++)
    {
        row1[i] = row1[i] - sub * row2[i];
    }
    *chislo1 = *chislo1 - sub * (*chislo2); // изменение значения элемента единичной матрицы
}

// Меняет строки местами, для того, чтобы вверху оставался не нулевой элемент,
// также меняет местами элемент столбца единичной матрицы
// также здесь происходит проверка на нулевой определитель, смысл в том,
// что если внизу нет больше таких строк, с ненулевым элементом, то значит, что определитель равен нулю

// double **matrix1  - матрица
// int column - номер столбца
// int number  -  номер элемента строки, на который нужно умножить строку
// int n  -  размер матрицы
// double **edin  -  единичная матрица
// int column_edin  -  номер столбца единичной матрицы
// double *arr_operations  -  массив операций

int choos_not_zero_element(double **matrix1, int column, int n, double **edin, int column_edin, double *arr_operations)
{    
    double eps = 0.000000001;
    int err = OK;
    double k;
    double *row;
	int max_i = column;
    for (int i = column; i < n; i++)
    {
        if (matrix1[i][column] > matrix1[max_i][column])
			max_i = i;
    }
	if (fabs(matrix1[max_i][column]) > eps)
    {
        row = matrix1[max_i];
        matrix1[max_i] = matrix1[column];
        matrix1[column] = row;
	
        k = edin[max_i][column_edin];
        edin[max_i][column_edin] = edin[column][column_edin]; 
        edin[column][column_edin] = k;
	
        *arr_operations = max_i; // запись в массив операций
    }
	else
		err = DETERMINATE_0;     
    return err;
}

// Главная функция
int gauss(double **matrix1, double ***edin, int n1, int m1)
{
    /// Пытался сделать сохранение операций, чтоб с остальными стобцами просто применить их
    /// сделал это, но не уверен, что это сделало программу легче, хотелось бы услышать ваше мнение
    int err = OK;
    if (n1 == m1)    
    {
        double arr_operations[n1 + n1 * n1]; // в этот массив сохраняются операции (два цикла, вложеных n1*n1 + максимальное количество перестановок n1)
        int k = -1;
        *edin = allocate_matrix_row(n1, m1); // создание единичной матрицы
        if (*edin)
        {
            creat_edin(*edin, n1);
            //print_matrix(stdout,matrix1,n1,n1);
            //printf("\n");
            for (int j = 0;j < n1;j++)
            {            
                k++;
                err = choos_not_zero_element(matrix1, j, n1, *edin, 0, &arr_operations[k]);
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
                            subtraction(matrix1[v], matrix1[j], j, &(*edin)[v][0], &(*edin)[j][0], n1);        
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
                            (*edin)[v][i] -= arr_operations[k] * (*edin)[j][i];        
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