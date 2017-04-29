#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2
#define NO_VALUES_IN_FILE -3

float get_count(FILE *f, float srednee)
{
    float x = 0;
    int k = 0;
    while (fscanf(f, "%f", &x) == 1)
    {
        
        if (x > srednee)
            k++;
    }
    
    return k;
}

float get_srednee(FILE *f,float *srednee)
{
    float max = 0, min = 0, x = 0, err = 0;
    
    if (fscanf(f, "%f", &x) == 1)
    {
        max = x;
        min = x;
    }
    else
        err = NO_VALUES_IN_FILE;
    while (fscanf(f, "%f", &x) == 1)
    {
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
    }
    *srednee = (max + min)/2;
    return err;
}

int main(int argc, char** argv)
{
    FILE *f;
    float srednee=0;
    int k,err = 0;

    if (argc != 2)
    {
        fprintf(stderr, "main1.exe <file-name>\n");
        err = NOT_ALL_ARGUMENTS;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            fprintf(stderr, "%s\n",strerror(errno));
            err = NO_FILE;
        }
        else
        {
            err = get_srednee(f,&srednee);
            if (err == NO_VALUES_IN_FILE)
            {
                fprintf(stderr, "There are no values in the file\n");
            }
            else
            {    
                fclose(f);            
                f = fopen(argv[1], "r");
                k = get_count(f,srednee);
                fclose(f);        
                fprintf(stdout,"Number of values of large mean value: %d", k);
            }
        }
    }
    return err;
}
