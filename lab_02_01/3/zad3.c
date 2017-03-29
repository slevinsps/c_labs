#include <stdio.h>
#include <math.h>

// Программа которая вычисляет сумму ряда, точное значение ряда,
// абсолютную и относителную ошибку

// Функция котоая вычисляет сумму ряда
float Sum(float x,float eps)
{
    float s2 = x; // Сумма ряда
    float x1 = x; // Очередной x
    int k = 1; // Счетчик
    while(1)
    {
        x1 = -x1*x*x/((k+1)*(k+2));
		if (fabs(x1) < eps)
			return s2;
        k += 2;
        s2 += x1;
    }
    
}

int main(void)
{
    float x; // Значение аргумента
    float eps; // Точность
    float zn,zn_toch; // Вычисленное и точное значение фунции
    float absol_Error, otnos_Error; // Абсолютная и относительная ошибка
    int pr; // Счетчик правильно считанных пременных

    // Цикл выполняется пока не будет найдено ошибок ввода
    while(1)
    {
        setbuf(stdout,NULL);
        printf("Enter x and epsilon:\n");
        pr = scanf("%f %f", &x, &eps);
        if ( pr != 2)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;
        }

        else
            break;
    }

    zn = Sum(x,eps);
    zn_toch = sin(x);
    absol_Error = fabs(zn_toch-zn);
    printf("Sum = %7.3f\n",zn);
    printf("Sum2 = %7.3f\n",zn_toch);
    printf("Absolut error = %f\n",absol_Error);
    if (zn == 0)
        printf("Division by zero, it is impossible to calculate the relative error...\n");
    else
    {
        otnos_Error = absol_Error/zn_toch;
        printf("Otnosit error = %f\n",otnos_Error);
    }
    return 0;
}
