#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "io.h"
#include "sum_matrix.h"
#include "multiply_matrix.h"
#include "gauss.h"
#include "create_free_matrix.h"
#include "defines.h"

#define N 20 
#define M 20 

void array_into_pointer(double matrix[][M], int n, double **mat)
{
    for (int i = 0; i < n; i++)
    {
        mat[i] = matrix[i];
    }
}

int compare_matrix(double **matrix1, double **matrix2, int n, int m)
{
    float eps = 0.0001;
    int tmp = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(matrix1[i][j] - matrix2[i][j]) > eps)
            {
                tmp = 0;    
                break;
            }
            if (tmp == 0)
                break;
        }    
    }
    return tmp;
}


void sum_matrix_tests(void)
{
    int k;
    //1 Сложение матриц размера 3х4
    int n11 = 3, m11 = 4;
    double matrix11[N][M] = { { 1, 2, 3, 7 }, { 4, 5, 6, 4 }, { 7, 8, 9, -8 } };
    double *mat11[n11];
    array_into_pointer(matrix11, n11, mat11);
   
    int n21 = 3, m21 = 4;
    double matrix21[N][M] = { { -4, 2, 5, 2 }, { 3, 5, 2, 1 }, { 7, -1, 1, 0 } };
    double *mat21[n21];
    array_into_pointer(matrix21, n21, mat21);
    
    double **actual1 = NULL;

    sum_matrix(mat11, mat21, n11, m11, n21, m21, &actual1);
    
    double expected1[N][M] = { { -3, 4, 8, 9 }, { 7, 10, 8, 5 }, { 14, 7, 10, -8 } };
    double *expect1[n11];
    array_into_pointer(expected1, n11, expect1);
    
    k = compare_matrix(expect1, actual1, n11, m11);
    if (k == 1)
        printf("Test 1 in sum_matrix function is passed\n");
    else
    {
        printf("Test 1 in sum_matrix function is failed\n");
        print_matrix(stdout, actual1, n11, m21);
    } 
    //2 Сложение матриц размера 1х1
    int n12 = 1, m12 = 1;
    double matrix12[N][M] = { { 5 } };
    double *mat12[n11];
    array_into_pointer(matrix12, n12, mat12);
    
    int n22 = 1, m22 = 1;
    double matrix22[N][M] = { { 3 } };
    double *mat22[n22];
    array_into_pointer(matrix22, n22, mat22);
    
    double **actual2 = NULL;

    sum_matrix(mat12, mat22, n12, m12, n22, m22, &actual2);
    
    double expected2[N][M] = { { 8 } };
    double *expect2[n12];
    array_into_pointer(expected2, n12, expect2);
    
    k = compare_matrix(expect2, actual2, n12, m12);
    if (k == 1)
        printf("Test 2 in sum_matrix function is passed\n");
    else
    {
        printf("Test 2 in sum_matrix function is failed\n");
        print_matrix(stdout, actual2, n12, m22);
    } 
    
    //3 Матрицы имеют разный размер
    int n13 = 1, m13 = 1;
    double matrix13[N][M] = { { 5 } };
    double *mat13[n11];
    array_into_pointer(matrix13, n13, mat13);
    
    int n23 = 2, m23 = 2;
    double matrix23[N][M] = { { 3, 2 }, { 8, -7 } };
    double *mat23[n23];
    array_into_pointer(matrix23, n23, mat23);
    
    double **actual3 = NULL;
    int err = OK;
    err = sum_matrix(mat13, mat23, n13, m13, n23, m23, &actual3);
    if (err == DONT_EQUAL_SIZE)
        printf("Test 3 in sum_matrix function is passed\n");
    else
    {
        printf("Test 3 in sum_matrix function is failed\n");
        print_matrix(stdout, actual3, n13, m23);
    } 
}


