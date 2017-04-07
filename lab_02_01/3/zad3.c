#include <stdio.h>
#include <math.h>

#define DIVISION_BY_ZERO 1
#define NEGATIVE_EPSILON -1

// Программа которая вычисляет сумму ряда, точное значение ряда,
// абсолютную и относителную ошибку

// Функция возвращает относительную ошибку
int otnos_Error(double zn,double absol_Error, double zn_toch)
{
    if (zn == 0)
    {
        printf("Division by zero, it is impossible to calculate the relative error...\n");
        return DIVISION_BY_ZERO;
    }
    else
    {
        double otnos_Error = absol_Error/zn_toch; //  Относительная ошибка
        printf("Otnosit error = %lf\n",otnos_Error);
        return 0;
    }
}
	
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
    double absol_Error; // Абсолютная ошибка
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
	
	// Проверка на отрицательную точность
	if (eps < 0)
    {
        printf("Negative epsilon...\n");
        return NEGATIVE_EPSILON;
    }    
	
	
    zn = sum(x,eps);
    zn_toch = sin(x); // Точное значение синуса
    absol_Error = fabs(zn_toch-zn);
    printf("Sum = %7.3lf\n",zn);
    printf("Sum_tochn = %7.3lf\n",zn_toch);
    printf("Absolut error = %lf\n",absol_Error);
	otnos_Error(zn, absol_Error, zn_toch);
    return 0;
}
