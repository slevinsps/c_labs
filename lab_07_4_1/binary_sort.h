#ifndef BINARY_SORT
#define BINARY_SORT

void swap(void *a, void *b,size_t size);
void* binary_search(void *first,void *right, size_t size,int (*compare)(const void*, const void*));
void binary_insert(void * first, size_t number, size_t size,int (*compare)(const void*, const void*));

#endif // BINARY_SORT