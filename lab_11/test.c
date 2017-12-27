#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_snprintf.h"


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

void test_num_to_string(void)
{
	// test 1 - тестируем десятичное число 
	{
		int n = 10;
		char *s = "10";
		//long long int n = 0xF3FFA;
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, 2, buf, 10);
		if (compare_strins(buf, s))
			printf("test 1 num_to_string in PASSED\n");
        else
			printf("test 1 num_to_string in FAILED\n\n");
		free(buf);
	}
	// test 2 - тестируем десятичное число 
	{
		int n = 1;
		char *s = "1";
		//long long int n = 0xF3FFA;
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, 1, buf, 10);
		if (compare_strins(buf, s))
			printf("test 2 num_to_string in PASSED\n");
        else
			printf("test 2 num_to_string in FAILED\n\n");
		free(buf);
	}
	// test 3 - тестируем отрицательное десятичное число 
	{
		int n = -125214;
		char *s = "-125214";
		//long long int n = 0xF3FFA;
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, 6, buf, 10);
		if (compare_strins(buf, s))
			printf("test 3 num_to_string in PASSED\n");
        else
		{
			printf("test 3 num_to_string in FAILED\n\n");
			printf("%s\n", buf);
		}
		free(buf);
	}
	// test 3 - тестируем шестнадцатиричное число 
	{
		long long int n = 0xFFF;
		char *s = "FFF";
		//long long int n = 0xF3FFA;
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, count_numbers(n, 16), buf, 16);
		if (compare_strins(buf, s))
			printf("test 4 num_to_string in PASSED\n");
        else
		{
			printf("test 4 num_to_string in FAILED\n\n");
			printf("%s#\n", buf);
		}
		free(buf);
	}
	// test 5 - тестируем шестнадцатиричное число 
	{
		long long int n = 0xF3FF1;
		char *s = "F3FF1";
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, 5, buf, 16);
		if (compare_strins(buf, s))
			printf("test 5 num_to_string in PASSED\n");
        else
		{
			printf("test 5 num_to_string in FAILED\n\n");
			printf("%s\n", buf);
		}
		free(buf);
	}
	// test 6 - тестируем шестнадцатиричное число 
	{
		long long int n = -0xA;
		char *s = "-A";
		char *buf = calloc(20, sizeof(char));
		num_to_string(&n, count_numbers(n, 16), buf, 16);
		if (compare_strins(buf, s))
			printf("test 6 num_to_string in PASSED\n");
        else
		{
			printf("test 6 num_to_string in FAILED\n\n");
			printf("%s\n", buf);
		}
		free(buf);
	}
}


void test_snprintf(void)
{
    // test 1 - тестируем %d 
    {
        int n = 20;
        char *string = malloc(n);
        char *string2 = "I am 120 years old";
        
        char *format = "I am %d years old";

        my_snprintf(string, n, format, 120, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 1 PASSED\n");
        }
        else
        {
            printf("test 1 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    }
    // test 2 - тестируем %s 
    {
        int n = 20;
        char *string = malloc(n);
        char *string2 = "My name is Ivan\n";
        
        char *format = "My %s is %s\n";

        my_snprintf(string, n, format, "name", "Ivan", NULL);
        if (compare_strins(string, string2))
        {
            printf("test 2 PASSED\n");
        }
        else
        {
            printf("test 2 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    }
    // test 3 - тестируем %llX 
    {
        int n = 30;
        char *string = malloc(n);
        char *string2 = "  Its FFF here AFF...";
        
        char *format = "  Its %llX here %llX...";

        my_snprintf(string, n, format, 0xFFF, 0xAFF, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 3 PASSED\n");
        }
        else
        {
            printf("test 3 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    } 
    // test 4 - тестируем %llX %d %s
    {
        int n = 32;
        char *string = malloc(n);
        char *string2 = "My FFF name is 35 AAA Ivan 365";
        
        char *format = "My %llX %s is %d %llX Ivan %d";

        my_snprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 4 PASSED\n");
        }
        else
        {
            printf("test 4 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    }
    // test 5 - тестируем %llX %d %s при n меньших длины строки
    {
        int n = 5;
        char *string = malloc(n);
        char *string2 = "My F";
        
        char *format = "My %llX %s is %d %llX Ivan %d";

        my_snprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 5 PASSED\n");
        }
        else        
        {
            printf("test 5 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    }
    // test 6 - тестируем %llX %d %s при n меньших длины строки
    {
        int n = 1;
        char *string = malloc(n);
        char *string2 = "";
        
        char *format = "My %llX %s is %d %llX Ivan %d";

        my_snprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 6 PASSED\n");
        }
        else
        {
            printf("test 6 FAILED\n");
            printf("%s\n%s\n", string, string2);
        }
        free(string);
    }
    // test 7 - ошибочный коэфициент
    {
        int n = 300;
        char *string = malloc(n);
        char *string2 = "M";
        
        char *format = "My %llX %ws is %td %llX Ivan %d";

        
        int k = my_snprintf(string, n, format, 0xFFF, "name", 35, 0xAAA, 365, NULL);
        if (k == -1)
        {
            printf("test 7 PASSED\n");
        }
        else
        {
            printf("test 7 FAILED\n");
            printf("%s#\n%s\n", string, string2);
        }
        free(string);
    }
    // test 8 - один символ
    {
        int n = 300;
        char *string = malloc(n);
        char *string2 = "35M365";
        
        char *format = "%dM%d";
        my_snprintf(string, n, format, 35, 365, NULL);
        if (compare_strins(string, string2))
        {
            printf("test 8 PASSED\n");
        }
        else
        {
            printf("test 8 FAILED\n");
            printf("%s#\n%s\n", string, string2);
        }
        free(string);
    }
}

int main(void)
{
	test_num_to_string();
    test_snprintf();
}