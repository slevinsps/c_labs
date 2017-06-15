#include "sum_proizved.h"

int sum_proizved(const int* pb,const int* pe)
{
    int sum = 0;
    const int *left_border = pb;
    const int *right_border = pe;
    while(pe>=left_border && right_border>=pb)
    {
        if (*left_border < 0)
        {
            if (*right_border > 0)
            {
                sum += (*right_border)*(*left_border);
                right_border--;
                left_border++;
            }
            else
            {
                right_border--;
            }
        }
        else
        {
            left_border++;
        }
    }    
    return sum;
}