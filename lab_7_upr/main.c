#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"
    
#define OK 0
#define INCORRECT_EPSILON -1
#define NO_INTERSECTIONS -2

// Первая пользовательская функция
double func1(double x)
{
    return exp(-x+2);
}

// Вторая пользовательская функция
double func2(double x)
{
    return exp(x);
}
    
// Третья пользовательская функция    
double func3(double x)
{
    return 3*x+2;
}

double eq1(double x)
{
    return func1(x)-func2(x);
}

double eq2(double x)
{
    return func2(x)-func3(x);
}
        
double eq3(double x)
{
    return func3(x)-func1(x);
}

int main(void)
{
    double x1,x2,x3,eps;
    int err = OK;
    setbuf(stdout,NULL);
    printf("Enter epsilon:  ");
    scanf("%lf",&eps);
    if (eps <= 0 || eps >= 1)
    {
        printf("Inorrect epsilon");
        err = INCORRECT_EPSILON;
    }
    else
    {
        err = intersection(&x1,&x2,&x3,eq1,eq2,eq3,0,3);
        
        if (err == NO_INTERSECTIONS)
        {
            printf("There is not triangle");
        }
        else
        {
            printf("Square triangle = ");
            printf("%f  ",square(x1,x2,x3,eps,func1,func2,func3));
            
        }
    }
    return err;
}
    