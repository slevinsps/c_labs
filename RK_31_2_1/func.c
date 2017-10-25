#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
int srednee(double *res, int m)
{
	double sr = 0.0;
	for (int i = 0; i < m; i++)
	{
		sr += res[i];
	}
	return sr/m;
	
}

void sort_1(double **res, int n, int m)
{
	double *tmp;
	for (int i = 0;i < n-1; i++)
	{
		for (int j = i;j < n; j++)
		{
			if (srednee(res[i], m) > srednee(res[j], m))
			{
				
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
				
				
			}
			
		}
	}
}

void perst_str(double **str1, double **str2)
{
	double *tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
	
}

void perst_stol(double **res, int n, int st1, int st2)
{
	double tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = res[i][st1];
		res[i][st1] = res[i][st2];
		res[i][st2] = tmp;
	}
}

void max_in_ugol(double **res, int n, int m)
{
	int max_i = 0;
	int max_j = 0;
	double max = res[max_i][max_j];
	for (int i = 0; i < n; i++ )
	{
		for (int j = 0; j < m; j++ )
		{
			if (res[i][j] > max)
			{
				max_i = i;
	            max_j = j;
				max = res[max_i][max_j];
			}
		}
	}
	while (max_i != 0 || max_j != 0)
	{
		if (max_i != 0)
		{
			perst_str(&res[max_i], &res[max_i-1]);
			max_i -= 1;
		}
		if (max_j != 0)
		{
			perst_stol(res, n, max_j, max_j-1);
			max_j -= 1;
		}
	}
	
}