#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NUMBER_ITEMS 10

#define OK 0
#define NO_FILE -1
#define ARRAY_EMPTY -2
#define UNCORRECT_NUMBERS -3
#define UNCORRECT_CHOICE -4
#define NUMBER_ITEMS_EXCEEDED -5
#define NO_ODD_NUMBER -6
#define NO_EVEN_NUMBER -7
#define ALL_NEGATIVE -8
#define ALL_POSITIVE -9
#define NO_ELEMENT_IN_ARRAY -10
#define NO_ELEMENT_DIV_3 -11
#define NO_ELEMENT_ENDING_3 -12

int read_array(int **pb, int **pe)
{
    int err = OK;
    while((*pe-*pb < NUMBER_ITEMS) && (scanf("%d",*pe) == 1))
    {
        *pe = *pe + 1;
    }

    if (*pe == *pb)
    {
        err = ARRAY_EMPTY;
    }
    fflush(stdin);
    return err;        
}


int menu(int *k)
{
    int err;
    printf("Меню:\n1 - нахождения суммы четных и произведения нечетных элементов массива\n\
2 - перезаписи в другой массив всех элементов, которые больше среднего арифметического элементов исходного массива\n\
3 - удаления из массива всех отрицательных элементов\n\
4 - добавления после элементов, значение которых равно указанному числу, суммы элементов, предшествующих ему\n\
5 - обмена в массиве максимального элемента среди четных и минимального элемента среди нечетных\n\
6 - записи на место максимального элемента, кратного 3, суммы элементов, заканчивающихся на 3\n\
7 - упорядочивания элементов, расположенных между минимальным и максимальным элементами массива (включая эти элементы)\n");
    printf("\nYour choice: ");
    if (scanf("%d",k) == 1)
    {
        err = OK;
    }
    else
    {
        err = UNCORRECT_CHOICE;
    }
    return err;
}

int sum_and_proizved(int *pb,int *pe,int *sum,int *proizved)
{
    int err = OK;
    int counter_even = 0;
    int counter_odd = 0;
    *sum = 0;
    *proizved = 1;
    while(pe>=pb)
    {
        if (*pb % 2 == 0)
        {
            *sum = *sum + *pb;
            counter_even = 1;
        }
        else
        {
            *proizved = (*proizved)*(*pb); 
            counter_odd = 1;
        }
        pb = pb + 1;
    }
    
    if (counter_even == 0)
        err = NO_EVEN_NUMBER;
    if (counter_odd == 0)
        err = NO_ODD_NUMBER;
    return err;
}

int summ_elements(int *pb,int *pe)
{
    int sum = 0;
    int *ppb = pb;
    while(pe>=ppb)
    {
        sum = sum + *ppb;
        ppb = ppb + 1;
    }
    return sum;    
}

int more_arithmetic_mean(int *pb,int *pe, int **bb, int **be,int n)
{
    int err = OK;
    int sum = 0;
    int srednee = 0;
    *bb = *be;
    sum = summ_elements(pb,pe);
    srednee = sum / n;
    while(pe>=pb)
    {
        if (*pb>srednee)
        {
            **be = *pb;
            *be = *be + 1;  
        }
        pb = pb + 1;
    }
    if (*be == *bb)
    {
        err = ARRAY_EMPTY;
    }
    *be = *be - 1;
    return err; 
}



void delete_element(int *number, int **pb, int **pe)
{
    int *ppb;
    ppb = number;
    while(*pe>ppb)
    {
        *ppb = *(ppb+1);
        ppb = ppb + 1;
    }    
    *pe = *pe - 1;
}

int delete_negative(int **pb,int **pe)
{
    int err = OK;
    int *begin = *pb;
    int n;
    
    *pe = *pe - 1;
    n = *pe-*pb;
    
    while(*pe>=begin)
    {
        if (*begin < 0)
        {
            delete_element(begin, pb, pe);    
        }
        else
        {
            begin = begin + 1;
        }
    }   
    
    if (*pe-*pb == n)
        err = ALL_POSITIVE;

    if (*pe - *pb == -1)
        err = ALL_NEGATIVE;
    
    return err;
}


void add_element(int *number, int **pb, int **pe,int element)
{
    int *ppe;
    *pe = *pe + 1;
    ppe = *pe;
    while(ppe>number)
    {
        *ppe = *(ppe-1);
        ppe = ppe - 1;
    }
    *(number+1) = element;
}

