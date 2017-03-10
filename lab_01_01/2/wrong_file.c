#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{
float a, b;  // большая и меньшая сторона пирамиды
float u;  // угол при большем основании
float h, s;  // высота и площадь пирамиды
printf("Введите большую, меньшую стороны трапеции и угол при большей стороне: ");
scanf("%f %f %f", &a, &b, &u);
h = (a-b)*tan((PI/180)*u)/2;
s = h*a/2;
printf("Площадь равна: %7.3f\n", s);
return 0;
}
