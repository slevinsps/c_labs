#include <math.h>
#include <assert.h>
#include <stdio.h>

#define NO_INTERSECTIONS -2
  
typedef  double (*function1)(double);

//Функция, реализирующая метод половинного деления
double polovin_del(function1 func, double a, double b, double eps)
{
    double c = (a + b) / 2;  
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
int intersection(double *const x1, double *const x2, double *const x3, function1 eq1, function1 eq2,function1 eq3,double begin,double end)
{  
    double dx = 0.01; // шаг
    double nach = begin;
    double kon = nach+dx;
    int intersection1 = 0;  // переменная, показывающая, нахождение пересечения 1
    int intersection2 = 0;  // переменная, показывающая, нахождение пересечения 2
    int intersection3 = 0;  // переменная, показывающая, нахождение пересечения 3
    
    while (nach <= end)
    {
        
        if (eq1(nach)*eq1(kon) <= 0)
        {
            *x1 = polovin_del(eq1,nach,kon,0.00001);
            intersection1 = 1;
        }
        if (eq2(nach)*eq2(kon) <= 0)
        {
            *x2 = polovin_del(eq2,nach,kon,0.00001);
            intersection2 = 1;
        }    
        if (eq3(nach)*eq3(kon) <= 0)
        {
            *x3 = polovin_del(eq3,nach,kon,0.00001);
            intersection3 = 1;
        }
        nach = kon;
        kon = kon + dx;
    }
    if (intersection1 == 0 || intersection2 == 0 || intersection3 == 0)
    {
        return NO_INTERSECTIONS;
    }
    return 0;
}

//Функция находящая интеграл по методу трапеций для данного колиества разбиений
double trapez_method(double a, double b, int n, function1 func)
{
    double h = (b-a)/n;
    double s = 0;
    double x = 0;
    
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
double integral(double a, double b, double eps, function1 func)
{
    assert(0 < eps && eps < 1);
    assert(func);
    
    double s1 = 0;
    int n = 2;
    double s2 = trapez_method(a,b,n,func);
    while (fabs((s2-s1)/s1) > eps)
    {
        n *= 2;
        s1 = s2;
        s2 = trapez_method(a,b,n,func);
    }
    return s1;
}
        
// Функция, находящая площадь криволинейного треугольника
double square(double x1, double x2, double x3, double eps, function1 func1, function1 func2,function1 func3)
{
    double s1 = integral(x1,x3,eps,func1);
    double s2 = integral(x1,x2,eps,func2);
    double s3 = integral(x2,x3,eps,func3);
    return fabs(s1 + s2 - s3);
}