#include <stdio.h>

#define AP_IN_ENTR 36 // квартир в подъезде
#define AP_ON_FLOOR 4 // квартир на этаже

// Программа по номеру квартиры подсчитывает номер подъезда и этажа
int main(void)
{
    int apart; // вводимый номер квартиры
    int number_entr; // номер подъезда
    int number_floor; // номер этажа

    setbuf(stdout,NULL);
    printf("Enter number of flat: ");
    scanf("%d", &apart);
    number_entr = (apart - 1) / AP_IN_ENTR + 1;
    number_floor = ((apart - 1) % AP_IN_ENTR) / AP_ON_FLOOR + 1;

    printf("Entrance number = %d\n", number_entr);
    printf("Floor number = %d", number_floor);
    return 0;
}
