#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "standart_func.h"
#include "find_replace.h"
#include "defines.h"


void test_str_replace(void)
{
    {
        // 1 два вхождения        
        char source[20] = "aaaa";
        char search[20] = "aa";
        char replace[20] = "bbb";
        char expected[20] = "bbbbbb";
        char *actual;
        actual = str_replace(source, search, replace);
        if (actual)
        {
            if (strlen(actual) > 0)
            {
                if (strcmp(expected, actual) == 0)
                    printf("Test 1 in str_replace PASSED\n");
                else
                {
                    printf("Test 1 in str_replace FAILED\n");
                    printf("%s\n", actual);
                }
            }
        }
        free(actual);
    }
    {
        // 2 одно вхождениe
        char *source = "aaaa";
        char *search = "aaaa";
        char *replace = "b";
        
        char *expected = "b";
        char *actual;
        actual = str_replace(source, search, replace);
        if (strcmp(expected, actual) == 0)
            printf("Test 2 in str_replace PASSED\n");
        else
        {
            printf("Test 2 in str_replace FAILED\n");
            printf("%s\n", actual);
        }
        free(actual);
    }    
    {
        // 3 вхождений нет
        char *source = "aaaa";
        char *search = "hello";
        char *replace = "b";
        
        char *expected = "aaaa";
        char *actual;
        actual = str_replace(source, search, replace);
        if (strcmp(expected, actual) == 0)
            printf("Test 3 in str_replace PASSED\n");
        else
        {
            printf("Test 3 in str_replace FAILED\n");
            printf("%s\n", actual);
        }
        free(actual);
    }
    {
        // 4 несколько вхождений
        char *source = "Amy likes sweets Amy? Hey Amy.";
        char *search = "Amy";
        char *replace = "Arnold";
        
        char *expected = "Arnold likes sweets Arnold? Hey Arnold.";
        char *actual;
        actual = str_replace(source, search, replace);
        if (strcmp(expected, actual) == 0)
            printf("Test 4 in str_replace PASSED\n");
        else
        {
            printf("Test 4 in str_replace FAILED\n");
            printf("%s\n", actual);
        }
        free(actual);
    }
    {
        // 5 один из элементов передаваемых в функцию равен NULL
        char *source = "Amy likes sweets Amy? Hey Amy.";
        char *search = NULL;
        char *replace = "Arnold";
        char *actual;
        actual = str_replace(source, search, replace);
        if (!actual)
            printf("Test 5 in str_replace PASSED\n");
        else
        {
            printf("Test 5 in str_replace FAILED\n");
            printf("%s\n", actual);
        }
        free(actual);
    }
}

