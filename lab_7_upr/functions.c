#include <math.h>
#include <assert.h>
#include <stdio.h>

#define NO_INTERSECTIONS -2
     
//Функция, реализирующая метод половинного деления
float polovin_del(float (*const func)(float), float a, float b, float eps)
{
    float c = (a + b) / 2;  
    while (fabs(b - a) > eps)
    {
      
        if (func(a) * func(c) <= 0)
            b = c;
        else
        {
            a = c;
        }
        c = (a+b)/2;

    }
    return (a+b)/2;
}

// Функция, находящая пересечения пользовательских функций
int intersection(float *const x1, float *const x2, float *const x3, float (*const eq1)(float), float (*const eq2)(float),float (*const eq3)(float),float begin,float end)
{  
    float dx = 0.01;
    float nach = begin;
    float kon = nach+dx;
    int bool1 = 0;
    int bool2 = 0;
    int bool3 = 0;
    
    while (nach <= end)
    {
        
        if (eq1(nach)*eq1(kon) <= 0)
        {
            *x1 = polovin_del(eq1,nach,kon,0.00001);
            bool1 = 1;
        }
        if (eq2(nach)*eq2(kon) <= 0)
        {
            *x2 = polovin_del(eq2,nach,kon,0.00001);
            bool2 = 1;
        }    
        if (eq3(nach)*eq3(kon) <= 0)
        {
            *x3 = polovin_del(eq3,nach,kon,0.00001);
            bool3 = 1;
        }
        nach = kon;
        kon = kon + dx;
    }
    if (bool1 == 0 || bool2 == 0 || bool3 == 0)
    {
        return NO_INTERSECTIONS;
    }
    return 0;
}

//Функция находящая интеграл по методу трапеций для данного колиества разбиений
float trapez_method(float a, float b, int n, float (*const func)(float))
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
float integral(float a, float b, float eps, float (*const func)(float))
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
float square(float x1, float x2, float x3, float eps, float (*const func1)(float), float (*const func2)(float),float (*const func3)(float))
{
    float s1 = integral(x1,x3,eps,func1);
    float s2 = integral(x1,x2,eps,func2);
    float s3 = integral(x2,x3,eps,func3);
    float answer = 0;
    if ((x2 <= x1 && x1 <= x3) || (x3 <= x1 && x1 <= x2))
    {
        answer = fabs(s1 + s2 - s3);
        
    }
    if ((x1 <= x2 && x2 <= x3) || (x3 <= x2 && x2 <= x1))
    {
        answer = fabs(s3 + s2 - s1);
        
    }
    if ((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1))
    {
       
        answer = fabs(s1 + s3 - s2);
    }
    return answer;
}