# ifndef FIND_REPLACE
# define FIND_REPLACE
//#define _GNU_SOURCE
//#include <unistd.h>

int find_underline(const char *source, const char *search, int *pos1, int *pos2, int pos_begin);
char* str_replace(const char *source, const char *search, const char *replace);
size_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream);
size_t my_getline(char **lineptr, size_t *n, FILE *stream);

# endif // FIND_REPLACE