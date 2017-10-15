#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strrchr1( const char *string, int symbol)
{
	char symb = (char)symbol;
	char *last = NULL;
	for (int i = 0; string[i] != 0; i++)
	{
		if (string[i] == symb)
			last = (char*)(string + i);
	}
	return last;
}


int main(void)
{
	char str[] = "13246789";
    char *pch = strrchr1(str,'8');
	printf("%I64d    %c",pch - str,*pch);
	return 0;
}