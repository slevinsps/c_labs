#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "functions.h"
#include "io.h"
#include "binary_sort.h"
#include "defines.h"
    
int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b; 
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d));
    return d;
}

void equation(int *a, int *b, int n)
{
    for (int j = 0;j < n;j++)
    {
        b[j] = a[j];
    }
}

void print_results(int *a, int n)
{
    unsigned long long tb, te;
    unsigned long long t_mid;
    int b[n];
    t_mid = 0;
    int count = 100;
    int i = 0;        
    while (i < count)
    {
        equation(a, b, n);
        tb = tick();
        mysort(b, n, sizeof(int), compare_int);
        te = tick();
        if (te >= tb)
        {
            t_mid += (te - tb);
            i++;
        }
    }
    printf("mysort %d: %I64d\n", n, t_mid / count);
    
    t_mid = 0;
    i = 0;
    while (i < count)
    {
        equation(a, b, n);
        tb = tick();
        qsort(b, n, sizeof(int), compare_int);
        te = tick();
        if (te >= tb)
        {
            t_mid += (te - tb);
            i++;
        }
    }    
    printf("qsort %d: %I64d\n\n", n, t_mid / count);  
}

void test_sorts(int n, char c)
{
    int a[n];
    
    if (c == 'r')
    {
        for (int i = 0;i < n;i++)
        {
            a[i] = rand() % (100) + 1;
        }
        print_results(a, n);
    }
    if (c == 'v')
    {
        for (int i = 0;i < n;i++)
        {
            a[i] = i;
        }
        print_results(a, n);
    }
    if (c == 'u')
    {
        for (int i = 0;i < n;i++)
        {
            a[i] = n - i;
        }
        print_results(a, n);
    }
    if (c == 's')
    {
        for (int i = 0;i < n;i++)
        {
            a[i] = 5;
        }
        print_results(a, n);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    printf("В случайном порядке:\n");
    for (int i = 1;i < 10;i++)
    {
        test_sorts(i, 'r');
    }
    for (int i = 10;i <= 100;i += 10)
    {
        test_sorts(i, 'r');
    }
    
    /////////////////
    printf("\n-----------------------\nВ порядке возрастания:\n");
    for (int i = 1;i < 10;i++)
    {
        test_sorts(i, 'v');
    }
    for (int i = 10;i <= 100;i += 10)
    {
        test_sorts(i, 'v');
    }
    
    /////////////////
    printf("\n-----------------------\nВ порядке убывания:\n");
    for (int i = 1;i < 10;i++)
    {
        test_sorts(i, 'u');
    }
    for (int i = 10;i <= 100;i += 10)
    {
        test_sorts(i, 'u');
    }
    
    /////////////////
    printf("\n-----------------------\nОдинаковые значения:\n");
    for (int i = 1;i < 10;i++)
    {
        test_sorts(i, 's');
    }
    for (int i = 10;i <= 100;i += 10)
    {
        test_sorts(i, 's');
    }
}