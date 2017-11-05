#ifndef IO
#define IO

int read_matrix(FILE *f,double ***res, int *n,int *m);
void print_mat(FILE *f, double **matrix, int n,int m);

#endif // IO