void multiply_matrix_tests(void)
{
    int k;
    //1 Умножение матриц размера 3х4 на 4х3
    int n11 = 3, m11 = 4;
    double matrix11[N][M] = { { 1, 2, 3, 7 }, { 4, 5, 6, 4 }, { 7, 8, 9, -8 } };
    double *mat11[n11];
    array_into_pointer(matrix11, n11, mat11);
    
    int n21 = 4, m21 = 3;
    double matrix21[N][M] = { { -4, 2, 5 }, { 3, 5, 2 }, { 7, -1, 1 }, { 4, 5, 3 } };
    double *mat21[n21];
    array_into_pointer(matrix21, n21, mat21);
    
    double **actual1 = NULL;

    multiply_matrix(mat11, mat21, n11, m11, n21, m21, &actual1);
        
    double expected1[N][M] = { { 51, 44, 33 }, { 57, 47, 48 }, { 27, 5, 36 } };
    
    double *expect1[n11];
    array_into_pointer(expected1, n11, expect1);
    
    k = compare_matrix(expect1, actual1, n11, n11);
    if (k == 1)
        printf("Test 1 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 1 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual1, n11, m21);
    } 
    //2 Умножение матриц одинакого размера 2х2 на 2х2
    int n12 = 2, m12 = 2;
    double matrix12[N][M] = { { 1, 2 }, { 3, 4 } };
    double *mat12[n11];
    array_into_pointer(matrix12, n12, mat12);
    
    int n22 = 2, m22 = 2;
    double matrix22[N][M] = { { 1, 1 }, { 1, 1 } };
    double *mat22[n22];
    array_into_pointer(matrix22, n22, mat22);
    
    double **actual2 = NULL;

    multiply_matrix(mat12, mat22, n12, m12, n22, m22, &actual2);
    
    double expected2[N][M] = { { 3, 3 }, { 7, 7 } };
    
    double *expect2[n12];
    array_into_pointer(expected2, n12, expect2);
    
    k = compare_matrix(expect2, actual2, n12, n12);
    if (k == 1)
        printf("Test 2 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 2 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual2, n12, m22);
    } 
    
    //3 Матрицы имеют неподходящий размер
    int n13 = 1, m13 = 1;
    double matrix13[N][M] = { { 5 } };
    double *mat13[n13];
    array_into_pointer(matrix13, n13, mat13);
    
    int n23 = 2, m23 = 2;
    double matrix23[N][M] = { { 3, 2 }, { 8, -7 } };
    double *mat23[n23];
    array_into_pointer(matrix23, n23, mat23);
    
    double **actual3 = NULL;
    int err = OK;
    err = multiply_matrix(mat13, mat23, n13, m13, n23, m23, &actual3);
    if (err == DONT_RIGHT_SIZE)
        printf("Test 3 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 3 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual2, n13, m23);
    }  
    //4 Умножение матриц 1х1 на 1х1
    int n14 = 1, m14 = 1;
    double matrix14[N][M] = { { 5 } };
    double *mat14[n14];
    array_into_pointer(matrix14, n14, mat14);
    
    int n24 = 1, m24 = 1;
    double matrix24[N][M] = { { 2 } };
    double *mat24[n24];
    array_into_pointer(matrix24, n24, mat24);
    
    double **actual4 = NULL;

    multiply_matrix(mat14, mat24, n14, m14, n24, m24, &actual4);
    
    double expected4[N][M] = { { 10 } };
    
    double *expect4[n14];
    array_into_pointer(expected4, n14, expect4);
    
    k = compare_matrix(expect4, actual4, n14, n14);
    if (k == 1)
        printf("Test 4 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 4 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual2, n14, m24);
    }
}

void gauss_tests(void)
{
    int k;
    //1 Вычисление обратной матрицы размера 3х3
    int n11 = 3, m11 = 3;
    double matrix11[N][M] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 10 } };
    double *mat11[n11];
    array_into_pointer(matrix11, n11, mat11);
    
    double **actual1 = NULL;

    gauss(mat11, &actual1, n11, m11);
    
    double expected1[N][M] = { { (double)-2 / 3, (double)-4 / 3, 1 }, { (double)-2 / 3, (double)11 / 3, -2 }, { 1, -2, 1 } };

    double *expect1[n11];
    array_into_pointer(expected1, n11, expect1);
    
    k = compare_matrix(expect1, actual1, n11, n11);

    if (k == 1)
        printf("Test 1 in gauss function is passed\n");
    else
    {
        printf("Test 1 in gauss function is failed\n");
        print_matrix(stdout, actual1, n11, m11);          
    } 
    
    //2 Вычисление обратной матрицы размера 1х1
    int n12 = 1, m12 = 1;
    double matrix12[N][M] = { { 5 } };
    double *mat12[n12];
    array_into_pointer(matrix12, n12, mat12);
    
    double **actual2 = NULL;

    gauss(mat12, &actual2, n12, m12);
    
    double expected2[N][M] = { { 0.2 } };
    
    k = 1;
    double *expect2[n12];
    array_into_pointer(expected2, n12, expect2);
    
    k = compare_matrix(expect2, actual2, n12, n12);
    if (k == 1)
        printf("Test 2 in gauss function is passed\n");
    else
    {
        printf("Test 2 in gauss function is failed\n");
        print_matrix(stdout, actual2, n12, m12);        
    }
    
    //3 Определитель матрицы равен 0
    int n13 = 3, m13 = 3;
    double matrix13[N][M] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    double *mat13[n13];
    array_into_pointer(matrix13, n13, mat13);
    
    double **actual3 = NULL;
    int err = OK;
    err = gauss(mat13, &actual3, n13, m13);

    if (err == DETERMINATE_0)
        printf("Test 3 in gauss function is passed\n");
    else
    {
        printf("Test 3 in gauss function is failed\n");
        printf("%d\n", err);
    } 
    
    //4 Некорректный размер матрицы
    int n14 = 3, m14 = 4;
    double matrix14[N][M] = { { 1, 2, 3, 5 }, { 4, 5, 6, 7 }, { 7, 8, 9, -4 } };
    double *mat14[n14];
    array_into_pointer(matrix14, n14, mat14);
    
    double **actual4 = NULL;
    err = OK;
    err = gauss(mat14, &actual4, n14, m14);

    if (err == DONT_EQUAL_SIZE)
        printf("Test 4 in gauss function is passed\n");
    else
    {
        printf("Test 4 in gauss function is failed\n");
        printf("%d\n", err);
    }
}

int main(void)
{
    sum_matrix_tests();
    multiply_matrix_tests();
    gauss_tests();
    return 0;
}