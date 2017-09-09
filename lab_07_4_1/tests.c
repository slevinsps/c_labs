#include <stdio.h>
#include <math.h>
#include "functions.h"
    

void count_numbers_tests(void)
{
	FILE *f1, *f2, *f3, *f4;
    float expected, actual;
    // Tests count_numbers function
    // Test 1
	f1 = fopen("in_1.txt", "r");
    expected = 9;
    actual = count_numbers(f1);
    if (actual == expected)
        printf("Test 1 in polovin_del function is passed\n");
    else
	{
        printf("Test 1 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    }
	fclose(f1);
	// Test 2
    f2 = fopen("in_2.txt", "r");
    expected = 1;
    actual = count_numbers(f2);
    if (actual == expected)
        printf("Test 2 in polovin_del function is passed\n");
    else
	{
        printf("Test 2 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    }
	fclose(f2);
	// Test 3
    f3 = fopen("in_3.txt", "r");
    expected = 8;
    actual = count_numbers(f3);
    if (actual == expected)
        printf("Test 3 in polovin_del function is passed\n");
    else
	{
        printf("Test 3 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);    
	}
	fclose(f3);
	// Test 4
    f4 = fopen("in_4.txt", "r");
    expected = 7;
    actual = count_numbers(f4);
    if (actual == expected)
        printf("Test 4 in polovin_del function is passed\n");
    else
    {
        printf("Test 4 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    }
	 fclose(f4);
}

void swap_tests(void)
{
	int a = 6, b = 7;
	float a1 = 1.15, b1 = 6.25;
	double a2 = 5.5, b2 = 4.32;
    double expected1,expected2, actual1,actual2;
    // Tests swap function
    // Test 1
	swap(&a,&b,sizeof(int));
    expected1 = 7;
	expected2 = 6;
    actual1 = a;
    actual2 = b;
    if (actual1 == expected1 && actual2 == expected2)
        printf("Test 1 in swap function is passed\n");
    else
	{
        printf("Test 1 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected1,expected2,actual1,actual2);
	}
	// Test 2
	swap(&a1,&b1,sizeof(float));
    expected1 = 6.25;
	expected2 = 1.15;
    actual1 = a1;
    actual2 = b1;
    if (fabs(actual1 - expected1) < 0.0001 && fabs(actual2 - expected2) < 0.0001)
        printf("Test 2 in swap function is passed\n");
    else
	{
        printf("Test 2 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected1,expected2,actual1,actual2);
	}
	// Test 3
	swap(&a2,&b2,sizeof(double));
    expected1 = 4.32;
	expected2 = 5.5;
    actual1 = a2;
    actual2 = b2;
    if (fabs(actual1 - expected1) < 0.0001 && fabs(actual2 - expected2) < 0.0001)
        printf("Test 3 in swap function is passed\n");
    else
	{	
		printf("Test 3 in swap function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected1,expected2,actual1,actual2);
	}
	
}


void search_min_max_tests(void)
{
	int *pb, *pe, *ppb;
	int n;
    double expected_ppb,expected_n, actual_ppb,actual_n;
    //Tests search_min_max function
    //Test 1
	int a[9] = {8,2,0,1,5,7,2,-1,3};
	pb = a;
	pe = pb + 9;
	search_min_max(pb,pe,&ppb,&n);
    expected_ppb = 2;
	expected_n = 6;
    actual_ppb = *ppb;
    actual_n = n;
    if (fabs(actual_ppb - expected_ppb) < 0.0001 && fabs(actual_n - expected_n) < 0.0001)
        printf("Test 1 in search_min_max function is passed\n");
    else
	{
        printf("Test 1 in search_min_max function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected_ppb,expected_n,actual_ppb,actual_n);
	} 
    //Test 2
	int b[9] = {8,2,0,1,5,7,2,5,3};
	pb = b;
	pe = pb + 9;
	search_min_max(pb,pe,&ppb,&n);
    expected_ppb = 2;
	expected_n = 1;
    actual_ppb = *ppb;
    actual_n = n;
    if (fabs(actual_ppb - expected_ppb) < 0.0001 && fabs(actual_n - expected_n) < 0.0001)
        printf("Test 2 in search_min_max function is passed\n");
    else
	{
        printf("Test 2 in search_min_max function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected_ppb,expected_n,actual_ppb,actual_n);
	} 
	//Test 3
	int c[8] = {1,3,3,4,5,6,7,8};
	pb = c;
	pe = pb + 8;
	search_min_max(pb,pe,&ppb,&n);
    expected_ppb = 3;
	expected_n = 6;
    actual_ppb = *ppb;
    actual_n = n;
    if (fabs(actual_ppb - expected_ppb) < 0.0001 && fabs(actual_n - expected_n) < 0.0001)
        printf("Test 3 in search_min_max function is passed\n");
    else
	{
        printf("Test 3 in search_min_max function is failed:\n    expected = %f; %f, actual = %f; %f\n",expected_ppb,expected_n,actual_ppb,actual_n);
	} 
}



int compare_int(const void* p, const void* q)
{
	const int *a = p;
	const int *b = q;
	return *a - *b; 
}

int compare_float(const void* p, const void* q)
{
	const float *a = p;
	const float *b = q;
	return *a - *b; 
}

int compare_double(const void* p, const void* q)
{
	const double *a = p;
	const double *b = q;
	return *a - *b; 
}
void binary_insert_tests(void)
{
	int *pb;
	int k = 1;
    //Tests binary_insert function
    //Test 1
	int a[9] = {8,2,0,1,5,7,2,-1,3};
	int a1[9] = {-1,0,1,2,2,3,5,7,8};
	pb = a;
	binary_insert(pb,9,sizeof(int),compare_int);
	for (int i = 0;i<9;i++)
	{
		if (a[i] != a1[i])
			k = 0;
	}
    if (k == 1)
        printf("Test 1 in binary_insert function is passed\n");
    else
	{
        printf("Test 1 in binary_insert function is failed\n");
	} 
    //Test 2
	float *pb1;
	k = 1;
	float b[3] = {2.5,-1.23,0};
	float b1[3] = {-1.23,0,2.5};
	pb1 = b;
	binary_insert(pb1,3,sizeof(float),compare_float);
	for (int i = 0;i<3;i++)
	{
		if (fabs(b[i] - b1[i])>0.001)
			k = 0;

	}
    if (k == 1)
        printf("Test 2 in binary_insert function is passed\n");
    else
	{
        printf("Test 2 in binary_insert function is failed\n");
	} 
	//Test 3
	double *pb2;
	k = 1;
	double c[5] = {2.5,-1.23,0,0,1};
	double c1[5] = {-1.23,0,0,1,2.5};
	pb2 = c;
	binary_insert(pb2,5,sizeof(double),compare_double);
	for (int i = 0;i<5;i++)
	{
		if (fabs(c[i] - c1[i])>0.001)
			k = 0;

	}
    if (k == 1)
        printf("Test 3 in binary_insert function is passed\n");
    else
	{
        printf("Test 3 in binary_insert function is failed\n");
	} 
}

int main(void)
{
    count_numbers_tests();
	swap_tests();
	search_min_max_tests();
	binary_insert_tests();
    return 0;
}