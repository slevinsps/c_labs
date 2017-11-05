#include <stdio.h>
#include <math.h>
#include "func.h"
#include "io.h"

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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(matrix1[i][j] - matrix2[i][j]) > eps)
            {   
                return 0;
            }
        }    
    }
    return 1;
}

void test_sort_func(void)
{
    int k;
    {
        // 1 Сортировка в обратном порядке
        double actual_m[N][M] = {{7,8,9},{4,5,6},{1,2,3}};
        double expected_m[N][M] = {{1,2,3},{4,5,6},{7,8,9}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 3;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        sort_1(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 1 in sort function is passed\n");
        else
        {
            printf("Test 1 in sort function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 2 Сортировка одного элемента
        double actual_m[N][M] = { { 7 } };
        double expected_m[N][M] = { { 7 } };
        double *actual[N];
        double *expected[N];
        int n = 1;
        int m = 1;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        sort_1(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 2 in sort function is passed\n");
        else
        {
            printf("Test 2 in sort function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 3 Сортировка вещественных чисел
        double actual_m[N][M] = { { 2.15, 4.1}, { 1,17, 7.125 }, { 0.0, 6.898 } };
        double expected_m[N][M] = { { 2.15, 4.1}, { 0.0, 6.898 }, { 1,17, 7.125 } };
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 2;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        sort_1(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 3 in sort function is passed\n");
        else
        {
            printf("Test 3 in sort function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 4 Сортировка столбца чисел
        double actual_m[N][M] = { {6}, {5}, {8}, {0}, {7}, {-1} };
        double expected_m[N][M] = { {-1}, {0}, {5}, {6}, {7}, {8} };
        double *actual[N];
        double *expected[N];
        int n = 6;
        int m = 1;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        sort_1(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 4 in sort function is passed\n");
        else
        {
            printf("Test 4 in sort function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
}

void test_max_in_ugol(void)
{
    int k;
    {
        // 1 Искомый элемент в правом нижнем углу
        double actual_m[N][M] = {{1,2,3},{4,5,6},{7,8,9}};
        double expected_m[N][M] = {{9,7,8},{3,1,2},{6,4,5}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 3;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 1 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 1 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 2 Искомый элемент в левом нижнем углу
        double actual_m[N][M] = {{1,2,3,0},{4,5,6,0},{9,7,8,0}};
        double expected_m[N][M] = {{9,7,8,0},{1,2,3,0},{4,5,6,0}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 4;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 2 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 2 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 3 Искомый элемент в правом верхнем углу
        double actual_m[N][M] = {{1,2,3,10},{4,5,6,0},{9,7,8,0}};
        double expected_m[N][M] = {{10,1,2,3},{0,4,5,6},{0,9,7,8}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 4;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 3 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 3 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 4 Искомый элемент в левом верхнем углу
        double actual_m[N][M] = {{11,2,3,10},{4,5,6,0},{9,7,8,0}};
        double expected_m[N][M] = {{11,2,3,10},{4,5,6,0},{9,7,8,0}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 4;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 4 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 4 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 5 Искомый элемент в внутри матрицы
        double actual_m[N][M] = {{11,2,3,10},{4,5,66,0},{9,7,8,0}};
        double expected_m[N][M] = {{66,4,5,0},{3,11,2,10},{8,9,7,0}};
        double *actual[N];
        double *expected[N];
        int n = 3;
        int m = 4;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 5 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 5 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
    {
        // 6 В матрице один элемент
        double actual_m[N][M] = { { 0 } };
        double expected_m[N][M] = { { 0 } };
        double *actual[N];
        double *expected[N];
        int n = 1;
        int m = 1;
        array_into_pointer(actual_m, n, actual);
        array_into_pointer(expected_m, n, expected);
        
        max_in_ugol(actual, n, m);
        k = compare_matrix(actual, expected, n, m);
        
        if (k == 1)
            printf("Test 6 in max_in_ugol function is passed\n");
        else
        {
            printf("Test 6 in max_in_ugol function is failed\n");
            print_mat(stdout, actual, n, m);
        }
    }
}



int main(void)
{
    test_sort_func();
    test_max_in_ugol();
    return 0;
}