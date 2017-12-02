#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# ifndef FUNC
# define FUNC

int check_affiliation(char ch, const char *string2);
size_t my_strspn( const char *string1, const char *string2);
char *my_strdup(const char *str1);

# endif // FUNC