#include <stdio.h>
#include <math.h>

#define PI 3.1415926

// Программа подсчитывает площадь трапеции, используя два основания и угол
int main(void)
{
    float big_side, small_side;  // большая и меньшая сторона трапеции
    float ugol;  // угол при большем основании
    float h, s;  // высота и площадь трапеции

    setbuf(stdout,NULL);
    printf("Enter the large, lower side of the trapezoid, and the angle at the"
           " large side: \n");
    scanf("%f %f %f", &big_side, &small_side, &ugol);
    h = (big_side - small_side) * tan((PI / 180) * ugol) / 2;  // подсчет высоты
    s = h * (big_side + small_side) / 2;  // подсчет площади

    printf("S = %7.3f\n", s);
    return 0;
}
