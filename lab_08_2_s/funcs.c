#include <string.h>
#include <errno.h>
#include <stdio.h>


#define COL 7
#define STR 5
#define OK 0

int find_max_el(int mat[STR][COL], int *max, int str, int col)
{
	int err = OK;
	
	for(int i = 0; i < str;i++ )
	{
		max[i] = mat[i][0];
		for( int j = 0; j < col; j++ )
		{
			if (mat[i][j]>max[i])
			{
				max[i] = mat[i][j];
			}
		}
	}

	/* for(int i = 0; i < str;i++ )
	{
		printf("%d ",max[i]);
	} */
	return err;
}