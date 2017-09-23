#ifndef IO
#define IO
#define COL 7
#define STR 5
int read_array(FILE *f,int mat[STR][COL], int *str,int *col);
void print_array(int (*mat)[COL], int str,int col);
#endif // IO
