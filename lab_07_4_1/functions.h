#ifndef FUNCTIONS
#define FUNCTIONS

int count_numbers(FILE *f);
int read_array(FILE *f, int **pb, int **pe, int k);
void print_array(const int* pb,const int* pe,FILE *f);
void swap(void *a, void *b,size_t size);
void binary_insert(void * first, size_t number, size_t size,int (*compare)(const void*, const void*));
void search_min_max(int *pb, int const *const pe, int **ppb, int **ppe);
int rewrite_array(int *min,int *max,int **new_begin, int **new_end);

#endif // FUNCTIONS