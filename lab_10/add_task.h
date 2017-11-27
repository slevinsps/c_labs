#ifndef ADD_TASK
#define ADD_TASK

const char *strchr1(const char *str, char symbol);
int count_words(const char *str);
void split_words(char *str, char **words, int ind);
void load_list_int(node_t *head, char **words, int n);
int comp1(const void *a, const void *b);
void print_list(FILE *f, node_t *head);
void read_text(FILE *f, char ***words, int *n);

#endif // ADD_TASK