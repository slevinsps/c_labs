#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define OK 0
#define INVALID_NUMBER -1
#define INVALID_ARGUMENT_MATRIX -2
#define NOT_ALL_ARGUMENTS -3
#define NO_FILE -4
#define DONT_EQUAL_SIZE -5
#define DONT_RIGHT_SIZE -6
#define DETERMINATE_0 -7




void free_matrix_rows(double **data, double n)
{
    for (int i = 0;i < n; i++)
    {
        free(data[i]);        
    }
    free(data);    
}

double** allocate_matrix_row(int n,int m)
{
    double **data = calloc(n,sizeof(double*));
    if (!data)
        return NULL;
    for (int i = 0;i < n;i++)
    {
        data[i] = malloc(m*sizeof(double));
        if (!data[i])
        {
            free_matrix_rows(data,n);
            return NULL;
        }
    
    }
    return data;
}

int read_matrix(FILE *f,double ***matrix1,int *n1, int *m1)
{
    int err = OK;
    if (fscanf(f,"%d",n1)==1 && *n1>0)
    {
        if (fscanf(f,"%d",m1)==1 && *m1>0)
        {
            *matrix1 = allocate_matrix_row(*n1,*m1);
            for (int i = 0; i<*n1;i++)
            {
                for (int j = 0; j<*m1;j++)
                {
                    if (fscanf(f,"%lf",&(*matrix1)[i][j]) != 1)
                    {
                        err = INVALID_NUMBER;
                        break;
                    }
                }
                if (err == INVALID_NUMBER)
                {
                    free_matrix_rows(*matrix1,*n1);
                    break;
                }
            }            
        }
        else
        {
            err = INVALID_ARGUMENT_MATRIX;
        }
    }
    return err;
}

void print_matrix(FILE *f,double **matrix1,int n1, int m1)
{
    for (int i = 0; i<n1;i++)
    {
        for (int j = 0; j<m1;j++)
        {
            fprintf(f,"%f ",matrix1[i][j]);
        }
        fprintf(f,"\n");
    }
    
}

