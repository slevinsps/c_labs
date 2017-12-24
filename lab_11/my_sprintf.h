# ifndef FUNC
# define FUNC
void num_to_string(void *num, char *buf, int k);
int read_specificators(const char *format, int *counter);
void to_upp(char *s);
int my_sprintf(char *string, size_t n, const char *format, ...);

# endif // FUNC