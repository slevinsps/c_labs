#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"
    

double f1(double x)
{
    return x*x;
}

double f2(double x)
{
    return 2*x+3;
}
       
double f3(double x)
{
    return 3-x;
}

double ef1(double x)
{
    return f1(x)-f2(x);
}

double ef2(double x)
{
    return f2(x)-f3(x);
}
        
double ef3(double x)
{
    return f3(x)-f1(x);
}

void polovin_del_tests(void)
{
    double expected, actual;
    // Tests polovin_del function
    // Test 1
    expected = -1;
    actual = polovin_del(ef1,-1.5,0,0.00001);
    if (fabs(actual - expected) < 0.001)
        printf("Test 1 in polovin_del function is passed\n");
    else
        printf("Test 1 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    // Test 2
    expected = 3;
    actual = polovin_del(ef1,2,3.5,0.00001);
    if (fabs(actual - expected) < 0.001)
        printf("Test 2 in polovin_del function is passed\n");
    else
        printf("Test 2 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    // Test 3
    expected = 0;
    actual = polovin_del(ef2,-1,1,0.00001);
    if (fabs(actual - expected) < 0.001)
        printf("Test 3 in polovin_del function is passed\n");
    else
        printf("Test 3 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    // Test 4
    expected = 1.303;
    actual = polovin_del(ef3,1,2,0.00001);
    if (fabs(actual - expected) < 0.001)
        printf("Test 4 in polovin_del function is passed\n");
    else
    {
        printf("Test 4 in polovin_del function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    }
}

void trapez_method_tests(void)
{
    double expected, actual;
    // Tests trapez_method function
    // Test 1
    expected = 8;
    actual = trapez_method(-2,0,1000,f3);
    if (fabs(actual - expected) < 0.001)
        printf("Test 1 in trapez_method function is passed\n");
    else
        printf("Test 1 in trapez_method function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
    // Test 2
    expected = 7.875;
    actual = trapez_method(1.5,3,1000,f1);
    if (fabs(actual - expected) < 0.001)
        printf("Test 2 in trapez_method function is passed\n");
    else
        printf("Test 2 in trapez_method function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
    // Test 3
    expected = 9;
    actual = trapez_method(-1.5,1.5,1000,f2);
    if (fabs(actual - expected) < 0.001)
        printf("Test 3 in trapez_method function is passed\n");
    else
        printf("Test 3 in trapez_method function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
}

void integral_tests(void)
{
    double expected, actual;
    // Tests integral function
    // Test 1
    expected = 8;
    actual = integral(-2,0,0.0001,f3);
    if (fabs(actual - expected) < 0.001)
        printf("Test 1 in integral_tests function is passed\n");
    else
        printf("Test 1 in integral_tests function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
    // Test 2
    expected = 7.875;
    actual = integral(1.5,3,0.0001,f1);
    if (fabs(actual - expected) < 0.001)
        printf("Test 2 in integral_tests function is passed\n");
    else
        printf("Test 2 in integral_tests function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
    // Test 3
    expected = 9;
    actual = integral(-1.5,1.5,0.0001,f2);
    if (fabs(actual - expected) < 0.001)
        printf("Test 3 in integral_tests function is passed\n");
    else
        printf("Test 3 in integral_tests function is failed:\n    expected = %f, actual = %f\n",expected,actual); 
}

void intersection_tests(void)
{
    double x1,x2,x3;
    // Tests intersection function
    // Test 1
    intersection(&x1,&x2,&x3,ef1,ef2,ef3,-3,0);
    if (x1 - (-1) < 0.001 && x2 - 0 < 0.001 && x3 - (-2.303) < 0.001)
        printf("Test 1 in intersection function is passed\n");
    else
        printf("Test 1 in intersection function is failed x1 = %f; x2 = %f; x3 = %f\n",x1,x2,x3);    
    // Test 2
    intersection(&x1,&x2,&x3,ef1,ef2,ef3,-1,3);
    if (x1 - 3 < 0.001 && x2 - 0 < 0.001 && x3 - (1.303) < 0.001)
        printf("Test 2 in intersection function is passed\n");
    else
        printf("Test 2 in intersection function is failed x1 = %f; x2 = %f; x3 = %f\n",x1,x2,x3);    
}

    
void square_tests(void)
{
    double actual,expected;
    // Tests intersection function
    // Test 1 
    expected = 3.8229;
    actual = square(-1,0,-2.303,0.0001,f1,f2,f3);
    if (fabs(actual - expected) < 0.01)
        printf("Test 1 in square function is passed\n");
    else
        printf("Test 3 in square function is failed:\n    expected = %f, actual = %f\n",expected,actual);
    // Test 2
    expected = 6.68;
    actual = square(3,0,1.303,0.0001,f1,f2,f3);
    if (fabs(actual - expected) < 0.01)
        printf("Test 2 in square function is passed\n");
    else
        printf("Test 2 in square function is failed:\n    expected = %f, actual = %f\n",expected,actual);

}

int main(void)
{
    polovin_del_tests();
    intersection_tests();
    trapez_method_tests();
    integral_tests();
    intersection_tests();
    square_tests();
    return 0;
}