#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
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
    int n;
	int a[10];
    int a1[100];
    int a2[1000];
    int a3[10000];
    int a4[100000];
    //int a5[1000000]; 
  
    unsigned long long tb, te;
    srand(time(NULL));
	
	
	n = 10;
    for(int i = 0;i<n;i++)
    {
        a[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 10: %I64d\n", (te - tb) / n);
    
    
    for(int i = 0;i<n;i++)
    {
        a[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 10: %I64d\n", (te - tb) / n);
    
    
    /////////////////
	
    n = 100;
    for(int i = 0;i<n;i++)
    {
        a1[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 100: %I64d\n", (te - tb) / n);
    
    
    for(int i = 0;i<n;i++)
    {
        a1[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a1,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 100: %I64d\n", (te - tb) / n);
    
    
    /////////////////
    
    
    n = 1000;
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a2[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a2,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 1000: %I64d\n", (te - tb) / n);
    
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a2[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a2,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 1000: %I64d\n", (te - tb) / n);
    
    //////////////////////
    
    
    n = 10000;
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a3[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a3,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 10000: %I64d\n", (te - tb) / n);
    
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a3[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a3,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 10000: %I64d\n", (te - tb) / n);
    
    //////////////////////
    
    n = 100000;
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a4[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a4,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 100000: %I64d\n", (te - tb) / n);
    
    
    //srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a4[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a4,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 100000: %I64d\n", (te - tb) / n);
    
    /*
    
    ////////////////////////
    
    n = 1000000;
    srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a5[i] = rand() % (100)+1;
    }
    tb = tick();
    //qsort(a1,n,sizeof(int),compare_int);
    binary_insert(a5,n,sizeof(int),compare_int);
    te = tick();
    printf("binary_insert 1000000: %I64d\n", (te - tb) / n);
    
    srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        a5[i] = rand() % (100)+1;
    }
    tb = tick();
    qsort(a5,n,sizeof(int),compare_int);
    //binary_insert(a1,n,sizeof(int),compare_int);
    te = tick();
    printf("qsort 1000000: %I64d\n", (te - tb) / n); */
    
}