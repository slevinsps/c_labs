#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FEWER_THAN_THREE_VALUES -1

int find_loc_max(FILE *f1,int *k)
{   
    float a = 0,b = 0,c = 0,x;
    int err = 0;
    *k = 0;
    
    if (fscanf(f1,"%f%f%f", &a, &b, &c) != 3)
        err = FEWER_THAN_THREE_VALUES;
    else
    {    
        if (b>c && b>a)
            *k = *k + 1;        
        while (fscanf(f1,"%f", &x) == 1)
        {
            a = b;
            b = c;
            c = x;
            if (b>c && b>a)
            {
                *k = *k + 1;
            }
        }
    }
    return err;
}
    


int main(int argc, char** argv)
{   
    setbuf(stdout,NULL);
    int k;    
    
    printf("Enter numbers:\n");   
    int err = find_loc_max(stdin,&k);
    if (err == FEWER_THAN_THREE_VALUES)
        fprintf(stderr, "Fewer than three values\n");
    else
        fprintf(stdout,"The number of peaks = %d\n",k);
    return err;
}
