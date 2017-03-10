#include <stdio.h>
#include <math.h>
int main(void)
{
    setbuf(stdout,NULL);
    int k; // вводимый номер квартиры
    int k2; // результат остатка от деления k на 36
    int k1; // результат целочисленного деления k на 36
    int e1;
    int e2;
    printf("Enter number of flat: ");
    scanf("%d",&k);
    k1 = k / 36;
    k2 = k % 36;
    if (k2 != 0) // если остаток от деления присутствует, то увеличиваем номер подъезда на 1
    {
        printf("Entrance number: %d\n",k1+1);
    }
    else
    {
        printf("Entrance number: %d\n",k1);
    }
    if (k2 == 0)
    {
        printf("Floor number: 9");
    }
    else
    {
        e1 = k2 / 4;
        e2 = k2 % 4;
        if (e2 != 0) // если остаток от деления присутствует, то увеличиваем номер этажа на 1
        {
            printf("Floor number: %d\n",e1+1);
        }
        else
        {
            printf("Floor number: %d\n",e1);
        }
    }

    return 0;
}
