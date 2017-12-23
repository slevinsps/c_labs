#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"
#include "io.h"
#include "binary_sort.h"
#include "defines.h"  
      
void count_numbers_tests(void)
{
    FILE * f1, * f2, * f3;
    float expected, actual;
    //1 в файле различные числа
    f1 = fopen("count_numbers_test1.txt", "r");
    expected = 9;
    actual = count_numbers(f1);
    if (actual == expected)
        printf("Test 1 in count_number function is passed\n");
    else
    {
        printf("Test 1 in count_number function is failed:\n    expected = %f, actual = %f\n", expected, actual);
    }
    fclose(f1);
    //2 В файле 1 число
    f2 = fopen("count_numbers_test2.txt", "r");
    expected = 1;
    actual = count_numbers(f2);
    if (actual == expected)
        printf("Test 2 in count_number function is passed\n");
    else
    {
        printf("Test 2 in count_number function is failed:\n    expected = %f, actual = %f\n", expected, actual);
    }
    fclose(f2);
    //3 В файле есть буква
    f3 = fopen("count_numbers_test3.txt", "r");
    expected = 0;
    actual = count_numbers(f3);
    if (actual == expected)
        printf("Test 3 in count_number function is passed\n");
    else
    {
        printf("Test 3 in count_number function is failed:\n    expected = %f, actual = %f\n", expected, actual);    
    }
    fclose(f3);
}

void swap_tests(void)
{
    int a = 6, b = 7;
    float a1 = 1.15, b1 = 6.25;
    double a2 = 5.5, b2 = 4.32;
    double expected1, expected2, actual1, actual2;
    //1 Обмен значениями целочисленных переменных
    swap(&a, &b, sizeof(int));
    expected1 = 7;
    expected2 = 6;
    actual1 = a;
    actual2 = b;
    if (actual1 == expected1 && actual2 == expected2)
        printf("Test 1 in swap function is passed\n");
    else
    {
        printf("Test 1 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n", expected1, expected2, actual1, actual2);
    }
    //2 Обмен значениями переменных типа float
    swap(&a1, &b1, sizeof(float));
    expected1 = 6.25;
    expected2 = 1.15;
    actual1 = a1;
    actual2 = b1;
    if (fabs(actual1 - expected1) < 0.0001 && fabs(actual2 - expected2) < 0.0001)
        printf("Test 2 in swap function is passed\n");
    else
    {
        printf("Test 2 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n", expected1, expected2, actual1, actual2);
    }
    //3 Обмен значениями переменных типа double
    swap(&a2, &b2, sizeof(double));
    expected1 = 4.32;
    expected2 = 5.5;
    actual1 = a2;
    actual2 = b2;
    if (fabs(actual1 - expected1) < 0.0001 && fabs(actual2 - expected2) < 0.0001)
        printf("Test 3 in swap function is passed\n");
    else
    {    
        printf("Test 3 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n", expected1, expected2, actual1, actual2);
    }   
}
    
int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    if (*a - *b >= 0)
    {
        return 1; 
    }
    return -1;
}

int compare_float(const void *p, const void *q)
{
    const float *a = p;
    const float *b = q;
    if (*a - *b >= 0)
    {
        return 1; 
    }
    return -1; 
}

int compare_double(const void *p, const void *q)
{
    const double *a = p;
    const double *b = q;
    if (*a - *b >= 0)
    {
        return 1; 
    }
    return -1;
}

