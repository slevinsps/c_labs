#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{
    float a, b;  // большая и меньшая сторона трапеции
    float u;  // угол при большем основании
    float h, s;  // высота и площадь трапеции
    setbuf(stdout,NULL);
    printf("Enter the large, lower side of the trapezoid, and the angle at the large side: \n");
    scanf("%f %f %f", &a, &b, &u);
    h = (a - b) * tan((PI / 180) * u) / 2;  // подсчет высоты
    s = h * a / 2;  // подсчет площади
    printf("S = %7.3f\n", s);
    return 0;
}
