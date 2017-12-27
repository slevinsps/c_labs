#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_snprintf.h"
#include "limits.h"


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
    // test 1 - INT_MIN
    {
        int n = 20;
        char *string = malloc(n);
        char *string2 = malloc(n);
        //char *string2 = "I am 120 years old";
        
        char *format = "%d";

        my_snprintf(string, n, format, INT_MIN);
        snprintf(string2, n, format, INT_MIN);
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
        free(string2);
    }
    // test 2 - INT_MAX
    {
        int n = 20;
        char *string = malloc(n);
        char *string2 = malloc(n);
        //char *string2 = "I am 120 years old";
        
        char *format = "%d";

        my_snprintf(string, n, format, INT_MAX);
        snprintf(string2, n, format, INT_MAX);
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
		free(string2);
    }
    // test 3 - LLONG_MAX 
    {
        int n = 30;
        char *string = malloc(n);
        char *string2 = malloc(n);
        
        char *format = "%llX";

        my_snprintf(string, n, format, LLONG_MAX);
        snprintf(string2, n, format, LLONG_MAX);
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
		free(string2);
    } 
    // test 4 - LLONG_MIN
    {
        int n = 30;
        char *string = malloc(n);
        char *string2 = malloc(n);
        
        char *format = "%llX";

        my_snprintf(string, n, format, LLONG_MIN);
        snprintf(string2, n, format, LLONG_MIN);
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
		free(string2);
    } 
    // test 5 - ULLONG_MAX
    {
        int n = 30;
        char *string = malloc(n);
        char *string2 = malloc(n);
        
        char *format = "%llX";

        my_snprintf(string, n, format, ULLONG_MAX);
        snprintf(string2, n, format, ULLONG_MAX);
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
		free(string2);
    }
    // test 6 - 0
    {
        int n = 30;
        char *string = malloc(n);
        char *string2 = malloc(n);
        
        char *format = "%llX";

        my_snprintf(string, n, format, 0);
        snprintf(string2, n, format, 0);
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
		free(string2);
    }
}

int main(void)
{
	//test_num_to_string();
    test_snprintf();
}