void mysort_tests(void)
{
    int *pb;
    int k = 1;
    //1 Сортировка целочисленных элементов
    int a[9] = { 8, 2, 0, 1, 5, 7, 2, -1, 3 };
    int a1[9] = { -1, 0, 1, 2, 2, 3, 5, 7, 8 };
    pb = a;
    mysort(pb, 9, sizeof(int), compare_int);
    for (int i = 0;i < 9;i++)
    {
        if (a[i] != a1[i])
            k = 0;
    }
    if (k == 1)
        printf("Test 1 in mysort function is passed\n");
    else
    {
        printf("Test 1 in mysort function is failed\n");
    } 
    //2 Сортировка элементов типа float
    float *pb1;
    k = 1;
    float b[6] = { 2.6, -1.23, 0, 2.5, 0,1 };
    float b1[6] = { -1.23, 0, 0, 1, 2.5, 2.6 } ;
    pb1 = b;
    mysort(pb1, 6, sizeof(float), compare_float);
    for (int i = 0;i < 6;i++)
    {
        if (fabs(b[i] - b1[i]) > 0.001)
            k = 0;
    }
    if (k == 1)
        printf("Test 2 in mysort function is passed\n");
    else
    {
        printf("Test 2 in mysort function is failed\n");
    } 
    //3 Сортировка элементов типа double
    double *pb2;
    k = 1;
    double c[5] = { 2.5, -1.23, 0, 0, 1 };
    double c1[5] = { -1.23, 0, 0, 1, 2.5 };
    pb2 = c;
    mysort(pb2, 5, sizeof(double), compare_double);
    for (int i = 0;i < 5;i++)
    {
        if (fabs(c[i] - c1[i]) > 0.001)
            k = 0;
    }
    if (k == 1)
        printf("Test 3 in mysort function is passed\n");
    else
    {
        printf("Test 3 in mysort function is failed\n");
    } 
    
    //4 Сортировка одного элемента
    int *pb3;
    int d[1] = { 8 };
    int d1[1] = { 8 };
    k = 1;
    pb3 = d;
    mysort(pb3, 1, sizeof(int), compare_int);
    for (int i = 0;i < 1;i++)
    {
        if (d[i] != d1[i])
            k = 0;
    }
    if (k == 1)
        printf("Test 4 in mysort function is passed\n");
    else
    {
        printf("Test 4 in mysort function is failed\n");
    }
    
    //5 Сортировка двух элементов
    int *pb4;
    int e[2] = { 8, -1 };
    int e1[2] = { -1, 8 };
    k = 1;
    pb4 = e;
    mysort(pb4, 2, sizeof(int), compare_int);
    for (int i = 0;i < 2;i++)
    {
        if (e[i] != e1[i])
            k = 0;
    }
    if (k == 1)
        printf("Test 5 in mysort function is passed\n");
    else
    {
        printf("Test 5 in mysort function is failed\n");
    }
    
    //5 Сортировка элементов расположенных в правильном порядке
    int *pb5;
    int f[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int f1[7] = { 1, 2, 3, 4, 5, 6, 7 };
    k = 1;
    pb5 = f;
    mysort(pb5, 7, sizeof(int), compare_int);
    for (int i = 0;i < 7;i++)
    {
        if (f[i] != f1[i])
            k = 0;
    }
    if (k == 1)
        printf("Test 6 in mysort function is passed\n");
    else
    {
        printf("Test 6 in mysort function is failed\n");
    }
}
    
void read_array_tests(void)
{
    FILE * f1, * f2, * f3, * f4, * f5;
    f1 = fopen("read_test1.txt", "r");
    f2 = fopen("read_test2.txt", "r");
    f3 = fopen("read_test3.txt", "r");
    f4 = fopen("read_test4.txt", "r");
    f5 = fopen("read_test5.txt", "r");

    int a1[5];
    int a11[5] = { 2, -4, 5, 1, 0 };
    int a2[2];
    int a22[1] = { 8 };
    int a3[1];
    int a4[3];
    int a44[3] = { 1, 2, 3 };
    int a5[4];
    int a55[4] = { 2, 2, 2, 2 };
    int counter;
    int *pb, *pe;

    // Считывание пяти элементов, в файле пять элементов
    pb = a1;
    pe = a1;
    read_array(f1, pb, &pe, 5);
    fclose(f1);
    counter = 0;
    for (int i = 0;i < 5;i++)
    {
        if (a1[i] != a11[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 1 in read_array function is failed\n");
    }
    else
    {
        printf("Test 1 in read_array function is passed\n");       
    }

    // Считывание одного элемента, в файле один элемент
    pb = a2;
    pe = a2;
    read_array(f2, pb, &pe, 1);
    fclose(f2);
    counter = 0;
    for (int i = 0;i < 1;i++)
    {
        if (a2[i] != a22[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 2 in read_array function is failed\n");
    }
    else
    {
        printf("Test 2 in read_array function is passed\n");       
    }

    // Файл пустой
    pb = a3;
    pe = a3;
    int err = read_array(f3, pb, &pe, 6);
    fclose(f3);
    if (err == FILE_EMPTY)
    {
        printf("Test 3 in read_array function is passed\n");
    }
    else
    {
        printf("Test 3 in read_array function is failed\n");
    }
    
    // Считывание трех элементов, в файле пять элементов
    pb = a4;
    pe = a4;
    err = read_array(f4, pb, &pe, 3);
    fclose(f4);
    counter = 0;
    for (int i = 0;i < 1;i++)
    {
        if (a4[i] != a44[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 4 in read_array function is failed\n");
    }
    else
    {
        printf("Test 4 in read_array function is passed\n");       
    }
    
    // Считывание четырех элементов, в файле в файле на месте 5-го элемента стоит буква
    pb = a5;
    pe = a5;
    err = read_array(f5, pb, &pe, 3);
    fclose(f5);
    counter = 0;
    for (int i = 0;i < 1;i++)
    {
        if (a5[i] != a55[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 5 in read_array function is failed\n");
    }
    else
    {
        printf("Test 5 in read_array function is passed\n");       
    }
}

void key_tests(void)
{
    int k;
    int *new_begin;
    int *new_end;
    
    //1 Между минимальным и максимальным находится несколько значений
    k = 1;
    int a1[9] = { 8, 2, 0, 1, 5, 7, 2, -1, 3 };
    int b1[6] = { 2, 0, 1, 5, 7, 2 };
    key(a1, a1 + 9, &new_begin, &new_end);
    for (int i = 0;i < new_end - new_begin;i++)
    {
        if (b1[i] != new_begin[i])
            k = 0;
    }
    if (k == 1)
        printf("Test 1 in key function is passed\n");
    else
    {
        printf("Test 1 in key function is failed\n");
    } 
    free(new_begin);
    //2 Между минимальным и максимальным находится одно значение
    k = 1;
    int a2[9] = { 8, 2, 0, 1, 5, 7, 2, 5, 3 };
    int b2[1] = { 2 };
    key(a2, a2 + 9, &new_begin, &new_end);
    for (int i = 0;i < new_end - new_begin;i++)
    {
        if (b2[i] != new_begin[i])
            k = 0;
    }    
    if (k == 1)
        printf("Test 2 in key function is passed\n");
    else
    {
        printf("Test 2 in key function is failed\n");
    } 
    free(new_begin);
    //3 Между минимальным и максимальным нет значений
    k = 1;
    int err;
    int a3[8] = { 1, -1, 8, 4, 5, 6, 7, 3 };
    err = key(a3, a3 + 8, &new_begin, &new_end);
    if (err == ARRAY_EMPTY)
        printf("Test 3 in key function is passed\n");
    else
    {
        printf("Test 3 in key function is failed\n");
        free(new_begin);
    } 
    //2 Несколько минимальных и максимальных значений
    k = 1;
    int a4[7] = { 1, 1, 1, 2, 8, 8, 8 };
    int b4[3] = { 1, 1, 2 };
    key(a4, a4 + 7, &new_begin, &new_end);
    for (int i = 0;i < new_end - new_begin;i++)
    {
        if (b4[i] != new_begin[i])
            k = 0;
    }    
    if (k == 1)
        printf("Test 4 in key function is passed\n");
    else
    {
        printf("Test 4 in key function is failed\n");
    } 
    free(new_begin);   
}
    
    
void print_array_test(void)
{
    FILE * f1, * f2;
    f1 = fopen("print_test1.txt", "w");
    f2 = fopen("print_test2.txt", "w");

    int a1[5];
    int a11[5] = { 2, -4, 5, 1, 0 };
    int a2[2];
    int a22[1] = { 8 };
   
    int counter;
    int *pb, *pe;

    // Печать 5-и элементов
    pb = a11;
    pe = a11 + 5;
    print_array(pb, pe, f1);
    fclose(f1);
    pb = a1;
    pe = a1;
    f1 = fopen("print_test1.txt", "r");
    read_array(f1, pb, &pe, 5);
    counter = 0;
    for (int i = 0;i < 5;i++)
    {
        if (a1[i] != a11[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 1 in print_array function is failed\n");
    }
    else
    {
        printf("Test 1 in print_array function is passed\n");       
    }

    // Печать 1-ого элемента
    pb = a22;
    pe = a22 + 1;
    print_array(pb, pe, f2);
    fclose(f2);
    pb = a2;
    pe = a2;
    f2 = fopen("print_test2.txt", "r");
    read_array(f2, pb, &pe, 1);
    counter = 0;
    for (int i = 0;i < 1;i++)
    {
        if (a2[i] != a22[i])
        {
            counter = 1;
        }
    }
    if (counter == 1)
    {
        printf("Test 2 in print_array function is failed\n");
    }
    else
    {
        printf("Test 2 in print_array function is passed\n");       
    }
}
    
int main(void)
{
    count_numbers_tests();
    swap_tests();
    key_tests();
    mysort_tests();
    read_array_tests();
    print_array_test();
    return 0;
}