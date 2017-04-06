#include <stdio.h>
#define DIVISION_BY_ZERO 1

// Программа которая вычисляет остаток от
// деления и результат целочисленного деления

// Функция которая высичляет результат целочисленного деления числа a на b
void division(int a, int b,int *zel_del,int *ost_del)
{	int a1 = a;
    while(a1>=b)
    {
        a1 = a1 - b;
        *zel_del = *zel_del + 1;		
    }
	*ost_del = a-*zel_del*b;	
}

int main(void)
{
    int a, b; // Делимое и делитель
    int zel_del = 0; // Результат целочисленного деления
    int ost_del = 0; // Результат деления с остатком
    int pr; // Счетчик правильно считанных пременных
	setbuf(stdout,NULL);
    // Цикл выполняется пока не будет найдено ошибок ввода
    do
    {       
        printf("Enter a,b\n");
        pr = scanf("%d %d", &a, &b);
        if ( pr != 2)
        {
            fflush(stdin); // Очищаем буфер обмена
            printf("Uncorrected variables...\n");
            continue;

        }  
    }while (pr != 2);
	
	// Проверка деления на 0
	if (b == 0)
        {
            printf("Division by zero...\n");
            return DIVISION_BY_ZERO;
        }
	division(a,b,&zel_del,&ost_del);
    printf("%d / %d = %d; %d %% %d = %d\n",a,b,zel_del,a,b,ost_del);
    return 0;

}
