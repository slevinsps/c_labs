#include <stdio.h>
#include <math.h>
#include <assert.h>

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

// Функция, находящая пересечения пользовательских функций
int intersection(float *x1, float *x2, float *x3, float (*func1)(float), float (*func2)(float),float (*func3)(float))
{
    float begin = -1;   
    float end = 1;    
    float dy = 0.001;
    float dx = 0.000001;
    float x = begin;
    float y1,y2,y3;
    int bool1 = 0;
    int bool2 = 0;
    int bool3 = 0;
    while (x <= end)
    {
        y1 = func1(x);
        y2 = func2(x);
        y3 = func3(x);
        if (fabs(y1-y2)<dy)
        {
            *x1 = x;
            bool1 = 1;
        }
        if (fabs(y1-y3)<dy)
        {
            *x2 = x;
            bool2 = 1;
        }    
        if (fabs(y2-y3)<dy)
        {
            *x3 = x;
            bool3 = 1;
        }
        x = x + dx;
    }
    if (bool1 == 0 || bool2 == 0 || bool3 == 0)
    {
        return NO_INTERSECTIONS;
    }
    return 0;
}

//Функция находящая интеграл по методу трапеций для данного колиества разбиений
float trapez_method(float a, float b, int n, float (*func)(float))
{
    float h = (b-a)/n;
    float s = 0;
    float x = 0;
    
    assert(n > 1);
    assert(func);
    
    for (int i = 1; i < n; i++) 
    {
        x = a + h*i;
        s += func(x);
    }
    s = fabs(h * ((func(a)+func(b))/2 + s));
    return s;
}

//Функция находящая интеграл с заданной точностью
float integral(float a, float b, float eps, float (*func)(float))
{
    assert(0 < eps && eps < 1);
    assert(func);
    
    float s1 = 0;
    int n = 2;
    float s2 = trapez_method(a,b,n,func);
    while (fabs((s2-s1)/s1) > eps)
    {
        n *= 2;
        s1 = s2;
        s2 = trapez_method(a,b,n,func);
    }
    return s1;
}
    
// Функция, находящая площадь криволинейного треугольника
float square(float x1, float x2, float x3, float eps, float (*func1)(float), float (*func2)(float),float (*func3)(float))
{
    float s1 = integral(x1,x2,eps,func1);
    float s2 = integral(x1,x3,eps,func2);
    float s3 = integral(x2,x3,eps,func3);
    float answer = 0;
    if ((x2 <= x1 && x1 <= x3) || (x3 <= x1 && x1 <= x2))
    {
        answer = fabs(s1 + s2 - s3);
        
    }
    if ((x1 <= x2 && x2 <= x3) || (x3 <= x2 && x2 <= x1))
    {
        answer = fabs(s1 + s3 - s2);
        
    }
    if ((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1))
    {
        answer = fabs(s1 + s2 - s3);
    }
    return answer;
}

int main(void)
{
    float x1,x2,x3,eps;
    int err = 0;
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
        err = intersection(&x1,&x2,&x3,func1,func2,func3);
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