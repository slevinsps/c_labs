#ifndef BINARY_SORT
#define BINARY_SORT
#include <stdio.h>


#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif


#define ARR_DECL __cdecl

typedef  int(*comparator)(const void*, const void*); 

ARR_DLL void ARR_DECL swap(void *a, void *b, size_t size);
ARR_DLL void* ARR_DECL binary_search(void *first, void *right, size_t size, comparator compare);
ARR_DLL void  ARR_DECL mysort(void *first, size_t number, size_t size, comparator compare);
#endif // BINARY_SORT