int add_sum(int **pb,int **pe,int k)
{
    int err = OK;
    int check_existence = 0;
    int *begin = *pb; 
    int sum = 0;
    
    *pe = *pe - 1;
    while(*pe>=begin)
    {
        if (*begin == k)
        {
            check_existence = 1;
            add_element(begin, pb, pe,sum);
            sum = sum + *begin;
            begin = begin + 2;
        }
        else
        {
            sum = sum + *begin;
            begin = begin + 1;
        }
    }
    if (check_existence == 0)
        err = NO_ELEMENT_IN_ARRAY;
    return err;
}
    

void replace_elements(int *pb,int *pe,int e1i,int e2i,int e1,int e2)
{
    int k = 1;
    while(pe>=pb)
    {
        if (k == e1i)
            *pb = e2;
        if (k == e2i)
            *pb = e1;
        k++;
        pb = pb + 1;
    }
}
    
int replace_min_max(int *pb,int *pe)
{

    int err = OK;
    int k = 1;
    int *ppb = pb;
    
    int min = 2; // среди нечетных => 2 не может быть равно
    int max = 1; // среди четных => 1 не может быть равно
    int mini = -1;
    int maxi = -1;
    
    int counter_even = 0;
    int counter_odd = 0;
    
    
    while(pe>=ppb)
    {
        if (*ppb % 2 == 0)
        {
            if (max == 1) // инициализация первого максимума
            {
                max = *ppb;
                maxi = k;
            }
            else
            {
                if (*ppb > max)
                {
                    max = *ppb;
                    maxi = k;
                }
            }
            counter_even = 1;
        }
        else
        {
            if (min == 2) // инициализация первого минимума
            {
                min = *ppb;
                mini = k;
            }
            else
            {
                if (*ppb < min)
                {
                    min = *ppb;
                    mini = k;
                }
            }
            counter_odd = 1;
        }
        k++;
        ppb = ppb + 1;
    }
    
    if (counter_even == 0)
        err = NO_EVEN_NUMBER;
    if (counter_odd == 0)
        err = NO_ODD_NUMBER;
    if (err == OK)    
        replace_elements(pb,pe,mini,maxi,min,max);
    
    return err;
}

int div_into_three(int *pb,int *pe)
{
    int err = OK;
    int k = 1;
    int *ppb = pb;
    int max;
    int maxi = 0;
    int check_initialization = 0;
    int check_div_three = 0;
    int check_ending_three = 0;
    int sum = 0;
    while(pe>=ppb)
    {
        if (*ppb % 3 == 0)
        {
            if (check_initialization == 0)
            {
                max = *ppb;
                maxi = k;
                check_initialization = 1;
                check_div_three = 1;
            }
            else
            {
                if (*ppb > max)
                {
                    max = *ppb;
                    maxi = k;
                }
            }
        }
        
        if (*ppb % 10 == 3)
        {
            check_ending_three = 1;
            sum = sum + *ppb;
        }
        k++;
        ppb = ppb + 1;
    }
    if (check_div_three == 0)
        err  = NO_ELEMENT_DIV_3;
    if (check_ending_three == 0)
        err = NO_ELEMENT_ENDING_3;
    if (err == OK)
    {
        k = 1;
        while(pe>=pb)
        {
            if (k == maxi)
                *pb = sum;
            k++;
            pb = pb + 1;
        }
    }
    return err;
}



void bubble_sort(int **pb, int **pe)
{
    int elem;
    int n = *pe - *pb;
    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<=n; j++) 
        {
            if (*(*pb+i) > *(*pb+j))
            {
                elem = *(*pb+i);
                *(*pb+i) = *(*pb+j);
                *(*pb+j) = elem;
            }
        }
    }
}

void sort_min_max(int **pb, int **pe)
{
    int *k;
    int *ppb = *pb;
    
    int *min = *pb; 
    int *max = *pb;
        
    while(*pe>ppb)
    {
        if (*ppb > *max)
        {
            max = ppb;

        }
        
        if (*ppb < *min)
        {
            min = ppb;
        }
        
        ppb = ppb + 1;
    }
    if (min > max)
    {
        k = min;
        min = max;
        max = k;
    }
    bubble_sort(&min, &max);
}
    

