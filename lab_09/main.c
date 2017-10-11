# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int compare(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len_min;
	int k = 1;
	if (len1 <= len2)
		len_min = len1;
	else
		len_min = len2;
	for (int i = 0; i < len_min; i++)
	{
		if (s1[i] < s2[i])
		{
			k = 0;
			break;
		}
	}
	return k;
}

/* void sort(char **words, int n)
{
	for (int )
	
	
} */


int main(void)
{
	
	char *s1 = "првиет";
	char *s2 = "абба";
	printf("%d\n",compare(s1, s2));
	

}