void test_my_getdelim(void)
{
    {
        // 1 разделитель \n
        char *lineptr = NULL;        
        size_t n = 0;
        int delimiter = '\n';
        FILE *stream = fopen("source_1.txt", "r");
        char *expected[7] = { "Amy normally hated Monday mornings. but this year was different.\n",       
                            "Kamal was in her art class and she liked Kamal. She was waiting outside the classroom when her friend Tara arrived.\n",
                            " Hi Amy! Your mum sent me a text. You forgot your inhaler.\n",
                            "Amy don t you turn your phone on?  Amy didn t like technology.\n",
                            "She never sent text messages and she hated Facebook too.\n",
                            " Did Kamal ask you to the disco?  Tara was Amy s best friend,\n",
                            "and she wanted to know everything that was happening in Amy s life." };
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 1 in my_getdelim FAILED\n");
                    printf("lineptr = #%s#\n", lineptr);
                    printf("expected = #%s#\n", expected[k]);                    
                    check_right = 0;
                    break;
                }
                k++;
            } 
        }
        if (check_right)
            printf("Test 1 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    }
    {
        // 2 разделитель \n
        char *lineptr = NULL;
        size_t n = 0;
        int delimiter = '\n';
        FILE *stream = fopen("source_2.txt", "r");
        char *expected[17] = { "Amy \n",
                            "normally hated Monday \n",
                            "mornings. but this year was different. \n",
                            "Kamal was in her art class \n",
                            "and she liked Kamal. She was waiting \n",
                            "outside the classroom when her friend \n",
                            "Tara arrived.\n",
                            " Hi Amy! Your mum sent me a text. \n",
                            "You forgot your inhaler. \n",
                            "Amy don t you turn your phone on? \n",
                            " Amy didn t like technology. \n",
                            "She never sent text messages and \n",
                            "she hated Facebook too.\n",
                            " Did Kamal ask you to the disco?  \n",
                            "Tara was Amy s best friend, \n",
                            "and she wanted to know everything \n",
                            "that was happening in Amy s life."};
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 2 in my_getdelim FAILED\n");
                    printf("#%s# \n", lineptr);
                    printf("#%s# \n", expected[k]);                    
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 2 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    }
    
    {
        // 3 разделитель \n одна строчка
        char *lineptr = NULL;
        size_t n;
        int delimiter = '\n';
        FILE *stream = fopen("source_3.txt", "r");
        char *expected[1] = { "Amy normally hated Monday " };
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 3 in my_getdelim FAILED\n");
                    printf("%s#\n", lineptr);
                    printf("%s#\n", expected[k]);
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 3 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    } 
    {
        // 4 разделитель .
        char *lineptr = NULL;
        size_t n;
        int delimiter = '.';
        FILE *stream = fopen("source_4.txt", "r");
        char *expected[21] = { "Amy normally hated Monday mornings.", 
                            " but this year was different.",
                            "\nKamal was in her art class and she liked Kamal.",
                            " She was waiting outside the classroom when her friend Tara arrived.",
                            "\n Hi Amy! Your mum sent me a text.",
                            " You forgot your inhaler.",
                            "\nAmy don t you turn your phone on?  Amy didn t like technology.",
                            "\nShe never sent text messages and she hated Facebook too.",
                            "\n Did Kamal ask you to the disco?  Tara was Amy s best friend,\nand she wanted to know everything that was happening in Amy s life.",
                            "\n I don t think he likes me,  said Amy.",
                            "  And I never see him alone.",
                            "\nHe s always with Grant.",
                            "  Amy and Tara didn t like Grant.",
                            "\n Do you know about their art project?  asked Amy.",
                            "  It s about graffiti,\nI think,  said Tara.",
                            "  They re working on it at the old house behind the\nfactory.",
                            "   But that building is dangerous,  said Amy.",
                            "  Aah, are you worried\nhe s going to get hurt? Tara teased.",
                            "  Shut up, Tara! Hey look, here they come!\nKamal and Grant arrived.",
                            "  Hi Kamal!  said Tara.",
                            ""};
        int k = 0;
        int check_right = 1;
        int count_numbers = 0;
        while (count_numbers > 0)
        {
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || ((k < 20) && count_numbers != strlen(expected[k]))|| ((k == 20) && count_numbers != -1))
                {
                    printf("Test 4 in my_getdelim FAILED\n");
                    printf("lineptr = #%s# %d\n", lineptr, count_numbers);                    
                    check_right = 0;
                    break;
                }
                k++;
            }
            //printf("lineptr = #%s#  %d\n", lineptr,count_numbers);
        }  
        if (check_right)
            printf("Test 4 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    }
    {
        // 5 разделитель !
        char *lineptr = NULL;
        size_t n;
        int delimiter = '!';
        FILE *stream = fopen("source_5.txt", "r");
        char *expected[6] = {"Hello!",
                            "my names!",
                            " is !",
                            " Ivan\nand I!",
                            " like books!",
                            ""};
        int k = 0;
        int check_right = 1;
        int count_numbers = 0;
        //int l = 0;
        while (count_numbers > 0)
        {            
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            //printf("lineptr = #%s#\n", lineptr);
            //printf("%d\n",count_numbers);
             if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || ((k < 5) && count_numbers != strlen(expected[k])) || ((k == 5) && count_numbers != -1) )
                {
                    printf("Test 5 in my_getdelim FAILED\n");
                    printf("lineptr = #%s#  %d \n", lineptr,count_numbers);
                    printf("expected = #%s#\n", expected[k]);
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 5 in my_getdelim PASSED\n");
        if (lineptr != NULL)
            free(lineptr);
        fclose(stream);
    }
    {
        // 6 разделитель . его нет в тексте
        char *lineptr = NULL;
        size_t n;
        int delimiter = '.';
        FILE *stream = fopen("source_5.txt", "r");
        char *expected[5] = {"Hello!my names! is ! Ivan\nand I! like books!" };
        int k = 0;
        int check_right = 1;
        int count_numbers = 0;
        while (count_numbers > 0)
        {
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 6 in my_getdelim FAILED\n");
                    printf("lineptr = #%s#  %d \n", lineptr,count_numbers);
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 6 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    }
	{
        // 7 Файл не задан
        char *lineptr = NULL;
        size_t n;
        int delimiter = '!';
        FILE *stream = NULL;
  
        int count_numbers = 0;
        //int l = 0;       
		count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
        if (count_numbers == ERROR)
            printf("Test 7 in my_getdelim PASSED\n");
    }
	{
        // 8 задан начальный размер строки 
		size_t n = 10;
        char *lineptr = malloc(n);
       
        int delimiter = '.';
        FILE *stream = fopen("source_5.txt", "r");
        char *expected[5] = {"Hello!my names! is ! Ivan\nand I! like books!" };
        int k = 0;
        int check_right = 1;
        int count_numbers = 0;
        while (count_numbers > 0)
        {
            count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 8 in my_getdelim FAILED\n");
                    printf("lineptr = #%s#  %d \n", lineptr,count_numbers);
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 8 in my_getdelim PASSED\n");
        free(lineptr);
        fclose(stream);
    }
	{
        // 9 Файл пуст
        char *lineptr = NULL;
        size_t n;
        int delimiter = '!';
        FILE *stream =  fopen("source_6.txt", "r");;
  
        int count_numbers = 0;
        //int l = 0;       
		count_numbers = my_getdelim(&lineptr, &n, delimiter, stream);
        if (count_numbers == ERROR)
            printf("Test 9 in my_getdelim PASSED\n");
		fclose(stream);
		free(lineptr);
    }	
}

void test_my_getline(void)
{
    {
        // 1 разделитель \n
        char *lineptr = NULL;        
        size_t n = 0;
        FILE *stream = fopen("source_1.txt", "r");
        char *expected[7] = { "Amy normally hated Monday mornings. but this year was different.\n",       
                            "Kamal was in her art class and she liked Kamal. She was waiting outside the classroom when her friend Tara arrived.\n",
                            " Hi Amy! Your mum sent me a text. You forgot your inhaler.\n",
                            "Amy don t you turn your phone on?  Amy didn t like technology.\n",
                            "She never sent text messages and she hated Facebook too.\n",
                            " Did Kamal ask you to the disco?  Tara was Amy s best friend,\n",
                            "and she wanted to know everything that was happening in Amy s life." };
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            count_numbers = my_getline(&lineptr, &n, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 1 in my_getline FAILED\n");
                    printf("lineptr = #%s#\n", lineptr);
                    printf("expected = #%s#\n", expected[k]);               
                    check_right = 0;
                    break;
                }
                k++;
            } 
        }
        if (check_right)
            printf("Test 1 in my_getline PASSED\n");
        free(lineptr);
        fclose(stream);
    }
    {
        // 2 разделитель \n
        char *lineptr = NULL;
        size_t n = 0;
        FILE *stream = fopen("source_2.txt", "r");
        char *expected[17] = { "Amy \n",
                            "normally hated Monday \n",
                            "mornings. but this year was different. \n",
                            "Kamal was in her art class \n",
                            "and she liked Kamal. She was waiting \n",
                            "outside the classroom when her friend \n",
                            "Tara arrived.\n",
                            " Hi Amy! Your mum sent me a text. \n",
                            "You forgot your inhaler. \n",
                            "Amy don t you turn your phone on? \n",
                            " Amy didn t like technology. \n",
                            "She never sent text messages and \n",
                            "she hated Facebook too.\n",
                            " Did Kamal ask you to the disco?  \n",
                            "Tara was Amy s best friend, \n",
                            "and she wanted to know everything \n",
                            "that was happening in Amy s life."};
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            count_numbers = my_getline(&lineptr, &n, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 2 in my_getline FAILED\n");
                    printf("#%s# \n", lineptr);
                    printf("#%s# \n", expected[k]);                    
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 2 in my_getline PASSED\n");
        free(lineptr);
        fclose(stream);
    }
    
    {
        // 3 разделитель \n одна строчка
        char *lineptr = NULL;
        size_t n;
        FILE *stream = fopen("source_3.txt", "r");
        char *expected[1] = { "Amy normally hated Monday " };
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            count_numbers = my_getline(&lineptr, &n, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 3 in my_getline FAILED\n");
                    printf("%s#\n", lineptr);
                    printf("%s#\n", expected[k]);
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 3 in my_getline PASSED\n");
        free(lineptr);
        fclose(stream); 
    } 
	{
        // 4 Файл пуст
        char *lineptr = NULL;
        size_t n;
        FILE *stream =  fopen("source_6.txt", "r");;
  
        int count_numbers = 0;
        //int l = 0;       
		count_numbers = my_getline(&lineptr, &n, stream);
        if (count_numbers == ERROR)
            printf("Test 4 in my_getline PASSED\n");
		fclose(stream);
		free(lineptr);
    }
	{
        // 5 Файл не задан
        char *lineptr = NULL;
        size_t n;
        FILE *stream = NULL;
  
        int count_numbers = 0;
        //int l = 0;       
		count_numbers = my_getline(&lineptr, &n, stream);
        if (count_numbers == ERROR)
            printf("Test 5 in my_getline PASSED\n");
    }
	{
        // 6 Изначально задан размер строки
        size_t n = 100;
        char *lineptr = malloc(n);
        FILE *stream = fopen("source_2.txt", "r");
        char *expected[17] = { "Amy \n",
                            "normally hated Monday \n",
                            "mornings. but this year was different. \n",
                            "Kamal was in her art class \n",
                            "and she liked Kamal. She was waiting \n",
                            "outside the classroom when her friend \n",
                            "Tara arrived.\n",
                            " Hi Amy! Your mum sent me a text. \n",
                            "You forgot your inhaler. \n",
                            "Amy don t you turn your phone on? \n",
                            " Amy didn t like technology. \n",
                            "She never sent text messages and \n",
                            "she hated Facebook too.\n",
                            " Did Kamal ask you to the disco?  \n",
                            "Tara was Amy s best friend, \n",
                            "and she wanted to know everything \n",
                            "that was happening in Amy s life."};
        int k = 0;
        int check_right = 1;
        int count_numbers;
        while (!feof(stream))
        {
            count_numbers = my_getline(&lineptr, &n, stream);
            //count_numbers = getdelim(&lineptr, &n, delimiter, stream);
            if (lineptr)
            {
                if (strcmp(expected[k], lineptr) != 0 || count_numbers != strlen(expected[k]))
                {
                    printf("Test 6 in my_getline FAILED\n");
                    printf("#%s# \n", lineptr);
                    printf("#%s# \n", expected[k]);                    
                    check_right = 0;
                    break;
                }
                k++;
            }
        }  
        if (check_right)
            printf("Test 6 in my_getline PASSED\n");
        free(lineptr);
        fclose(stream);
    }
}



void test_find_underline(void)
{
    {
        // 1 такой подстроки в строке нет 
        
        char source[20] = "aaaa";
        char search[20] = "b";
        int pos1 = 0;
        int pos2 = 0;
        int actual_pos1 = 0;
        int actual_pos2 = 0;
		int pos_begin = 0;
		
        if (!find_underline(source, search, &pos1, &pos2, pos_begin) && pos1 == actual_pos1 && pos2 == actual_pos2)
        {
            printf("Test 1 in find_underline PASSED\n");
        }
        else
        {
            printf("Test 1 in find_underline FAILED\n");
        }
    }
    {
        // 2 встречается вначале
        
        char source[30] = "hello my name is Ivan";
        char search[30] = "hello";
        int pos1 = 0;
        int pos2 = 0;
        int actual_pos1 = 0;
        int actual_pos2 = 5;
        int pos_begin = 0;
        if (find_underline(source, search, &pos1, &pos2, pos_begin) && pos1 == actual_pos1 && pos2 == actual_pos2)
        {
            printf("Test 2 in find_underline PASSED\n");
        }
        else
        {
            printf("Test 2 in find_underline FAILED\n");
        }
    }
    {
        // 3 встречается в конце
        
        char source[30] = "hello my name is Ivan";
        char search[30] = "Ivan";
        int pos1 = 0;
        int pos2 = 0;
        int actual_pos1 = 17;
        int actual_pos2 = 21;
        int pos_begin = 0;
		
        if (find_underline(source, search, &pos1, &pos2, pos_begin) && pos1 == actual_pos1 && pos2 == actual_pos2)
        {
            printf("Test 3 in find_underline PASSED\n");
        }
        else
        {
            printf("Test 3 in find_underline FAILED\n");
        }
    }
    {    
        // 4 несколько вхождений
        
        char source[30] = "hello my name my is Ivan";
        char search[30] = "my";
        int pos1 = 0;
        int pos2 = 0;
        int actual_pos1 = 6;
        int actual_pos2 = 8;
        int pos_begin = 0;
		
        if (find_underline(source, search, &pos1, &pos2, pos_begin) && pos1 == actual_pos1 && pos2 == actual_pos2)
        {
            printf("Test 4 in find_underline PASSED\n");
        }
        else
        {
            printf("Test 4 in find_underline FAILED\n");
        }
    }
}


int main(void)
{
    test_str_replace();    
    test_my_getdelim();
    test_my_getline();
    test_find_underline();
    return 0;
}