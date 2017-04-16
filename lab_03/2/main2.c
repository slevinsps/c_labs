#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NO_FILE -1
#define NOT_ALL_ARGUMENTS -2
#define INCORRECTED_VARIABLES_IN_FILE -3

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
    float max = 0, min = 0, x = 0;
	
	if (fscanf(f, "%f", &x) == 1)
	{
		max = x;
		min = x;
	}
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
	if (!feof(f))
		return INCORRECTED_VARIABLES_IN_FILE;
	*srednee = (max + min)/2;
    return 0;
}

int main(int argc, char** argv)
{
    FILE *f;
    float srednee=0;
	int k,k2;

	if (argc != 2)
	{
		fprintf(stderr, "main1.exe <file-name>\n");
		return NOT_ALL_ARGUMENTS;
	}
	
	f = fopen(argv[1], "r");
	if (f == NULL)
    {
		fprintf(stderr, "%s\n",strerror(errno));
        return NO_FILE;
    }
	k2 = get_srednee(f,&srednee);
	if (k2 == INCORRECTED_VARIABLES_IN_FILE)
	{
		fprintf(stderr, "Incorrect symbols in the file\n");
		return INCORRECTED_VARIABLES_IN_FILE;
	}
	fclose(f);
	
	f = fopen(argv[1], "r");
	k = get_count(f,srednee);
	fclose(f);

	fprintf(stdout,"Number of values of large mean value: %d", k);
    return 0;
}
