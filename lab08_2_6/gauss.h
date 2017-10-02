#ifndef GAUSS
#define GAUSS

void creat_edin(double **edin,int n);
void gauss_divide(double *row,int number, double *chislo, int n1);
void subtraction(double *row1,double *row2, int number, double *chislo1, double *chislo2,int n1);
int choos_not_zero_element(double ***matrix1,int column,int n,double **edin,int column_edin,double *arr_operations);
int gauss(double **matrix1,double ***edin, int n1, int m1);

#endif // GAUSS
