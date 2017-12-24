#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_snprintf.h"




int main(void)
{
	int n = 10;
	//long long int n = 0xF3FFA;
	char *buf = calloc(20,sizeof(char));
	num_to_string(&n, buf, 10);
    /* // test 1 - тестируем %d 
	{
		int n = 5;
		char *string = malloc(n);
		char *string2 = malloc(n);
		
		char *format = "I am %d ""years"" old";

		int k = my_snprintf(string, n, format, 120, NULL);
		int k1 = snprintf(string2, n, format, 120, NULL);

		printf("%s# %d\n%s# %d\n", string, k, string2, k1);
	} */
}