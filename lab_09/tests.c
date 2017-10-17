# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>

# include "str.h"



int test1(void)
{
	char s[] = "hello my name Ivan";
	char *words[4];
	split_words(s, words);
	
	char *etalon[] = {"hello","my","name","Ivan"};
	for (int i = 0;i <  4; i++)
	{	
		if (strcmp(etalon[i],words[i]))
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
	char s[] = "hello,my name!Ivan";
	char *words[4];
	split_words(s, words);
	
	char *etalon[] = {"hello","my","name","Ivan"};
	for (int i = 0;i <  4; i++)
	{	
		if (strcmp(etalon[i],words[i]))
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
	char s[] = ".hello";
	char *words[1];
	split_words(s, words);
	
	char *etalon[] = {"hello"};
	for (int i = 0;i <  1; i++)
	{	
		if (strcmp(etalon[i],words[i]))
		{
			printf("not passed 3\n");
			return 0;
		} 
	}
	printf("passed 3\n");
		return 1; 
}

int test4(void)
{
	char s[] = ".h! e llo";
	char *words[3];
	split_words(s, words);
	
	char *etalon[] = {"h","e","llo"};
	for (int i = 0;i <  3; i++)
	{	
		if (strcmp(etalon[i],words[i]))
		{
			printf("not passed 4\n");
			return 0;
		} 
	}
	printf("passed 4\n");
		return 1; 
}


void test5(void)
{
	char s[] = ".h! e llo";
	int n;
	n = count_words(s);
	if (n == 3)
		printf("Passed_count 1\n");
	else
		printf("Not passed_count 1\n");
}


void test6(void)
{
	char s[] = "hello";
	int n;
	n = count_words(s);
	if (n == 1)
		printf("Passed_count 2\n");
	else
		printf("Not passed_count 2\n");
}

void test7(void)
{
	char s[] = "";
	int n;
	n = count_words(s);
	if (n == 0)
		printf("Passed_count 3\n");
	else
		printf("Not passed_count 3\n");
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}
	

