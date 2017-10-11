# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "str.h"
# include "sort.h"


void input(char s[]) 
{
    int i, c;
    i = 0;
    while ((c = getchar()) != '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}


int main(void)
{
	int n;
	char s[100];
	setbuf(stdout,NULL);
	
	
	printf("Введите строку:\n");
	input(s);
	n = count_words(s);
    char **words = malloc(n*sizeof(char *));
    split_words(s, words);
	sort(words, n);
	for(int i = 0; i < n;i++)
		printf("%s ", words[i]);

}