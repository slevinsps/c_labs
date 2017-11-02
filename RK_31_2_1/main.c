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
    int err = OK;
    if (argc == 2)
    {
        f = fopen(argv[1],"r");
        if (!f)
        {
            printf("Такого файла нет\n");
            return INVALID_FILE;
        }
        err = read_matrix(f, &matrix, &n, &m);
        if (err == MEMORY_ERROR)
            printf("Ошибка выделения памяти\n");
        if (err == INVALID_SIZE)
            printf("Некорректный размер матрицы\n");
        if (err == INVALID_NUMBER)
        {
            printf("Некорректный элемент в матрице\n");
            free_matrix(matrix, n);
        }
        if (err == OK)
        {
            max_in_ugol(matrix, n, m);
            sort_1(matrix, n, m);
            printf("Результат:\n");
            print_mat(stdout,matrix,n, m);
            free_matrix(matrix, n);
        }
        fclose(f);
    }
    else
        printf("Вводите в следующем формате: ./main.exe <file.txt>\n");
    return err;
}








