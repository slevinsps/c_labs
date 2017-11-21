#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"

int strlen1(const char *string)
{
    int k = 0;
    if (string)
    {    
        while (string[k] != 0)
            k++;
    }
    return k;
}
