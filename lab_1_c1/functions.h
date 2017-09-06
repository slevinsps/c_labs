#ifndef FUNCTIONS
#define FUNCTIONS

float func1(float x);
float func2(float x);
float func3(float x);
float eq1(float x);
float eq2(float x);
float eq3(float x);
float PolovDel(float (*func)(float), float a, float b, float eps);
int intersection(float *x1, float *x2, float *x3, float (*eq1)(float), float (*eq2)(float),float (*eq3)(float));
float trapez_method(float a, float b, int n, float (*func)(float));
float integral(float a, float b, float eps, float (*func)(float));
float square(float x1, float x2, float x3, float eps, float (*eq1)(float), float (*eq2)(float),float (*eq3)(float));

#endif // FUNCTIONS