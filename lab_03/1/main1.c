#include <stdio.h>
#include <errno.h>

#define NOT_ALL_ARGUMENTS -1
#define FEWER_THAN_THREE_VALUES -2

int find_loc_max(char *s)
{
	FILE *f1;
	printf("Enter numbers:\n");
	float a,b,c,x;
	int k = 0;
	char letter=0;
	
	if ((scanf("%f", &x) == 1)||(!scanf("%[a-zA-ZА-Яа-я]s", &letter)))
		a = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if ((scanf("%f", &x) == 1)||(!scanf("%[a-zA-ZА-Яа-я]s", &letter)))
		b = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if ((scanf("%f", &x) == 1)||(!scanf("%[a-zA-ZА-Яа-я]s", &letter)))
		c = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if (b>c && b>a)
	{
		f1 = fopen(s, "w");
		k++;
		fprintf(f1,"The number of peaks = %d\n",k);
		fclose(f1);
		
	}
	while ((scanf("%f", &x) == 1)||(!scanf("%[a-zA-ZА-Яа-я]s", &letter)))
    {
		a = b;
		b = c;
		c = x;
		if (b>c && b>a)
		{
			f1 = fopen(s, "w");
			k++;
			fprintf(f1,"The number of peaks = %d\n",k);
			fclose(f1);
		}
		fflush(stdin);
	}
	
	fprintf(f1,"The number of peaks = %d\n",k);
    return 0;
}



int main(int argc, char** argv)
{
	setbuf(stdout,NULL);

	if (argc != 2)
	{
		fprintf(stderr, "main1.exe <file-name>\n");
		return NOT_ALL_ARGUMENTS;
	}
	
	
	int k = find_loc_max(argv[1]);


	if (k == FEWER_THAN_THREE_VALUES)
	{
		fprintf(stderr, "Fewer than three values\n");
		return FEWER_THAN_THREE_VALUES;
	}
	
    return 0;
}
