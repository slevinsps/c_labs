#include <stdio.h>
#include <math.h>

// Программа которая вычисляет площадь треугольника по координатам трех точек

// Функция вычисления площади по трем точкам
float Area(float x1,float x2,float x3,float y1,float y2,float y3)
{
    float s;
    s = fabs(((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))/2);
    return s;
}

int main(void)
{
    float x1, y1; // Координаты первой точки
    float x2, y2; // Координаты второй точки
    float x3, y3; // Координаты третьей точки
    float s; // Площадь треугольника
    int pr; // Счетчик правильно считанных пременных

    setbuf(stdout,NULL);
    printf("Enter the coordinates of the first point x,y\n");
    pr = scanf("%f %f", &x1, &y1);
    if ( pr != 2)
    {
        printf("Uncorrected variables...\n");
        return 0;
    }

    setbuf(stdout,NULL);
    printf("Enter the coordinates of the second point x,y\n");
    pr = scanf("%f %f", &x2, &y2);
    if ( pr != 2)
    {
        printf("Uncorrected variables...\n");
        return 0;
    }


    setbuf(stdout,NULL);
    printf("Enter the coordinates of the third point x,y\n");
    pr = scanf("%f %f", &x3, &y3);
    if ( pr != 2)
    {
        printf("Uncorrected variables...\n");
        return 0;
    }

    s = Area(x1,x2,x3,y1,y2,y3);
    if (s == 0)
        printf("The points lie on one straight line");
    else
        printf("Area of triangle = %7.3f\n",s);

    return 0;
}