int sum_matrix(double **matrix1, double **matrix2, int n1, int m1,int n2, int m2,double ***matrix3)
{
    int err = OK;
    if (n1 == n2 && m1 == m2)
    {
        *matrix3 = allocate_matrix_row(n1,m1);
        for (int i = 0; i<n1;i++)
        {
            for (int j = 0; j<m1;j++)
            {
                (*matrix3)[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    else
    {
        err = DONT_EQUAL_SIZE;
    }    
    return err;
}

int multiply_matrix(double **matrix1, double **matrix2, int n1, int m1,int n2, int m2,double ***matrix3)
{
    int err = OK;
    if (n1 == m2 && m1 == n2)
    {
        *matrix3 = allocate_matrix_row(n1,m2);
        for (int i = 0; i<n1;i++)
        {
            for (int j = 0; j<m2;j++)
            {
                (*matrix3)[i][j] = 0;
            }
        }
        for (int ii = 0; ii<n1; ii++)
        {
                for (int i = 0; i<n1;i++)
                {
                    for (int j = 0; j<n2;j++)
                    {
                        (*matrix3)[ii][i] += matrix1[ii][j] * matrix2[j][i];
                    }
                }        
        }    
    }    
    else
        err = DONT_RIGHT_SIZE;
    return err;
}

void creat_edin(double **edin,int n)
{
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<n;j++)
        {
        if (i == j)
            edin[i][j] = 1;
        else
            edin[i][j] = 0;
        }
    } 
}    

void gauss_divide(double *row,int number, double *chislo, int n1)
{
    double div = row[number];
    *chislo = *chislo/div;
    
    for (int i = 0;i<n1;i++)
    {
        row[i] = row[i]/div;
    }    
}

void subtraction(double *row1,double *row2, int number, double *chislo1, double *chislo2,int n1)
{
    double sub = row1[number];
    
    for (int i = 0;i<n1;i++)
    {
        row1[i] = row1[i] - sub*row2[i];
    }
    *chislo1 = *chislo1 - sub*(*chislo2);
}

int choos_main_element(double ***matrix1,int j,int n,double **edin,int jj,double *ans)
{
    int err = OK;
    int k;
    int bool1 = 0;
    double *row;
    for(int i = j;i<n;i++)
    {
        if ((*matrix1)[i][j] > 0.0001)
        {
            bool1 = 1;
            row = (*matrix1)[i];
            (*matrix1)[i] = (*matrix1)[j];
            (*matrix1)[j] = row;
            k = edin[i][jj];
            edin[i][jj] = edin[j][jj]; 
            edin[j][jj] = k;
            *ans = i;
            break;
        }
    }
    if (!bool1)
    {
        err = DETERMINATE_0;
    }    
    
    return err;
}


int gauss(FILE *f,double **matrix1,int n1, int m1)
{
    /// Пытался сделать сохранение операций, чтоб с остальными стобцами просто применить их
    /// сделал это, но не уверен, что это сделало программу легче, хотелось бы услышать ваше мнение
    int err = OK;
    if (n1 == m1)    
    {
        double arr_operations[n1+n1*n1+n1]; // в этот массив сохраняются операции
        int k = 0;
        double **edin =  allocate_matrix_row(n1,m1);
        creat_edin(edin,n1);
		
        for (int j = 0;j<n1;j++)
        {
            err = choos_main_element(&matrix1, j, n1, edin, 0, &arr_operations[k]);
			if (err == DETERMINATE_0)
			{				
				break;				
			}
			else
			{
				k++;
				arr_operations[k] = matrix1[j][j];
				gauss_divide(matrix1[j],j,&edin[j][0], n1);
   
				k++;
				for (int v = 0;v<n1;v++)
				{
					if (v != j)
					{
						arr_operations[k] = matrix1[v][j];
						subtraction(matrix1[v], matrix1[j], j, &edin[v][0], &edin[j][0],n1);
	
						k++;
					}
				}
			}                    
        } 

		if (err == OK)
		{
			int tmp;
			for (int i = 1;i<n1;i++)
			{
				k = 0;
				for (int j = 0;j<n1;j++)
				{
					tmp = edin[j][i];
					edin[j][i] = edin[(int)arr_operations[k]][i];
					edin[(int)arr_operations[k]][i] = tmp;
					k++;
					edin[j][i] /= arr_operations[k];
					k++;
					for (int v = 0;v<n1;v++)
					{
						if (v != j)
						{
							edin[v][i] -= arr_operations[k]*edin[j][i];
							k++;
						}
					}    
				}    
			}    
			
			printf("\n");
			print_matrix(f,edin,n1,m1);
			printf("\n\n");
		}
        
    }
    else
        err = DONT_EQUAL_SIZE;
    return err;
}

int menu(double **matrix1,double **matrix2,int n1,int m1,int n2,int m2,char* argv)
{
    int err = OK;
    int choice;
    FILE *f3;
    double **matrix_sum = NULL;
    printf("1 - сложить матрицы\n");
    printf("2 - перемножить матрицы\n");
    printf("3 - вычислить обратную матрицу методом Гаусса\n\n");
    printf("0 - выйти\n");
    
    scanf("%d",&choice);
    if(choice == 1)
    {
        err = sum_matrix(matrix1,matrix2,n1,m1,n2,m2,&matrix_sum);
        if (err == OK)
        {                        
            f3 = fopen(argv, "w");
            print_matrix(f3,matrix_sum,n1,n2);
            fclose(f3);
            printf("Done!");
        }
        else
        {
            printf("Matrices should have the same size");        
        }
    }
    if(choice == 2)
    {
        err = multiply_matrix(matrix1,matrix2,n1,m1,n2,m2,&matrix_sum);
        if (err == OK)
        {                        
            f3 = fopen(argv, "w");
            print_matrix(f3,matrix_sum,n1,n1);
            fclose(f3);
            printf("Done!");
        }
        else
        {
            printf("The number of columns of the first matrix\nis ​​not equal to the number of rows of the second matrix.");        
        }
    }
    if(choice == 3)
    {
        err = gauss(stdout,matrix1,n1,m1);
        if (err == OK)
        {                        
            //f3 = fopen(argv, "w");
            //print_matrix(f3,matrix_sum,n1,n1);
            //fclose(f3);
            //printf("Done!");
        }
		if (err == DETERMINATE_0)
		{
			printf("Determinate = 0\n");
		}
        if (err == DONT_EQUAL_SIZE)
        {
            printf("The number of columns and rows ​​not equal");        
        }
    }
    
    
    
    return err;
}
        
int main(int argc, char** argv)
{
    int err = OK;
    int n1,m1;
    int n2,m2;
    double **matrix1 = NULL;
    double **matrix2 = NULL;
    
    FILE *f1;
    FILE *f2;
    setbuf(stdout,NULL);
    if (argc != 4)
    {
        fprintf(stderr, "main1.exe <file_input-name1> <file_input-name2> <file_output-name>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else    
    {
        f1 = fopen(argv[1], "r");
        if (f1 == NULL)
        {
            fprintf(stderr, "%s\n",strerror(errno));
            err = NO_FILE;
        }
        else
        {
            err = read_matrix(f1,&matrix1,&n1, &m1);
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
                f2 = fopen(argv[2], "r");
                if (f2 == NULL)
                {
                    fprintf(stderr, "%s\n",strerror(errno));
                    err = NO_FILE;
                }
                else
                {
                    err = read_matrix(f2,&matrix2,&n2, &m2);
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
                        err = menu(matrix1,matrix2,n1,m1,n2,m2,argv[3]);
                        
                        /*for (int i = 0; i<n1;i++)
                        {
                            for (int j = 0; j<m1;j++)
                            {
                                printf("%f ",matrix1[i][j]);
                            }
                            printf("\n");
                        } 
                        for (int i = 0; i<n2;i++)
                        {
                            for (int j = 0; j<m2;j++)
                            {
                                printf("%f ",matrix2[i][j]);
                            }
                            printf("\n");
                        } */ 
                    }
                
                }
                    
                    
            }
            
        }
        
    
    }
    
    return err;
}



