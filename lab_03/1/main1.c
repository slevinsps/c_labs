#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FEWER_THAN_THREE_VALUES -1

int find_loc_max(FILE *f1,int *k)
{
        
    float a = 0,b = 0,c = 0,x;
    int err = 0;
    *k = 0;
    
    if (fscanf(f1,"%f", &x) == 1)
         a = x;
     else
         err = FEWER_THAN_THREE_VALUES;
       
    if (fscanf(f1,"%f", &x) == 1)
         b = x;
     else
         err = FEWER_THAN_THREE_VALUES;
    
    if (fscanf(f1,"%f", &x) == 1)
         c = x;
     else
         err = FEWER_THAN_THREE_VALUES;
    
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
    return err;
}
    


int main(int argc, char** argv)
{   printf("Enter numbers:\n");
    setbuf(stdout,NULL);
    int k = 0;
    int err = find_loc_max(stdin,&k);

    if (err == FEWER_THAN_THREE_VALUES)
        fprintf(stderr, "Fewer than three values\n");
    else
        fprintf(stdout,"The number of peaks = %d\n",k);
    return err;
}
