
#include <stdio.h>
#include <string.h>
#include <errno.h>


#define NUMBER_ITEMS 10



#define ARRAY_EMPTY -2

#define NUMBER_ITEMS_EXCEEDED -4
    
#define OK 0
#define NO_FILE -1

#define UNCORRECT_NUMBERS -3
#define UNCORRECT_CHOICE -4
   
int read_array(int **pb, int **pe, int n)
{
    int err = OK;
    while((*pe-*pb < n) && (scanf("%d",*pe) == 1))
    {
        *pe = *pe + 1;
    }

    if (*pe == *pb)
    {
        err = ARRAY_EMPTY;
    }
    
    if (*pe-*pb > n)
    {
		
        err = NUMBER_ITEMS_EXCEEDED;
    }
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
        err = OK;
    else
        err = UNCORRECT_CHOICE;
    return err;
}

void sum_and_proizved(int *pb,int *pe,int *sum,int *proizved)
{

    *sum = 0;
    *proizved = 1;
    while(pe>=pb)
    {
        if (*pb % 2 == 0)
        {
            *sum = (*sum)+(*pb);
        }
        else
        {
            *proizved = (*proizved)*(*pb); 
        }

        pb = pb + 1;
    }
}

void more_arithmetic_mean(int *pb,int *pe,int **bb, int **be,int n)
{

    int sum = 0;
    int srednee = 0;
    int k = 0;
    int *ppb = pb;
    while(pe>=ppb)
    {
        sum = sum + *ppb;
        ppb = ppb + 1;
    }
    srednee = sum / n;
    while(pe>=pb)
    {
        if (*pb>srednee)
        {
            if (k == 0)
            {
                **bb = *pb;
                **be = *pb;
                k = 1;
            }
            else
            {
                *be = *be + 1;
                **be = *pb;
            }
        }
        pb = pb + 1;
    }
}

void delete(int **pb,int **pe)
{
	*pe = *pe - 1;
    int *begin = *pb;
    int *ppb;
    while(*pe>=begin)
    {
        
        if (*begin < 0)
        {
            ppb = begin;
            while(*pe>ppb)
            {
                *ppb = *(ppb+1);
                ppb = ppb + 1;
            }
            *pe = *pe - 1;
        }
        else
        {
            begin = begin + 1;
        }
    }        
}

void add_sum(int **pb,int **pe,int k)
{
	*pe = *pe - 1;
    int *begin = *pb;
    int *ppe;
    int sum = 0;
    while(*pe>=begin)
    {
        
        if (*begin == k)
        {
            *pe = *pe + 1;
            ppe = *pe;
            while(ppe>begin)
            {
                *ppe = *(ppe-1);
                ppe = ppe - 1;
            }
            *(begin+1) = sum;
            sum = sum + *begin;
            begin = begin + 2;
            /*
            while (*pe>=*pb)
            {
                printf("%d ",**pb);
                *pb = *pb + 1;
            }
            */
        }
        else
        {
            sum = sum + *begin;
            begin = begin + 1;
        }
    }
}
    
    
void replace(int *pb,int *pe)
{
    int k = 1;
    int *ppb = pb;
    int min = *pb;
    int max = *(pb+1);
    int mini = 1;
    int maxi = 2;
    while(pe>=ppb)
    {
        if (*ppb % 2 == 0)
        {
            if (*ppb > max)
            {
                max = *ppb;
                maxi = k;
            }
        }
        else
        {
            if (*ppb < min)
            {
                min = *ppb;
                mini = k;
            }
        }
        k++;
        ppb = ppb + 1;
    }
    k = 1;
    while(pe>=pb)
    {
        if (k == mini)
            *pb = max;
        if (k == maxi)
            *pb = min;
        k++;
        pb = pb + 1;
    }
}

void div_into_three(int *pb,int *pe)
{
    int k = 1;
    int *ppb = pb;
    int max;
    int maxi = 0;
    int kk = 0;
    int sum = 0;
    while(pe>=ppb)
    {
        if (*ppb % 3 == 0)
        {
            
            if (kk == 0)
            {
                max = *ppb;
                maxi = k;
                kk = 1;
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
            
            sum = sum + *ppb;
        }
        k++;
        ppb = ppb + 1;
    }
    k = 1;
    while(pe>=pb)
    {
        if (k == maxi)
            *pb = sum;
        k++;
        pb = pb + 1;
    }
}


void sort(int a[], int n)
{
    int maxi = 0;
    int mini = 0;
    int k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[maxi])
        {
            maxi = i;
        }
        if (a[i] < a[mini])
        {
            mini = i;
        }
    }
    
    if (mini > maxi)
    {
        k = mini;
        mini = maxi;
        maxi = k;
    }
    for (int i = mini; i<maxi; i++)
    {
        for (int j = i+1; j<=maxi; j++) 
        {
            if (a[i]>a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
        
    }
}



int main()
{
    setbuf(stdout,NULL);
    int err = OK;
    int n;
    printf("Enter numbres of elements 1<=n<=%d: ",NUMBER_ITEMS);
    if (scanf("%d",&n) == 1  && n<=NUMBER_ITEMS && n>0)
    {
        int a[2*n];
        int *pb = a;
        int *pe = a;
        int b[n];
        int *bb = b;
        int *be = b;
        int choice;
        int sum = 0;
        int proizved = 1;
        int number;
        printf("Enter array:\n");
        err = read_array(&pb, &pe,n);
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
				err = menu(&choice);
				if (err == OK)
				{
					switch(choice)
					{
						case 1:
							sum_and_proizved(pb,pe-1,&sum,&proizved);
							printf("Sum = %d; Proivedenie = %d",sum,proizved);
							break;
						case 2:
							more_arithmetic_mean(pb,pe-1,&bb,&be,n);
							printf("Array of elements of large mean value\n");
							while(be>=bb)
							{
								printf("%d ",*bb);
								bb = bb + 1;
							}
							break;        
						case 3:
							delete(&pb,&pe);
							while(pe>=pb)
							{
								printf("%d ",*pb);
								pb = pb + 1;
							}
							break;    
						case 4:
							printf("Enter number: ");
							if (scanf("%d",&number) == 1)
							{
								add_sum(&pb,&pe,number);
								while(pe>=pb)
								{
									printf("%d ",*pb);
									pb = pb + 1;
								}
							}
							else 
								err = UNCORRECT_CHOICE;
							break;
						case 5:
							replace(pb,pe-1);
							while(pe>=pb)
							{
								printf("%d ",*pb);
								pb = pb + 1;
							}
							break;    
						case 6:
							div_into_three(pb,pe-1);
							while(pe>=pb)
							{
								printf("%d ",*pb);
								pb = pb + 1;
							}
						case 7:
							sort(a,n);
							printf("Array:\n");
							while(pe>=pb)
							{
								printf("%d ",*pb);
								pb = pb + 1;
							}
					}
				}
			}
        }    
    }
    else
    {
        printf("Uncorrect numbers");
        err = UNCORRECT_NUMBERS;
    }
    return err;
}