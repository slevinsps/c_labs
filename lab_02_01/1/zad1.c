#include <stdio.h>
#include <math.h>

// Программа которая вычисляет остаток от
// деления и результат целочисленного деления

int Division(int a, int b)
{
    int k = 0;
    while (1)
    {
        if (a < b)
            break;
        a = a - b;
        k++;
    }
    return k;
}

int main(void)
{
    int a, b; // Делимое и делитель
    int x; // Корень целочисленного деления
    while(1)
    {
        setbuf(stdout,NULL);
        printf("Enter a,b\n");
        if (scanf("%d %d", &a, &b) == 0)
        {
            fflush(stdin);
            printf("Uncorrected variables...\n");
            continue;

        }
        if (b == 0)
        {
            printf("Division by zero...\n");
            continue;
        }
        fflush(stdin);
        x = Division(a,b);
        printf("%d / %d = %d; %d %% %d = %d\n",a,b,x,a,b,a-x*b);
        break;
    }
    return 0;
}
