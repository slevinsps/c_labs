#ifndef FUNCTIONS
#define FUNCTIONS
#include <stdio.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL int ARR_DECL count_numbers(FILE *f);
ARR_DLL int ARR_DECL key(const int *pb, const int *pe, int **new_begin, int **new_end);
ARR_DLL int ARR_DECL rewrite_array(int *min, int *max, int **new_begin, int **new_end);

#endif // FUNCTIONS