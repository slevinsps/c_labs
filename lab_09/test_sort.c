# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>

# include "sort.h"

int test1(void)
{
	char *input[] = {"2","3","1","6"};

	sort(input, 4);
	
	char *etalon[] = {"1","2","3","6"};
	for (int i = 0;i <  4; i++)
	{	
		if (strcmp(etalon[i],input[i]))
		{
			printf("not passed 1\n");
			return 0;
		} 
	}
	printf("passed 1\n");
		return 1; 
}


int test2(void)
{
	char *input[] = {"2"};

	sort(input, 1);
	
	char *etalon[] = {"2"};
	for (int i = 0;i <  1; i++)
	{	
		if (strcmp(etalon[i],input[i]))
		{
			printf("not passed 2\n");
			return 0;
		} 
	}
	printf("passed 2\n");
		return 1; 
}


int test3(void)
{
	char *input[] = {"vavv","abba","krot"};

	sort(input, 3);
	
	char *etalon[] = {"abba","krot","vavv"};
	for (int i = 0;i <  3; i++)
	{	
		if (strcmp(etalon[i],input[i]))
		{
			printf("not passed 3\n");
			return 0;
		} 
	}
	printf("passed 3\n");
		return 1; 
}

int main(void)
{
	test1();
	test2();
	test3();
	
}
	

