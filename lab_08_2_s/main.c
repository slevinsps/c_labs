#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "io.h"
#include "funcs.h"

#define COL 7
#define STR 5
#define OK 0
#define FILE_EMPTY -1
#define NOT_ALL_ARGUMENTS -2
#define INVALID_NUMBER -3
#define MUCH_NUMBERS -4


int main(int argc, char** argv)
{

	FILE *f1;
	int a[STR][COL];
	int col = 0;
	int str = 0;
	int err = OK;
	int max[COL];
	if (argc != 2)
	{
		printf("main1.exe <file_input-name>\n");
		err = NOT_ALL_ARGUMENTS;
	}
	else
	{
		f1 = fopen(argv[1], "r");
		err = read_array(f1, a, &str,&col);
		find_max_el(a,max, str, col);
		if (err != INVALID_NUMBER && err != MUCH_NUMBERS)
		{
			print_array(a,str,col);
		}
		else
		{
			printf("Erorr in read");
		}
	}
	return err; 
}