#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "io.h"
#include "sum_matrix.h"
#include "multiply_matrix.h"
#include "gauss.h"
#include "create_free_matrix.h"
#include "defines.h"

int main(int argc, char** argv)
{
    int err = OK;
    int n1 = 0,m1 = 0;
    int n2 = 0,m2 = 0;
    double **matrix1;
    double **matrix2;
    double **matrix_res = NULL;
    double **edin = NULL;
    
    FILE * f1;
    FILE * f2;
    FILE * f_res;

    setbuf(stdout,NULL);
	/* f1 = fopen(argv[2], "r");
	read_matrix(f1,&matrix1,&n1, &m1);
	f2 = fopen(argv[3], "r");
	err = read_matrix(f2,&matrix2,&n2, &m2);
	f_res = fopen(argv[4], "w");
	fprintf(f_res,"%d %d",n1,m1);
	for (int i = 0; i<n1;i++)
	{
		fprintf(f_res,"\n");
		for (int j = 0; j<m1;j++)
		{
			fprintf(f_res,"%f ",matrix1[i][j] + matrix2[i][j]);
			
		}
	}
	fclose(f1);
	fclose(f2);
	fclose(f_res);
	free_matrix_rows(&matrix1, n1);
	free_matrix_rows(&matrix2, n2); */
    //if (err == OK)
    //{                        
        // f_res = fopen(argv[4], "w");
        // if (f_res)
        // {
            // print_matrix(f_res,matrix_res,n1,m1);
            // fclose(f_res);
    
        // }
        // else
            // err = NO_FILE;
        // free_matrix_rows(matrix_res, n1);
        
    //}
    //else
    //{
    //    printf("Matrices should have the same size");                                     
    //}
    if (argc < 4 || argc > 5)
    {
        fprintf(stderr, "main1.exe <action> <mtr_1.txt> [mtr_2.txt] <res.txt>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else    
    {
        f1 = fopen(argv[2], "r");
        if (f1 == NULL)
        {
            fprintf(stderr, "%s\n",strerror(errno));
            err = NO_FILE;
        }
        else
        {           
            err = read_matrix(f1,&matrix1,&n1, &m1);
            fclose(f1);
            if (err == INVALID_NUMBER)
            {    
                printf("Invalid number in matrix 1\n");
            }
            if (err == INVALID_ARGUMENT_MATRIX)
            {    
                printf("Invalid arguments of matrix 1\n");
            }
            if (err == OK)
            {
                if (argc == 5)
                {
                    f2 = fopen(argv[3], "r");
                    if (f2 == NULL)
                    {
                        fprintf(stderr, "%s\n",strerror(errno));
                        err = NO_FILE;
                    }
                    else
                    {
                        err = read_matrix(f2,&matrix2,&n2, &m2);
                        fclose(f2);
                        if (err == INVALID_NUMBER)
                        {    
                            printf("Invalid number in matrix 2\n");
                        }
                        if (err == INVALID_ARGUMENT_MATRIX)
                        {    
                            printf("Invalid arguments of matrix 2\n");
                        }
                        if (err == OK)
                        {
                            if (strcmp(argv[1],"a") == 0)
                            {                               
                                err = sum_matrix(matrix1,matrix2,n1,m1,n2,m2,&matrix_res);
                                printf("%d \n",err);
                                if (err == OK)
                                {                        
                                    f_res = fopen(argv[4], "w");
                                    if (f_res)
                                    {
                                        print_matrix(f_res,matrix_res,n1,m1);
                                        fclose(f_res);
                                
                                    }
                                    else
                                        err = NO_FILE;
                                    free_matrix_rows(&matrix_res, n1);
                                    
                                }
                                else
                                {
                                    printf("Matrices should have the same size");                                     
                                }
                            }
                            else if (strcmp(argv[1],"m") == 0)
                            {                                
                                err = multiply_matrix(matrix1,matrix2,n1,m1,n2,m2,&matrix_res);
                                if (err == OK)
                                {                        
                                    f_res = fopen(argv[4], "w");
                                    if (f_res)
                                    {
                                        print_matrix(f_res,matrix_res,n1,n1);
                                        fclose(f_res);
                                        
                                    }
                                    else
                                        err = NO_FILE;
                                    free_matrix_rows(&matrix_res, n1);
                                }
                                else
                                {
                                    printf("The number of columns of the first matrix ​​not equal to the number of rows of the second matrix.");        
                                }
                            }
                            else
                            {
                                err = -10;                                
                            }
                            
                            free_matrix_rows(&matrix2, n2);
                        }  
                        
                    }
                    
                }
                if (argc == 4)
                {        
                   if (strcmp(argv[1],"o") == 0)
                    {                                            
                        err = gauss(matrix1,&edin,n1,m1);
                        if (err == OK)
                        {                        
                            f_res = fopen(argv[3], "w");
                            if (f_res)
                            {
                                //print_matrix(f_res,edin,n1,n1);
                                fclose(f_res);
                                
                            }
                            else
                                err = NO_FILE;
                            
                            free_matrix_rows(&edin, n1);
                        }
                        if (err == DETERMINATE_0)
                        {
                            printf("Determinate = 0\n");
                            free_matrix_rows(&edin, n1);
                            
                        }
                        if (err == DONT_EQUAL_SIZE)
                        {
                            printf("The number of columns and rows ​​not equal");                            
                        } 
                    }
                    else
                    {
                        err = -10;                                
                    }
                } 
                free_matrix_rows(&matrix1, n1);                
            }           
            
        } 
                
    }
    //printf("%d\n",err);
    
    return err;
}



