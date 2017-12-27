# ifndef FUNC
# define FUNC
int count_numbers(int n, int base);
void num_to_string(void *num, int kol, char *buf, int k);
int read_specificators(const char *format, int *counter);
void to_upp(char *s);
int my_snprintf(char *string, size_t n, const char *format, ...);

# endif // FUNC