#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"


float f1(float x)
{
    float y = x*x;
    return y;
}

float f2(float x)
{
    float y = 2*x+3;
    return y;
}
       
float f3(float x)
{
    float y = 3-x;
    return y;
}

float ef1(float x)
{
    float y = f1(x)-f2(x);
    return y;
}

float ef2(float x)
{
    float y = f2(x)-f3(x);
    return y;
}
        
float ef3(float x)
{
    float y = f3(x)-f1(x);
    return y;
}
void polovin_del_tests(void)
{
	// Tests polovin_del function
	// Test 1
	if (polovin_del(ef1,-1.5,0,0.00001) - (-1) < 0.001)
		printf("Test 1 in polovin_del function is passed\n");
	else
		printf("Test 1 in polovin_del function is failed\n");
	// Test 2
	if (polovin_del(ef1,2,3.5,0.00001) - 3 <  0.001)
		printf("Test 2 in polovin_del function is passed\n");
	else
		printf("Test 2 in polovin_del function is failed\n");
	// Test 3
	if (polovin_del(ef2,-1,1,0.00001) - 0 <  0.001)
		printf("Test 3 in polovin_del function is passed\n");
	else
		printf("Test 3 in polovin_del function is failed\n");
	// Test 4
	if (polovin_del(ef3,1,2,0.00001) - (1.303) <  0.001)
		printf("Test 4 in polovin_del function is passed\n");
	else
	{
		printf("Test 4 in polovin_del function is failed\n");
	}
}

void trapez_method_tests(void)
{
	float s;
	// Tests intersection function
	// Test 1
	s = trapez_method(-2,0,1000,f3);
	if (s - 8 < 0.001)
		printf("Test 1 in trapez_method function is passed\n");
	else
		printf("Test 1 in trapez_method function is failed\n");	
	// Test 2
	s = trapez_method(1.5,3,1000,f1);
	if (s - 7.875 < 0.001)
		printf("Test 2 in trapez_method function is passed\n");
	else
		printf("Test 2 in trapez_method function is failed\n");	
	// Test 3
	s = trapez_method(-1.5,1.5,1000,f2);
	if (s - 9 < 0.001)
		printf("Test 3 in trapez_method function is passed\n");
	else
		printf("Test 3 in trapez_method function is failed\n");	
}

void integral_tests(void)
{
	float s;
	// Tests intersection function
	// Test 1
	s = integral(-2,0,0.0001,f3);
	if (s - 8 < 0.001)
		printf("Test 1 in integral function is passed\n");
	else
		printf("Test 1 in integral function is failed\n");	
	// Test 2
	s = integral(1.5,3,0.0001,f1);
	if (s - 7.875 < 0.001)
		printf("Test 2 in integral function is passed\n");
	else
		printf("Test 2 in integral function is failed\n");	
	// Test 3
	s = integral(-1.5,1.5,0.0001,f2);
	if (s - 9 < 0.001)
		printf("Test 3 in integral function is passed\n");
	else
		printf("Test 3 in integral function is failed\n");	
}

void intersection_tests(void)
{
	float x1,x2,x3;
	// Tests intersection function
	// Test 1
	intersection(&x1,&x2,&x3,ef1,ef2,ef3,-3,0);
	if (x1 - (-1) < 0.001 && x2 - 0 < 0.001 && x3 - (-2.303) < 0.001)
		printf("Test 1 in intersection function is passed\n");
	else
		printf("Test 1 in intersection function is failed\n");	
	// Test 2
	intersection(&x1,&x2,&x3,ef1,ef2,ef3,-1,3);
	if (x1 - 3 < 0.001 && x2 - 0 < 0.001 && x3 - (1.303) < 0.001)
		printf("Test 2 in intersection function is passed\n");
	else
		printf("Test 2 in intersection function is failed\n");	
}


void square_tests(void)
{
	float s;
	// Tests intersection function
	// Test 1	
	s = square(-1,0,-2.303,0.0001,f1,f2,f3);
	if (s - 3.8229 < 0.001)
		printf("Test 1 in square function is passed\n");
	else
		printf("Test 1 in square function is failed\n");
	// Test 2
	s = square(3,0,1.303,0.0001,f1,f2,f3);
	if (s - 6.68 < 0.001)
		printf("Test 2 in square function is passed\n");
	else
		printf("Test 2 in square function is failed\n");	

}

int main(void)
{
	polovin_del_tests();
	intersection_tests();
	trapez_method_tests();
	integral_tests();
	square_tests();
    return 0;
}