int main()
{
    setbuf(stdout,NULL);
    int err = OK;
    int err_in_function = OK;
    int n;
    int a[2*NUMBER_ITEMS];
    int *pb = a;
    int *pe = a;
    int b[NUMBER_ITEMS];
    int *bb = b;
    int *be = b;
    int choice = 1;
    int sum = 0;
    int proizved = 1;
    int number;
    err = menu(&choice);
    if (err == OK)
    {
        printf("The maximum number of elements is %d\nYou can finish typing by typing a letter\nEnter the elements of the array into a column:\n",NUMBER_ITEMS);
        err = read_array(&pb, &pe);
        n = pe-pb;
        if (err == ARRAY_EMPTY)
        {
            printf("Array is empty");    
        }
        else
        {
            if (err == NUMBER_ITEMS_EXCEEDED)
            {
                printf("The number of elements exceeded %d\n",n);
            }
            else
            {        
                switch(choice)
                {
                    case 1:
                        
                        err_in_function = sum_and_proizved(pb,pe-1,&sum,&proizved);
                        if (err_in_function == NO_EVEN_NUMBER)
                        {
                            printf("No even number\n");
                            printf("The product of odd numbers = %d",proizved);
                        }
                        else
                        {
                            if (err_in_function == NO_ODD_NUMBER)
                            {
                                printf("No odd number\n");
                                printf("The summ of even numbers = %d",sum);
                            }
                            else
                                printf("The summ of even numbers = %d;\nThe product of odd numbers = %d",sum,proizved);
                        }
                        break;
                        
                    case 2:
                        err_in_function = more_arithmetic_mean(pb,pe-1,&bb,&be,n);
                        if (err_in_function == ARRAY_EMPTY)
                        {
                            printf("There are no elements larger than the arithmetic mean");
                        }
                        else
                        {
                            printf("Array of elements of large mean value:\n");
                            while(be>=bb)
                            {
                                printf("%d ",*bb);
                                bb = bb + 1;
                            }
                        }
                        break;        
                    case 3:
                        err_in_function = delete_negative(&pb,&pe);
                        if (err_in_function == ALL_NEGATIVE)
                            printf("All elements negative");
                        else
                        {
                            if (err_in_function == ALL_POSITIVE)
                                printf("All elements positive\n");
                            while(pe>=pb)
                            {
                                printf("%d ",*pb);
                                pb = pb + 1;
                            }
                        }

                        break;    
                    case 4:
                        printf("Enter number: ");
                        if (scanf("%d",&number) == 1)
                        {
                            err_in_function = add_sum(&pb,&pe,number);
                            if (err_in_function == NO_ELEMENT_IN_ARRAY)
                                printf("There is no element in the array");
                            else
                            {
                                printf("New array:\n");
                                while(pe>=pb)
                                {
                                    printf("%d ",*pb);
                                    pb = pb + 1;
                                }
                            }
                        }
                        else 
                            err = UNCORRECT_CHOICE;
                        break;
                        
                    case 5:
                        err_in_function = replace_min_max(pb,pe-1);
                        if (err_in_function == NO_EVEN_NUMBER)
                        {
                            printf("No even numbers\n");
                        }
                        else
                        {
                            if (err_in_function == NO_ODD_NUMBER)
                            {
                                printf("No odd numbers\n");
                            }
                            else
                            {
                                printf("New array:\n");
                                while(pe>pb)
                                {    
                                    printf("%d ",*pb);
                                    pb = pb + 1;
                                }
                            }
                        }
                        break;    
                    case 6:
                        err_in_function = div_into_three(pb,pe-1);
                        if (err_in_function == NO_ELEMENT_DIV_3)
                            printf("No elements dividing by 3");
                        else
                        {
                            if (err_in_function == NO_ELEMENT_ENDING_3)
                                printf("No elements ending by 3");
                            else
                            {
                                printf("New array:\n");
                                while(pe>pb)
                                {
                                    printf("%d ",*pb);
                                    pb = pb + 1;
                                }
                            }
                        }
                        break;
                    case 7:
                        sort_min_max(&pb, &pe);
                        printf("Array:\n");

                        while(pe>pb)
                        {
                            printf("%d ",*pb);
                            pb = pb + 1;
                        }
                        break;
                }
                
            }
        }  
    }
    return err;
}