#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"
    
#define OK 0
#define INCORRECT_EPSILON -1
#define NO_INTERSECTIONS -2

// Первая пользовательская функция
float func1(float x)
{
    float y = exp(-x+2);
    return y;
}

// Вторая пользовательская функция
float func2(float x)
{
    float y = exp(x);
    return y;
}
    
// Третья пользовательская функция    
float func3(float x)
{
    float y = 3*x+2;
    return y;
}

float eq1(float x)
{
    float y = func1(x)-func2(x);
    return y;
}

float eq2(float x)
{
    float y = func2(x)-func3(x);
    return y;
}
        
float eq3(float x)
{
    float y = func3(x)-func1(x);
    return y;
}

int main(void)
{
    float x1,x2,x3,eps;
    int err = OK;
    setbuf(stdout,NULL);
    printf("Enter epsilon:  ");
    scanf("%f",&eps);
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
    