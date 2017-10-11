# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# include "str.h"
# include "sort.h"

# define SEPP ",.?!" 

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


void gost(char s[],char s2[]) // функция ГОСТ
{
	int len = strlen(s);
	int k = 0;
	int counter = 0;
	s[0] = toupper(s[0]);
	for (int i = 0; i < len-1;i++)
	{
		
		if (s[i] == ' ')
		{
			k++;
			if (k == 1)
			{
				
				s2[counter] = s[i];
				counter++;
			}
	    }
		else
		{
			k = 0;
			s2[counter] = s[i];
			counter++;
		}
		
	}
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
	
	

	char s2[] = "hello      hjhjhj,  kljlk!";
	char s3[strlen(s2)];
	gost(s2,s3);
	printf("%s",s3);

}