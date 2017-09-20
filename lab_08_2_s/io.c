#include <string.h>
#include <errno.h>
#include <stdio.h>


#define COL 7
#define STR 5
#define OK 0
#define FILE_EMPTY -1
#define NOT_ALL_ARGUMENTS -2
#define INVALID_NUMBER -3
#define MUCH_NUMBERS -4

int read_array(FILE *f,int mat[STR][COL], int *str,int *col)
{
	int err = OK;

	if (fscanf(f,"%d",str) == 1)
	{
		if (fscanf(f,"%d",col) == 1)
		{
			if (*str<=STR && *col<=COL)
			{
				for(int i = 0; i < *str;i++ )
				{
					for( int j = 0; j < *col; j++ )
					{

						if (fscanf(f,"%d", &mat[i][j]) != 1)
						{
							err = INVALID_NUMBER;
							break;
						}
					}
					if (err == INVALID_NUMBER)
					{
						break;
					}
				}
			}
			else
			{
				err = MUCH_NUMBERS;
			}
		}
		else
		{
			err = INVALID_NUMBER;	
		}
	}
	else
	{
		err = INVALID_NUMBER;	
	}
	return err;
}


void print_array(int (*mat)[COL], int str,int col)
{
	for(int i = 0; i < str;++i )
	{
		for( int j = 0; j < col; ++j )
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	} 
}
