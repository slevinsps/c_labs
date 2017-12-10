#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_snprintf.h"




int main(void)
{
	int n = 5;
	char *string = malloc(n);
	char *string2 = malloc(n);
	char *format = "hello  %llX %d   ";
	//char *format = "%d%d%d%%%s";
	
	
	long long a = 0xFF;
	my_snprintf(string, n, format, a, 12, NULL);
	snprintf(string2, n, format, a, 12, NULL);
	printf("%s#\n", string);
	printf("%s#", string2);
	//my_snprintf(string, n, format, 5, 6, 7,"GREAT", NULL);
	
}