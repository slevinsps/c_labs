#include <stdio.h>

// Программа которая вычисляет остаток от
// деления и результат целочисленного деления

// Функция которая высичляет результат целочисленного деления числа a на b
int Division(int a, int b)
{
    int zel_del = 0;
    while (1)
    {
        if (a < b)
            break;
        a = a - b;
        zel_del++;
    }
    return zel_del;
}

int main(void)
{
    int a, b; // Делимое и делитель
    int zel_del; // Результат целочисленного деления
    int ost_del; // Результат деления с остатком
    int pr; // Счетчик правильно считанных пременных

    // Цикл выполняется пока не будет найдено ошибок ввода
    while(1)
    {
        setbuf(stdout,NULL);
        printf("Enter a,b\n");
        pr = scanf("%d %d", &a, &b);
        if ( pr != 2)
        {
            fflush(stdin); // Очищаем буфер обмена
            printf("Uncorrected variables...\n");
            continue;

        }
        if (b == 0)
        {
            printf("Division by zero...\n");
            continue;
        }

        zel_del = Division(a,b);
        ost_del = a-zel_del*b;
        printf("%d / %d = %d; %d %% %d = %d\n",a,b,zel_del,a,b,ost_del);
        return 0;
    }

}
