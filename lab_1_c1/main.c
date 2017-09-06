#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"

#define INCORRECT_EPSILON -1
#define NO_INTERSECTIONS -2

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
        err = intersection(&x1,&x2,&x3,eq1,eq2,eq3);
		
        if (err == NO_INTERSECTIONS)
        {
            printf("There is not triangle");
        }
        else
        {
            printf("Square triangle = ");
            printf("%f  ",square(x1,x2,x3,eps,eq1,eq2,eq3));
			
        }
    }
	//printf("   %f   ",PolovDel(eq2,-1,0,0.00001));
    return err;
}