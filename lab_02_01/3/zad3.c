#include <stdio.h>
#include <math.h>

// Программа которая вычисляет сумму ряда, точное значение ряда,
// абсолютную и относителную ошибку

// Функция котоая вычисляет сумму ряда
double sum(double x,double eps)
{
    double s2 = x; // Сумма ряда
    double x1 = x; // Очередной x
    int k = 1; // Счетчик
    while(fabs(x1) > eps)
    {
        x1 = -x1*x*x/((k+1)*(k+2));
        k += 2;
        s2 += x1;
    }
	return s2;
    
}

int main(void)
{
    double x; // Значение аргумента
    double eps; // Точность
    double zn,zn_toch; // Вычисленное и точное значение фунции
    double absol_Error, otnos_Error; // Абсолютная и относительная ошибка
    int pr; // Счетчик правильно считанных пременных
	setbuf(stdout,NULL);
    // Цикл выполняется пока не будет найдено ошибок ввода
	do
    {       
        printf("Enter x and epsilon:\n");
        pr = scanf("%lf %lf", &x, &eps);
        if ( pr != 2)
        {
            fflush(stdin); // Очищаем буфер обмена
            printf("Uncorrected variables...\n");
            continue;

        }  
    }while (pr != 2);

    zn = sum(x,eps); 
    zn_toch = sin(x); // Точное значение синуса
    absol_Error = fabs(zn_toch-zn);
    printf("Sum = %7.3lf\n",zn);
    printf("Sum2 = %7.3lf\n",zn_toch);
    printf("Absolut error = %lf\n",absol_Error);
    if (zn == 0)
        printf("Division by zero, it is impossible to calculate the relative error...\n");
    else
    {
        otnos_Error = absol_Error/zn_toch;
        printf("Otnosit error = %lf\n",otnos_Error);
    }
    return 0;
}
