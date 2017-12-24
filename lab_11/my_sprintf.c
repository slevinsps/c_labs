#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int read_specificators(const char *format, int *counter)
{
    int len = strlen(format);
    
    if (len >= 2 && format[0] == '%' && format[1] == 'd')
    {
        (*counter) += 2;
        return 1;
    }
    else if (len >= 2 && format[0] == '%' && format[1] == 's')
    {
        (*counter) += 2;
        return 2;
    }
    else if (len >= 4 && format[0] == '%' && format[1] == 'l' && format[2] == 'l' && format[3] == 'X')
    {    
        (*counter) += 4;
        return 3;
    }
    else if (len >= 2 && format[0] == '%' && format[1] == '%')
    {
        (*counter) += 2;
        return 4;
    }
    else
        return -1;
}

void to_upp(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        s[i] = toupper(s[i]);
    }
}


int count_dec_numbers(int n)
{
    int i = 0;
    while (n)
    {
        n /= 10;
        i++;
    }
    return i;
}

int count_hex_numbers(int n)
{
    int i = 0;
    while (n)
    {
        n /= 16;
        i++;
    }
    return i;
}

void num_to_string(void *num, char *buf, int base)
{
    int i;
    int num1;
    if (base == 16)
    {
        num1 = *(long long int *)num;
        i = count_hex_numbers(num1) - 1;
    }
    else
    {
        num1 = *(int *)num;
        i = count_dec_numbers(num1) - 1;
    }
	
	if (num1 < 0)
	{
		i++;
		buf[0] = '-';
		num1 *= -1;
	}
    buf[i + 1] = 0;
    while (num1)
    {
        int digit = num1 % base;
        
        if (digit < 0xA)
            buf[i] = (num1 % base) + '0';
        else
            buf[i] = (num1 % base) + 'A' - 0xA;
        num1 /= base;
        i--;
    }	
}


int my_sprintf(char *string, size_t n, const char *format, ...)
{
    if (n == 0 || !string || !format)
    {
        return 0;
    }
    va_list vl;
    va_start(vl, format);
    int num_int;
    char *num_char;
    long long int num_hex;
    
    int len_format = strlen(format);
    
    char *res_string = calloc(2 * len_format, sizeof(char));
    int counter = 0;
    int i = 0;
    int specif;
    char *buf = calloc(20, sizeof(char));
    while (counter < len_format)
    {
        if (format[counter] != '%')
        {
            res_string[i++] = format[counter];
            counter++;
        }
        else
        {
            specif = read_specificators(format + counter, &counter);
            
            if (specif == 1)
            {            
                num_int = va_arg(vl, int);
                //itoa(num_int, buf, 10);
                num_to_string(&num_int, buf, 10);
                strcat(res_string, buf);
                i = strlen(res_string);
            }
            else if (specif == 2)
            {
                num_char = va_arg(vl, char*);
                strcat(res_string, num_char);
                i = strlen(res_string);
            }
            else if (specif == 3)
            {
                num_hex = va_arg(vl, long long int);
                //printf("%I64X", num_hex);
                num_to_string(&num_hex, buf, 16);
                to_upp(buf);
                strcat(res_string, buf);
                i = strlen(res_string);
            }
            else if (specif == 4)
            {
                res_string[i++] = '%';
            }
            else
            {
                free(res_string);    
                free(buf);
                return -1;
            }
        }
    }
    //printf("%s", res_string);
    int len_res = strlen(res_string);
    if (len_res >= n - 1)
    {
        memmove(string, res_string, n - 1);
        string[n - 1] = 0;
        len_res = n - 1;
    }
    else
    {
        memmove(string, res_string, len_res);
        string[len_res] = 0;
    }
    free(res_string);    
    free(buf);    
    return len_res;
}