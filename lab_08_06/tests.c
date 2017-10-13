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
 
void sum_matrix_tests(void)
{
    int k;
    //1 Сложение матриц размера 3х4
    int n11 = 3,m11 = 4;
    double matrix11[3][4] = {{1, 2, 3, 7}, {4, 5, 6, 4}, {7, 8, 9, -8}};
    double *mat11[n11];
    for (int i = 0; i < m11; i++)
        mat11[i] = matrix11[i];
    
    int n21 = 3,m21 = 4;
    double matrix21[3][4] = {{-4, 2, 5, 2}, {3, 5, 2, 1}, {7, -1, 1, 0}};
    double* mat21[n21];
    for (int i = 0; i < m21; i++)
        mat21[i] = matrix21[i];
    
    double **actual1 = NULL;

    sum_matrix(mat11, mat21, n11, m11, n21, m21, &actual1);
    
    double expected1[3][4] = {{-3, 4, 8, 9}, {7, 10, 8, 5}, {14, 7, 10, -8}};
    
    k = 1;
    for (int i = 0; i < n11; i++)
    {
        for (int j = 0; j < m11; j++)
        if (actual1[i][j] != expected1[i][j])
            k = 0;
    }
    if (k == 1)
        printf("Test 1 in sum_matrix function is passed\n");
    else
    {
        printf("Test 1 in sum_matrix function is failed\n");
        print_matrix(stdout, actual1, n11, m21);
    } 
    //2 Сложение матриц размера 1х1
    int n12 = 1, m12 = 1;
    double matrix12[1][1] = {{5}};
    double *mat12[n11];
    for (int i = 0; i < m12; i++)
        mat12[i] = matrix12[i];
    
    int n22 = 1, m22 = 1;
    double matrix22[1][1] = {{3}};
    double *mat22[n22];
    for (int i = 0;i < m22;i++)
        mat22[i] = matrix22[i];
    
    double **actual2 = NULL;

    sum_matrix(mat12, mat22, n12, m12, n22, m22, &actual2);
    
    double expected2[1][1] = {{8}};
    
    k = 1;
    for (int i = 0; i < n12; i++)
    {
        for (int j = 0;j < m12;j++)
        if (actual2[i][j] != expected2[i][j])
            k = 0;
    }
    if (k == 1)
        printf("Test 2 in sum_matrix function is passed\n");
    else
    {
        printf("Test 2 in sum_matrix function is failed\n");
        print_matrix(stdout, actual2, n12, m22);
    } 
    
    //3 Матрицы имеют разный размер
    int n13 = 1, m13 = 1;
    double matrix13[1][1] = {{5}};
    double *mat13[n11];
    for (int i = 0; i < m13; i++)
        mat13[i] = matrix13[i];
    
    int n23 = 2, m23 = 2;
    double matrix23[2][2] = {{3, 2}, {8, -7}};
    double *mat23[n23];
    for (int i = 0; i < m23; i++)
        mat23[i] = matrix23[i];
    
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
    double eps = 0.0001;
    int k;
    //1 Умножение матриц размера 3х4 на 4х3
    int n11 = 3,m11 = 4;
    double matrix11[3][4] = {{1, 2, 3, 7}, {4, 5, 6, 4}, {7, 8, 9, -8}};
    double *mat11[n11];
    for (int i = 0;i < n11;i++)
        mat11[i] = matrix11[i];
    
    int n21 = 4,m21 = 3;
    double matrix21[4][3] = {{-4, 2, 5}, {3, 5, 2}, {7, -1, 1}, {4, 5, 3}};
    double *mat21[n21];
    for (int i = 0;i < n21;i++)
        mat21[i] = matrix21[i];
    
    double **actual1 = NULL;

    multiply_matrix(mat11, mat21, n11, m11, n21, m21, &actual1);
        
    double expected1[3][3] = {{51, 44, 33}, {57, 47, 48}, {27, 5, 36}};
    
    k = 1;
    for (int i = 0;i < n11;i++)
    {
        for (int j = 0;j < m21;j++)
        if (fabs(actual1[i][j] - expected1[i][j]) > eps)
            k = 0;
    }
    if (k == 1)
        printf("Test 1 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 1 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual1, n11, m21);
    } 
    //2 Умножение матриц одинакого размера 2х2 на 2х2
    int n12 = 2, m12 = 2;
    double matrix12[2][2] = {{1, 2}, {3, 4}};
    double *mat12[n11];
    for (int i = 0; i < m12; i++)
        mat12[i] = matrix12[i];
    
    int n22 = 2, m22 = 2;
    double matrix22[2][2] = {{1, 1}, {1, 1}};
    double *mat22[n22];
    for (int i = 0;i < m22;i++)
        mat22[i] = matrix22[i];
    
    double **actual2 = NULL;

    multiply_matrix(mat12, mat22, n12, m12, n22, m22, &actual2);
    
    double expected2[2][2] = {{3, 3}, {7, 7}};
    
    k = 1;
    for (int i = 0; i < n12; i++)
    {
        for (int j = 0; j < m12; j++)
        if (fabs(actual2[i][j] - expected2[i][j]) > eps)
            k = 0;
    }
    if (k == 1)
        printf("Test 2 in multiply_matrix function is passed\n");
    else
    {
        printf("Test 2 in multiply_matrix function is failed\n");
        print_matrix(stdout, actual2, n12, m22);
    } 
    
    //3 Матрицы имеют неподходящий размер
    int n13 = 1, m13 = 1;
    double matrix13[1][1] = {{5}};
    double *mat13[n11];
    for (int i = 0; i < m13; i++)
        mat13[i] = matrix13[i];
    
    int n23 = 2, m23 = 2;
    double matrix23[2][2] = {{3, 2}, {8, -7}};
    double *mat23[n23];
    for (int i = 0;i < m23;i++)
        mat23[i] = matrix23[i];
    
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
    double matrix14[1][1] = {{5}};
    double *mat14[n11];
    for (int i = 0; i < m14; i++)
        mat14[i] = matrix14[i];
    
    int n24 = 1, m24 = 1;
    double matrix24[2][2] = {{2}};
    double *mat24[n24];
    for (int i = 0; i < m24; i++)
        mat24[i] = matrix24[i];
    
    double **actual4 = NULL;

    multiply_matrix(mat14, mat24, n14, m14, n24, m24, &actual4);
    
    double expected4[1][1] = {{10}};
    
    k = 1;
    for (int i = 0; i < n14; i++)
    {
        for (int j = 0; j < m14; j++)
        if (fabs(actual4[i][j] - expected4[i][j]) > eps)
            k = 0;
    }
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
    int n11 = 3,m11 = 3;
    double matrix11[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    double *mat11[n11];
    for (int i = 0;i < m11;i++)
        mat11[i] = matrix11[i];
    
    double **actual1 = NULL;

    gauss(mat11,&actual1,n11,m11);
    
    double expected1[3][3] = {{(double)-2 / 3, (double)-4 / 3, 1}, {(double)-2 / 3, (double)11 / 3, -2}, {1, -2, 1}};
    
    k = 1;

    for (int i = 0;i < n11;i++)
    {
        for (int j = 0;j < m11;j++)
        {
            if (fabs(actual1[i][j] - expected1[i][j]) > 0.01)
                k = 0;
        }
    }
    if (k == 1)
        printf("Test 1 in gauss function is passed\n");
    else
    {
        printf("Test 1 in gauss function is failed\n");
        print_matrix(stdout, actual1, n11, m11);        
    } 
    
    //2 Вычисление обратной матрицы размера 1х1
    int n12 = 1, m12 = 1;
    double matrix12[1][1] = {{5}};
    double *mat12[n12];
    for (int i = 0; i < m12; i++)
        mat12[i] = matrix12[i];
    
    double **actual2 = NULL;

    gauss(mat12, &actual2, n12, m12);
    
    double expected2[1][1] = {{0.2}};
    
    k = 1;
    for (int i = 0; i < n12; i++)
    {
        for (int j = 0; j < m12; j++)
        {
            if (fabs(actual2[i][j] - expected2[i][j]) > 0.01)
                k = 0;
        }
    }
    if (k == 1)
        printf("Test 2 in gauss function is passed\n");
    else
    {
        printf("Test 2 in gauss function is failed\n");
        print_matrix(stdout, actual2, n12, m12);        
    }
    
    //3 Определитель матрицы равен 0
    int n13 = 3, m13 = 3;
    double matrix13[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double *mat13[n13];
    for (int i = 0;i < m13;i++)
        mat13[i] = matrix13[i];
    
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
    double matrix14[3][4] = {{1, 2, 3, 5}, {4, 5, 6, 7}, {7, 8, 9, -4}};
    double *mat14[n14];
    for (int i = 0; i < m14; i++)
        mat14[i] = matrix14[i];
    
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