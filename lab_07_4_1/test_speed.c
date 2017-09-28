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


void print_results(int *a, int n)
{
    unsigned long long tb, te;
    unsigned long long t_mid;
    int b[n];
    t_mid = 0;
    int count = 100;
    for (int i = 0;i < count;i++)
    {
        for (int j = 0;j < n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        mysort(b, n, sizeof(int), compare_int);
        te = tick();
        if (te >= tb)
        {
            t_mid += (te - tb);
        }
        else
            count--;
    }
    printf("mysort %d: %I64d\n", n, t_mid / count);
    
    t_mid = 0;
    for (int i = 0;i < count;i++)
    {
        for (int j = 0;j < n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        qsort(b, n, sizeof(int), compare_int);
        te = tick();
        if (te >= tb)
        {
            t_mid += (te - tb);
        }
        else
            count--;
    }    
    printf("qsort %d: %I64d\n", n, t_mid / count);  
}

int main(int argc, char **argv)
{
    int a[10];
    int a1[100];
    int a2[1000];
    int n;

    srand(time(NULL));
    printf("В случайном порядке:\n");
    n = 10;
    for (int i = 0;i < n;i++)
    {
        a[i] = rand() % (100) + 1;
    }
    print_results(a, n);

    n = 100;
    for (int i = 0;i < n;i++)
    {
        a1[i] = rand() % (100) + 1;
    }
    print_results(a1, n);

    n = 1000;

    for (int i = 0;i < n;i++)
    {
        a2[i] = rand() % (100) + 1;
    }
    print_results(a2, n);
        
    /////////////////
    printf("\n\nВ порядке возрастания:\n");
    n = 10;
    for (int i = 0;i < n;i++)
    {
        a[i] = i;
    }
    print_results(a, n);

    n = 100;

    for (int i = 0;i < n;i++)
    {
        a1[i] = i;
    }
    print_results(a1, n);

    n = 1000;

    for (int i = 0;i < n;i++)
    {
        a2[i] = i;
    }
    print_results(a2, n);
    
    /////////////////
    printf("\n\nВ порядке убывания:\n");
    n = 10; 

    for (int i = 0;i < n;i++)
    {
        a[i] = n - i;
    }
    print_results(a,n);
    
    n = 100;

    for (int i = 0;i < n;i++)
    {
        a1[i] = n - i;
    }
    print_results(a1, n);

    n = 1000;

    for (int i = 0;i < n;i++)
    {
        a2[i] = n - i;
    }
    print_results(a2, n);
    
    /////////////////
    printf("\n\nОдинаковые значения:\n");
    n = 10;
    for (int i = 0;i < n;i++)
    {
        a[i] = 5;
    }
    print_results(a, n);

    n = 100;

    for (int i = 0;i < n;i++)
    {
        a1[i] = 5;
    }
    print_results(a1, n);

    n = 1000;

    for (int i = 0;i < n;i++)
    {
        a2[i] = 5;
    }
    print_results(a2, n);
}