#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#include "standart_func.h"

void test_my_strspn(void)
{
	{
		// 1 search > source
		char source[] = "12-йгод";
		char search[] = "1234567890";
		
		if (my_strspn(source,search) == strspn(source, search))
			printf("test 1 in my_strspn PASSED\n");
		else
			printf("test 1 in my_strspn FAILED\n");
	}
	{
		// 2 search < source
		char source[] = "0123456789";
		char search[] = "210";
		
		if (my_strspn(source,search) == strspn(source, search))
			printf("test 2 in my_strspn PASSED\n");
		else
			printf("test 2 in my_strspn FAILED\n");
	}
	{
		// 3 нет вхождений
		char source[] = "0123456789";
		char search[] = "35";
		
		if (my_strspn(source,search) == strspn(source, search))
			printf("test 3 in my_strspn PASSED\n");
		else
			printf("test 3 in my_strspn FAILED\n");
	}
	{
		// 4 search = source
		char source[] = "0123456789";
		char search[] = "0123456789";
		
		if (my_strspn(source,search) == strspn(source, search))
			printf("test 4 in my_strspn PASSED\n");
		else
			printf("test 4 in my_strspn FAILED\n");
	}
	{
		// 5 search пустой
		char source[] = "0123456789";
		char search[] = "";
		
		if (my_strspn(source,search) == strspn(source, search))
			printf("test 5 in my_strspn PASSED\n");
		else
			printf("test 5 in my_strspn FAILED\n");
	}
}

void test_my_strdup(void)
{
	{
		// 1 test
		char *source = "12-йгод";
		char *s1 = my_strdup(source);
		char *s2 = strdup(source);
		if (strcmp(s1, s2) == 0)
			printf("test 1 in my_strdup PASSED\n");
		else
			printf("test 1 in my_strdup FAILED\n");
	}
	{
		// 2 test один символ
		char *source = "g";
		char *s1 = my_strdup(source);
		char *s2 = strdup(source);
		if (strcmp(s1, s2) == 0)
			printf("test 2 in my_strdup PASSED\n");
		else
			printf("test 2 in my_strdup FAILED\n");
	}
	{
		// 3 test пустая строка
		char *source = "";
		char *s1 = my_strdup(source);
		char *s2 = strdup(source);
		if (strcmp(s1, s2) == 0)
			printf("test 3 in my_strdup PASSED\n");
		else
			printf("test 3 in my_strdup FAILED\n");
	}
}


	
int main(void)
{
	test_my_strspn();
	test_my_strdup();
}