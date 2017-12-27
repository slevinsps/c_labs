#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define  SPEC_d 1 
#define  SPEC_s 2 
#define  SPEC_llX 3 
#define  SPEC_per 4 
#define  ERROR -1 
#define  MAX_LEN_BUFFER 40 
#define  BASE_10 10 
#define  BASE_16 16 

int read_specificators(const char *format, int *counter)
{
    int len = strlen(format);
    
    if (len >= 2 && format[0] == '%' && format[1] == 'd')
    {
        (*counter) += 2;
        return SPEC_d;
    }
    else if (len >= 2 && format[0] == '%' && format[1] == 's')
    {
        (*counter) += 2;
        return SPEC_s;
    }
    else if (len >= 4 && format[0] == '%' && format[1] == 'l' && format[2] == 'l' && format[3] == 'X')
    {    
        (*counter) += 4;
        return SPEC_llX;
    }
    else if (len >= 2 && format[0] == '%' && format[1] == '%')
    {
        (*counter) += 2;
        return SPEC_per;
    }
    else
        return ERROR;
}

void to_upp(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        s[i] = toupper(s[i]);
    }
}


int count_numbers(unsigned long long int n, int base)
{
    int i = 0;
	if (n == 0)
		return 1;
    while (n)
    {
		//printf("!! %d \n", n);
        n /= base;
		
        i++;
    } 
    return i;
}

void num_to_string(unsigned long long int num, int kol, char *buf, int base)
{
    //printf("## %d\n", kol );
    int i;
    i = kol - 1;
	
	
    if (base == BASE_10 && num < 0)        
    {
		//printf("!!!! %llX\n", num);
        i++;
        buf[0] = '-';
        num *= -1;
    }
    buf[i + 1] = 0;
	if (num == 0)
		buf[i] = '0';
    while (num)
    {
        int digit = num % base;
		if (digit < 0 && base == BASE_16)
			digit *= -1;
        //printf("%llx && &^%llx\n", num , digit);
        if (digit < 0xA)
            buf[i] = digit + '0';
        else
            buf[i] = digit + 'A' - 0xA;
        num /= base;
        i--;
    }    
}


int my_snprintf(char *string, size_t n, const char *format, ...)
{
    int kol;
    if (n == 0 || !string || !format)
    {
        return 0;
    }
    va_list vl;
    va_start(vl, format);
    int num_int;
    char *num_char;
    long long int num_hex;
    string[0] = 0;
    int len_format = strlen(format);
    
    //char *res_string = calloc(2 * len_format, sizeof(char));
    int counter = 0;
    int i = 0;
    int specif;
    //char *buf = calloc(20, sizeof(char));
    char buf[MAX_LEN_BUFFER];
    
    while (counter < len_format)
    {
        if (i >= n - 1)
            break;
        if (format[counter] != '%')
        {
            string[i++] = format[counter];
            string[i] = 0;
            counter++;
        }
        else
        {
            specif = read_specificators(format + counter, &counter);
            
            if (specif == SPEC_d)
            {            
                num_int = va_arg(vl, int);
                //itoa(num_int, buf, 10);
                kol = count_numbers(num_int, BASE_10);
                num_to_string(num_int, kol, buf, BASE_10);
                strncat(string, buf, n - i - 1);
                i = strlen(string);
            }
            else if (specif == SPEC_s)
            {
                num_char = va_arg(vl, char*);
                strncat(string, num_char, n - i - 1);
                i = strlen(string);
            }
            else if (specif == SPEC_llX)
            {
                num_hex = va_arg(vl, long long int);
                kol = count_numbers(num_hex, BASE_16);
                printf("## %llX   %d\n", num_hex, kol );
                num_to_string(num_hex, kol, buf, BASE_16);
                to_upp(buf);
                //strcat(string, buf);
                strncat(string, buf, n - i - 1);
                i = strlen(string);
            }
            else if (specif == SPEC_per)
            {
                string[i++] = '%';
                string[i] = 0;
            }
            else
            {
                //free(res_string);    
                //free(buf);
                return ERROR;
            }
        }
    } 
    string[n - 1] = 0;    
    //free(buf);    
    return strlen(string);
}