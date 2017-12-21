#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_sprintf.h"


int compare_strins(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	for (int i = 0; i < len1; i++)
	{
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}

void test_snprintf(void)
{
	// test 1 - тестируем %d 
	{
		int n = 20;
		char *string = malloc(n);
		char *string2 = "I am 120 years old";
		
		char *format = "I am %d years old";

		my_sprintf(string, n, format, 120, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 1 PASSED\n");
		}
		else
		{
			printf("test 1 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 2 - тестируем %s 
	{
		int n = 20;
		char *string = malloc(n);
		char *string2 = "My name is Ivan\n";
		
		char *format = "My %s is %s\n";

		my_sprintf(string, n, format, "name", "Ivan", NULL);
		if (compare_strins(string, string2))
		{
			printf("test 2 PASSED\n");
		}
		else
		{
			printf("test 2 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 3 - тестируем %llX 
	{
		int n = 30;
		char *string = malloc(n);
		char *string2 = "  Its FFF here AFF...";
		
		char *format = "  Its %llX here %llX...";

		my_sprintf(string, n, format, 0xFFF, 0xAFF, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 3 PASSED\n");
		}
		else
		{
			printf("test 3 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 4 - тестируем %llX %d %s
	{
		int n = 30;
		char *string = malloc(n);
		char *string2 = "My FFF name is 35 AAA Ivan 365";
		
		char *format = "My %llX %s is %d %llX Ivan %d";

		my_sprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 4 PASSED\n");
		}
		else
		{
			printf("test 4 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 5 - тестируем %llX %d %s при n меньших длины строки
	{
		int n = 5;
		char *string = malloc(n);
		char *string2 = "My FF";
		
		char *format = "My %llX %s is %d %llX Ivan %d";

		my_sprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 5 PASSED\n");
		}
		else
		{
			printf("test 5 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 6 - тестируем %llX %d %s при n меньших длины строки
	{
		int n = 1;
		char *string = malloc(n);
		char *string2 = "M";
		
		char *format = "My %llX %s is %d %llX Ivan %d";

		my_sprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 6 PASSED\n");
		}
		else
		{
			printf("test 6 FAILED\n");
			printf("%s\n%s\n", string, string2);
		}
	}
	// test 7 - ошибочный коэфициент
	{
		int n = 300;
		char *string = malloc(n);
		char *string2 = "M";
		
		char *format = "My %llX %ws is %td %llX Ivan %d";

		
		int k = my_sprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
		if (k == -1)
		{
			printf("test 7 PASSED\n");
		}
		else
		{
			printf("test 7 FAILED\n");
			printf("%s#\n%s\n", string, string2);
		}
	}
	// test 8 - один символ
	{
		int n = 300;
		char *string = malloc(n);
		char *string2 = "35M365";
		
		char *format = "%dM%d";
		my_sprintf(string, n, format, 35, 365, NULL);
		if (compare_strins(string, string2))
		{
			printf("test 8 PASSED\n");
		}
		else
		{
			printf("test 8 FAILED\n");
			printf("%s#\n%s\n", string, string2);
		}
	}

}

int main(void)
{
	test_snprintf();
}