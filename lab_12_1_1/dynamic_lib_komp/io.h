#ifndef IO
#define IO
#include <stdio.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL int ARR_DECL read_array(FILE *f, int *pb, int **pe, int k);
ARR_DLL void ARR_DECL print_array(const int *pb, const int *pe, FILE *f);

#endif // IO