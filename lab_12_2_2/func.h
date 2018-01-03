#ifndef FUNC
#define FUNC
#include <stdio.h>


#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL int ARR_DECL fibonachi(int *array, int n);
ARR_DLL int ARR_DECL move_elements(int *array1, int *array2, int n);

#endif // FUNC