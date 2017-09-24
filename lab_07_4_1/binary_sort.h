#ifndef BINARY_SORT
#define BINARY_SORT

typedef  int(*comparator)(const void*, const void*); 

void swap(void *a, void *b,size_t size);
void* binary_search(void *first,void *right, size_t size,comparator compare);
void mysort(void * first, size_t number, size_t size, comparator compare);
#endif // BINARY_SORT