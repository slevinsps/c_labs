#include <stdio.h>

#define AP_IN_ENTR 36 // квартир в подъезде
#define AP_ON_FLOOR 4 // квартир на этаже

// Программа по номеру квартиры подсчитывает номер подъезда и этажа
int main(void)
{
    setbuf(stdout,NULL);
    int k; // вводимый номер квартиры
    int np; // номер подъезда
    int ne; // номер этажа
    printf("Enter number of flat: ");
    scanf("%d", &k);
    np = (k - 1) / AP_IN_ENTR + 1;
    ne = ((k - 1) % AP_IN_ENTR) / AP_ON_FLOOR + 1;
    printf("Entrance number = %d\n", np);
    printf("Floor number = %d", ne);
    return 0;
}
