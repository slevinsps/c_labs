#include <stdio.h>
#include <errno.h>

#define NOT_ALL_ARGUMENTS -1
#define FEWER_THAN_THREE_VALUES -2

int find_loc_max(FILE *f1,FILE *f2)
{
	printf("Enter numbers:\n");
	float a,b,c,x;
	int k = 0;
	char letter=0;
	
	if ((fscanf(f1,"%f", &x) == 1)||(!fscanf(f1,"%[a-zA-ZА-Яа-я]s", &letter)))
		a = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if ((fscanf(f1,"%f", &x) == 1)||(!fscanf(f1,"%[a-zA-ZА-Яа-я]s", &letter)))
		b = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if ((fscanf(f1,"%f", &x) == 1)||(!fscanf(f1,"%[a-zA-ZА-Яа-я]s", &letter)))
		c = x;
	else
		return FEWER_THAN_THREE_VALUES;
	if (b>c && b>a)
	{
		k++;
		
	}
	while ((fscanf(f1,"%f", &x) == 1)||(!fscanf(f1,"%[a-zA-ZА-Яа-я]s", &letter)))
    {
		a = b;
		b = c;
		c = x;
		if (b>c && b>a)
		{
			k++;
		}
		fflush(stdin);
	}
	
	fprintf(f2,"The number of peaks = %d\n",k);
    return 0;
}



int main(int argc, char** argv)
{
	setbuf(stdout,NULL);
	
	//if (argc != 3)
	//{
	//	fprintf(stderr, "main1.exe <file-name>\n");
	//	return NOT_ALL_ARGUMENTS;
	//}
	
	int k = find_loc_max(stdin,stdout);

	if (k == FEWER_THAN_THREE_VALUES)
	{
		fprintf(stderr, "Fewer than three values\n");
		return FEWER_THAN_THREE_VALUES;
	}
	
    return 0;
}
