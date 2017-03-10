#include <stdio.h>
#include <math.h>
int main(void)
{
    setbuf(stdout,NULL);
    float t, t1, t2;  // общая температура и температуры воды разных объемов
    float v, v1, v2;  // общий объем и объемы воды разных температур
    printf("Enter v1,v2,t1,t2 through the gap: \n");
    scanf("%f %f %f %f", &v1, &v2, &t1, &t2);
    t = (v2*t2+v1*t1)/(v1+v2);  // подсчет общей температуры
    v = v1 + v2; // подсчет общего объема
    printf("T = %7.3f\n", t);
    printf("V = %7.3f\n", v);
    return 0;
}
