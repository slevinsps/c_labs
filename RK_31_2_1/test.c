#include <stdio.h>
#include "func.h"
#include "io.h"

int test_sort1(void)
{
	double mat[3][3] = {{7,8,9},{1,2,3},{4,5,6}};
	double right[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	double *matrix[3];
	int n = 3;
	int m = 3;
	for (int i = 0 ; i < n; i++)
	{
		matrix[i] = mat[i];
	}
	sort_1(matrix, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != right[i][j])
			{
				printf("sort FAILED\n");
				return -1;
			}
		}
	}
	printf("sort PASSED\n");
	return 0;
}


int test_sort2(void)
{
	double mat[3][4] = {{7,8,9,9},{0,0,0,0},{4,5,6,0}};
	double right[3][4] = {{0,0,0,0},{4,5,6,0},{7,8,9,9}};
	double *matrix[3];
	int n = 3;
	int m = 4;
	for (int i = 0 ; i < n; i++)
	{
		matrix[i] = mat[i];
	}
	sort_1(matrix, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != right[i][j])
			{
				printf("sort FAILED\n");
				return -1;
			}
		}
	}
	printf("sort PASSED\n");
	return 0;
}

int test_perest1(void)
{
	double mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	double right[3][3] = {{9,7,8},{3,1,2},{6,4,5}};
	double *matrix[3];
	int n = 3;
	int m = 3;
	for (int i = 0 ; i < n; i++)
	{
		matrix[i] = mat[i];
	}
	max_in_ugol(matrix, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != right[i][j])
			{
				printf("perest FAILED\n");
				print_mat(matrix,n, m);
				return -1;
			}
		}
	}
	printf("perest PASSED\n");
	return 0;
}


int main(void)
{

    test_sort1();
	test_sort2();
	test_perest1();
	return 0;
}