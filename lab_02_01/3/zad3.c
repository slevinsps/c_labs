#include <stdio.h>
#include <math.h>

// Программа которая вычисляет остаток от
// деления и результат целочисленного деления

float Sum(float x,float eps)
{

    float s2 = x;
    float x1 = x;
    int k = 1;
    while (fabs(x1) > eps)
    {

        x1 = -x1*x*x/((k+1)*(k+2));

        k += 2;
        s2 += x1;


    }

    return s2;
}

int main(void)
{
    float x;
    float eps;
    float s,s1;
    while(1)
    {
        setbuf(stdout,NULL);
        printf("Enter x and epsilon:\n");
        if (scanf("%f %f", &x, &eps) == 0)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;
        }

        else
            break;
    }


        s = Sum(x,eps);
        s1 = sin(x);
        printf("Sum = %7.3f\n",s);
        printf("Sum2 = %7.3f\n",s1);
        printf("Absolut error = %f\n",fabs(s1-s));
        printf("Otnosit error = %f\n",fabs((s1-s)/s1));
    return 0;
}
