#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2
#define NO_VALUES_IN_FILE -3

int get_count(FILE *f, float srednee)
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
    
int get_min_max(FILE *f,float *min, float *max)
{
    float x = 0;
    int err = 0;

    if (fscanf(f, "%f", &x) == 1)
    {
        *max = x;
        *min = x;
    }
    else
        err = NO_VALUES_IN_FILE;
    while (fscanf(f, "%f", &x) == 1)
    {
        if (x > *max)
        {
            *max = x;
        }
        if (x < *min)
        {
            *min = x;
        }
    }
    return err;
}

int main(int argc, char** argv)
{
    FILE *f;
    float srednee = 0, min = 0, max = 0;
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
            err = get_min_max(f,&min,&max);
            if (err == NO_VALUES_IN_FILE)
            {
                fprintf(stderr, "There are no values in the file\n");
            }
            else
            {                       
                if (fseek (f,0,0)==0)
                {
                    srednee = (max + min)/2;
                    k = get_count(f,srednee);
                    fclose(f);
                    fprintf(stdout,"Number of values of large mean value: %d", k);
                }
                else
                {
                    fprintf(stderr, "%s\n",strerror(errno));
                    err = NO_FILE;
                }
            }
        }
    }
    return err;
}
