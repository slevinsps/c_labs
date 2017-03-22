#include <stdio.h>
#include <math.h>

// Программа которая вычисляет остаток от
// деления и результат целочисленного деления

int Area(float x1,float x2,float x3,float y1,float y2,float y3)
{
    int s;
    s = abs(((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))/2);
    return s;
}

int main(void)
{
    float x1, y1; // Координаты первой точки
    float x2, y2; // Координаты второй точки
    float x3, y3; // Координаты третьей точки
    float s; // Площадь треугольника
    while(1)
    {
        setbuf(stdout,NULL);
        printf("Enter the coordinates of the first point x,y\n");
        if (scanf("%f %f", &x1, &y1) == 0)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;
        }

        else
            break;

    }
        fflush(stdin);
    while(1)
    {
        printf("Enter the coordinates of the second point x,y\n");
        if (scanf("%f %f", &x2, &y2) == 0)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;

        }
        else
            break;

    }
        fflush(stdin);
    while(1)
    {
        printf("Enter the coordinates of the third point x,y\n");
        if (scanf("%f %f", &x3, &y3) == 0)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;

        }
        else
            break;

    }
        fflush(stdin);
        s = Area(x1,x2,x3,y1,y2,y3);
        if (s == 0)
            printf("The points lie on one straight line");
        else
            printf("Area of triangle = %7.3f\n",s);

    return 0;
}
