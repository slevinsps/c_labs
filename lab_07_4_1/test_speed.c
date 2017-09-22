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
    
int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b; 
}

unsigned long long tick(void)
{
 unsigned long long d;
 __asm__ __volatile__ ("rdtsc" : "=A" (d) );
 return d;
}
    
int main(int argc, char** argv)
{
    
    int a[10];
    int a1[100];
    int a2[1000];
    //int a3[10000];
    //int a4[100000]; 
    //int a5[1000000]; 
  
    unsigned long long tb, te;
    int n;
    unsigned long long t_mid;
    //int64_t t_mid;

    srand(time(NULL));
    
    
    n = 10;
    int b[n];
    printf("В случайном порядке:\n");
    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a[i] = rand() % (100)+1;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        binary_insert(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 10: %I64d\n", t_mid / 100);
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        qsort(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 10: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 100;
    int b1[n];

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a1[i] = rand() % (100)+1;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        binary_insert(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 100: %I64d\n", t_mid / 100);
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        qsort(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 100: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 1000;
    int b2[n];

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a2[i] = rand() % (100)+1;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        binary_insert(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 1000: %I64d\n", t_mid / 100);
    
  
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        qsort(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 1000: %I64d\n", t_mid / 100);
        
    /////////////////
    printf("\n\nВ порядке возрастания:\n");
    n = 10;
    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a[i] = i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        binary_insert(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 10: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        qsort(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 10: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 100;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a1[i] = i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        binary_insert(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 100: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        qsort(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 100: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 1000;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a2[i] = i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        binary_insert(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 1000: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        qsort(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 1000: %I64d\n", t_mid / 100);
    
    /////////////////
    printf("\n\nВ порядке убывания:\n");
    n = 10;
    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a[i] = n-i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        binary_insert(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 10: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        qsort(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 10: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 100;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a1[i] = n-i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        binary_insert(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 100: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        qsort(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 100: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 1000;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a2[i] = n-i;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        binary_insert(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 1000: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        qsort(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 1000: %I64d\n", t_mid / 100);
    
    /////////////////
    printf("\n\nОдинаковые значения:\n");
    n = 10;
    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a[i] = 5;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        binary_insert(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 10: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b[j] = a[j];
        }
        tb = tick();
        qsort(b,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 10: %I64d\n", t_mid / 100);
    /////////////////
    
    n = 100;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a1[i] = 5;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        binary_insert(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 100: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[j] = a1[j];
        }
        tb = tick();
        qsort(b1,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 100: %I64d\n", t_mid / 100);
    
    /////////////////
    n = 1000;

    t_mid = 0;
    for(int i = 0;i<n;i++)
    {
        a2[i] = 5;
    }
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        binary_insert(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("binary_insert 1000: %I64d\n", t_mid / 100);
    
    
    t_mid = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b2[j] = a2[j];
        }
        tb = tick();
        qsort(b2,n,sizeof(int),compare_int);
        te = tick();
        t_mid += (te - tb);
    }
    printf("qsort 1000: %I64d\n", t_mid / 100);
    /////////////////

}