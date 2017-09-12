#ifndef FUNCTIONS
#define FUNCTIONS

typedef  double (*function1)(double);

double func1(double x);
double func2(double x);
double func3(double x);
double eq1(double x);
double eq2(double x);
double eq3(double x);
double polovin_del(function1 func, double a, double b, double eps);
int intersection(double *const x1, double *const x2, double *const x3, function1 eq1, function1 eq2,function1 eq3,double begin,double end);
double trapez_method(double a, double b, int n, function1 func);
double integral(double a, double b, double eps, function1 func);
double square(double x1, double x2, double x3, double eps, function1 func1, function1 func2,function1 func3);

#endif // FUNCTIONS