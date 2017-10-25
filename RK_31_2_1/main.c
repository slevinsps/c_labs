#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "io.h"
#include "free_all.h"
#include "defines.h"


int main(int argc,char **argv)
{
	FILE *f;
	double **matrix;
	int n,m;
	if (argc == 2)
	{
		f = fopen(argv[1],"r");
		if (!f)
		{
			printf("Такого файла нет");
			return INVALID_FILE;
		}
		read_matrix(f,&matrix, &n, &m);
		max_in_ugol(matrix, n, m);
		//sort_1(matrix, n, m);
        print_mat(matrix,n, m);
		
	}
	else
		printf("Неверное количество аргументов");
	
}








