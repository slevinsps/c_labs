#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define N 50

void load_list_int(node_t *head, int *arr, int n)
{
	head->data = (int*)&arr[0];
	head->next = NULL;
	node_t *tmp;
	
	for (int i = 1; i < n; i++)
	{
		tmp = malloc(sizeof(node_t));
		tmp->next = NULL;
		tmp->data = (int*)&arr[i];
		
		head->next = tmp;
		head = head->next;
	}	
}

void load_list_double(node_t *head, double *arr, int n)
{
	head->data = (double*)&arr[0];
	head->next = NULL;
	node_t *tmp;
	
	for (int i = 1; i < n; i++)
	{
		tmp = malloc(sizeof(node_t));
		tmp->next = NULL;
		tmp->data = (double*)&arr[i];
		
		head->next = tmp;
		head = head->next;
	}	
}

void load_list_char(node_t *head, char *arr, int n)
{
	head->data = (char*)&arr[0];
	head->next = NULL;
	node_t *tmp;
	
	for (int i = 1; i < n; i++)
	{
		tmp = malloc(sizeof(node_t));
		tmp->next = NULL;
		tmp->data = (char*)&arr[i];
		
		head->next = tmp;
		head = head->next;
	}	
}

void test_pop_front(void)
{
	{
		// 1 в списке несколько элементов
		int *actual;
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		int arr[5] = {8, 1, 4, 5, 4};
		int expect1 = arr[0];
		int expect2 = arr[1];
		
		load_list_int(head, arr, n);
		actual = pop_front(&head);
		
		if (*actual == expect1 && *(int*)(head->data) == expect2)
			printf("test 1 in pop_front PASSED\n");
		else
			printf("test 1 in pop_front FAILED\n");
	}
	{
		// 2 в списке один элемент
		int *actual;
		int n = 1;
		node_t *head = malloc(sizeof(node_t));
		int arr[5] = {8};
		int expect1 = arr[0];		
		load_list_int(head, arr, n);
		actual = pop_front(&head);
		
		if (*actual == expect1 && head == NULL)
			printf("test 2 in pop_front PASSED\n");
		else
			printf("test 2 in pop_front FAILED\n");
	}
	{
		// 3 head == NULL
		int *actual;
		node_t *head = NULL;
		int *expect1 = NULL;			
		actual = pop_front(&head);
		
		if (actual == expect1)
			printf("test 3 in pop_front PASSED\n");
		else
			printf("test 3 in pop_front FAILED\n");
	}
}

int compare_list_arr_int(node_t *head,int arr[N])
{
	int k = 0;
	while (head)
	{
		if (*(int*)(head->data) != arr[k])
		{
			return 0;
		}
		head = head->next;
		k++;
	}
	return 1;
}


int compare_list_arr_double(node_t *head,double arr[N])
{
	int k = 0;
	while (head)
	{
		if (*(double*)(head->data) != arr[k])
		{
			return 0;
		}
		head = head->next;
		k++;
	}
	return 1;
	
}


int compare_list_arr_char(node_t *head,char arr[N])
{
	int k = 0;
	while (head)
	{
		if (*(char*)(head->data) != arr[k])
		{
			return 0;
		}
		head = head->next;
		k++;
	}
	return 1;
	
}

void test_insert(void)
{
	{
		// 1 в списке несколько элементов
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *elem;
		int data = 100;
		node_t *before = malloc(sizeof(node_t));
		before->data = &data;
		before->next = NULL;
		
		
		int arr[N] = {8, 1, 4, 5, 4};
		int arr_exp[N+1] = {8, 1, 100, 4, 5, 4};
		
		load_list_int(head, arr, n);
		elem = head;
		for (int i = 0; i < 2; i++)
		{
			elem = elem->next;
		}
		insert(&head, elem, before);

		if (compare_list_arr_int(head,arr_exp))
			printf("test 1 in insert PASSED\n");
		else
			printf("test 1 in insert FAILED\n");
	}
	{
		// 2 вставка в начало
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *elem;
		int data = 100;
		node_t *before = malloc(sizeof(node_t));
		before->data = &data;
		before->next = NULL;
		
		
		int arr[N] = {8, 1, 4, 5, 4};
		int arr_exp[N+1] = {100, 8, 1, 4, 5, 4};
		
		load_list_int(head, arr, n);
		elem = head;
		insert(&head, elem, before);
		
		if (compare_list_arr_int(head,arr_exp))
			printf("test 2 in insert PASSED\n");
		else
			printf("test 2 in insert FAILED\n");
	}
	{
		// 3 вставка перед последним
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *elem;
		int data = 100;
		node_t *before = malloc(sizeof(node_t));
		before->data = &data;
		before->next = NULL;
		
		
		int arr[N] = {8, 1, 4, 5, 4};
		int arr_exp[N+1] = {8, 1, 4, 5, 100, 4};
		
		load_list_int(head, arr, n);
		elem = head;
		for (int i = 0; i < 4; i++)
		{
			elem = elem->next;
		}
		insert(&head, elem, before);
		
		if (compare_list_arr_int(head, arr_exp))
			printf("test 3 in insert PASSED\n");
		else
			printf("test 3 in insert FAILED\n");
	}
	
}

void test_reverse(void)
{
	{
		// 1 в списке несколько элементов
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *head_reverse;
		
		
		int arr[N] = {8, 1, 4, 5, 4};
		int arr_exp[N] = {4, 5, 4, 1, 8};
		
		load_list_int(head, arr, n);
		
		head_reverse = reverse(head);

		if (compare_list_arr_int(head_reverse, arr_exp))
			printf("test 1 in reverse PASSED\n");
		else
			printf("test 1 in reverse FAILED\n");
	}
	{
		// 2 в списке один элемент
		int n = 1;
		node_t *head = malloc(sizeof(node_t));
		node_t *head_reverse;
		
		
		int arr[N] = {8};
		int arr_exp[N] = {8};
		
		load_list_int(head, arr, n);
		
		head_reverse = reverse(head);

		if (compare_list_arr_int(head_reverse, arr_exp))
			printf("test 2 in reverse PASSED\n");
		else
			printf("test 2 in reverse FAILED\n");
	}
	{
		// 3 в списке одинаковые элементы
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *head_reverse;
		
		
		int arr[N] = {8, 8, 8, 8, 8};
		int arr_exp[N] = {8, 8, 8, 8, 8};
		
		load_list_int(head, arr, n);
		
		head_reverse = reverse(head);

		if (compare_list_arr_int(head_reverse, arr_exp))
			printf("test 3 in reverse PASSED\n");
		else
			printf("test 3 in reverse FAILED\n");
	}
	{
		// 4 в списке одинаковые элементы
		node_t *head = NULL;

		if (reverse(head) == NULL)
			printf("test 4 in reverse PASSED\n");
		else
			printf("test 4 in reverse FAILED\n");
	}
}

void print_list(node_t *head)
{
	while(head)
	{
		printf("%c ",*(char*)(head->data));
		head = head->next;
	}
	printf("\n");
}

void test_front_back_split(void)
{
	{
		// 1 в списке нечетное количество элементов
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		node_t *back;
		
		
		int arr[N] = {8, 1, 4, 5, 4};
		int arr_exp1[N] = {8, 1, 4};
		int arr_exp2[N] = {5, 4};
		
		load_list_int(head, arr, n);
		
		front_back_split(head, &back);

		if (compare_list_arr_int(head, arr_exp1) && compare_list_arr_int(back, arr_exp2))
			printf("test 1 in front_back_split PASSED\n");
		else
			printf("test 1 in front_back_split FAILED\n");
	}
	{
		// 2 в списке четное количество элементов
		int n = 6;
		node_t *head = malloc(sizeof(node_t));
		node_t *back;
		
		
		int arr[N] = {8, 1, 4, 5, 4, 10};
		int arr_exp1[N] = {8, 1, 4};
		int arr_exp2[N] = {5, 4, 10};
		
		load_list_int(head, arr, n);
		
		front_back_split(head, &back);

		if (compare_list_arr_int(head, arr_exp1) && compare_list_arr_int(back, arr_exp2))
			printf("test 2 in front_back_split PASSED\n");
		else
			printf("test 2 in front_back_split FAILED\n");
	}
	{
		// 3 в списке 1 элемент
		int n = 1;
		node_t *head = malloc(sizeof(node_t));
		node_t *back;
		
		
		int arr[N] = {8};
		int arr_exp1[N] = {8};
		
		load_list_int(head, arr, n);
		
		front_back_split(head, &back);
		if (compare_list_arr_int(head, arr_exp1) && back == NULL)
			printf("test 3 in front_back_split PASSED\n");
		else
			printf("test 3 in front_back_split FAILED\n");
	}
	{
		// 4 в списке 2 элемента
		int n = 2;
		node_t *head = malloc(sizeof(node_t));
		node_t *back;
		
		
		int arr[N] = {8, 1};
		int arr_exp1[N] = {8};
		int arr_exp2[N] = {1};
		
		load_list_int(head, arr, n);
		
		front_back_split(head, &back);

		if (compare_list_arr_int(head, arr_exp1) && compare_list_arr_int(back, arr_exp2))
			printf("test 4 in front_back_split PASSED\n");
		else
			printf("test 4 in front_back_split FAILED\n");
	}
}

int comporator_int(const void* d1, const void* d2)
{
	return(*(int *)d1 - *(int *)d2);
}

int comporator_double(const void* d1, const void* d2)
{
	double res = *(double *)d1 - *(double *)d2;
	if (res < 0)
		return -1;
	else if (res > 0)
		return 1;
	else
		return 0;
}

int comporator_char(const void* d1, const void* d2)
{
	if (*((char *)d1) < *((char *)d2))
		return -1;
	else if (*((char *)d1) > *((char *)d2))
		return 1;
	else
		return 0;
}

void test_sorted_merge(void)
{
	{
		// 1 в списках несколько элементов
		int n = 5;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *head_b = malloc(sizeof(node_t));
		node_t *res;
		
		
		int arr1[N] = {1, 3, 5, 7, 9};
		int arr2[N] = {2, 4, 6, 8, 10};
		int arr_exp[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		load_list_int(head_a, arr1, n);
		load_list_int(head_b, arr2, n);
		
		res = sorted_merge(&head_a, &head_b, comporator_int);

		if (compare_list_arr_int(res, arr_exp) && head_a == NULL && head_b == NULL)
			printf("test 1 in sorted_merge PASSED\n");
		else
			printf("test 1 in sorted_merge FAILED\n");
	}
	{
		// 2 в списках по одному элементу несколько элементов
		int n = 1;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *head_b = malloc(sizeof(node_t));
		node_t *res;
		
		
		int arr1[N] = {8};
		int arr2[N] = {2};
		int arr_exp[N] = {2, 8};
		
		load_list_int(head_a, arr1, n);
		load_list_int(head_b, arr2, n);
		
		res = sorted_merge(&head_a, &head_b, comporator_int);

		if (compare_list_arr_int(res, arr_exp) && head_a == NULL && head_b == NULL)
			printf("test 2 in sorted_merge PASSED\n");
		else
			printf("test 2 in sorted_merge FAILED\n");
	}
	{
		// 3 в списках разное количество элементов
		int n1 = 4;
		int n2 = 7;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *head_b = malloc(sizeof(node_t));
		node_t *res;
		
		
		int arr1[N] = {8, 10, 25, 50};
		int arr2[N] = {1, 9, 20, 27, 29, 53, 82};
		int arr_exp[N] = {1, 8, 9, 10, 20, 25, 27, 29, 50, 53, 82};
		
		load_list_int(head_a, arr1, n1);
		load_list_int(head_b, arr2, n2);
		
		res = sorted_merge(&head_a, &head_b, comporator_int);

		if (compare_list_arr_int(res, arr_exp) && head_a == NULL && head_b == NULL)
			printf("test 3 in sorted_merge PASSED\n");
		else
			printf("test 3 in sorted_merge FAILED\n");
	}
	{
		// 4 элементы типа double
		int n1 = 4;
		int n2 = 8;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *head_b = malloc(sizeof(node_t));
		node_t *res;
		
		
		double arr1[N] = {8.256, 10, 25.268, 50.145};
		double arr2[N] = {1, 8.253, 9, 20.5, 27, 29, 53, 82.487};
		double arr_exp[N] = {1, 8.253, 8.256, 9, 10, 20.5, 25.268, 27, 29, 50.145, 53, 82.487};
		
		load_list_double(head_a, arr1, n1);
		load_list_double(head_b, arr2, n2);
			
		res = sorted_merge(&head_a, &head_b, comporator_double);
		if (compare_list_arr_double(res, arr_exp) && head_a == NULL && head_b == NULL)
			printf("test 4 in sorted_merge PASSED\n");
		else
			printf("test 4 in sorted_merge FAILED\n");
	}
	{
		// 4 элементы типа char
		int n1 = 3;
		int n2 = 3;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *head_b = malloc(sizeof(node_t));
		node_t *res;
		
		
		char arr1[N] = {'1', '5', '8'};
		char arr2[N] = {'3', '6', '7'};
		char arr_exp[N] = {'1', '3', '5', '6', '7', '8'};			
		load_list_char(head_a, arr1, n1);
		load_list_char(head_b, arr2, n2);
		res = sorted_merge(&head_a, &head_b, comporator_char);
		if (compare_list_arr_char(res, arr_exp) && head_a == NULL && head_b == NULL)
			printf("test 4 in sorted_merge PASSED\n");
		else
			printf("test 4 in sorted_merge FAILED\n");
	}
}

void test_sort(void)
{
	{
		// 1 в обратном порядке
		int n = 10;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *res;
		
		
		int arr1[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int arr_exp[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		load_list_int(head_a, arr1, n);
		
		res = sort(head_a, comporator_int);
		if (compare_list_arr_int(res, arr_exp))
			printf("test 1 in sort PASSED\n");
		else
			printf("test 1 in sort FAILED\n");
	}
	{
		// 2 один элемент
		int n = 1;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *res;
		
		
		int arr1[N] = {10};
		int arr_exp[N] = {10};
		
		load_list_int(head_a, arr1, n);
		
		res = sort(head_a, comporator_int);
		if (compare_list_arr_int(res, arr_exp))
			printf("test 2 in sort PASSED\n");
		else
			printf("test 2 in sort FAILED\n");
	}
	{
		// 3 тип double
		int n = 4;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *res;
		
		
		double arr1[N] = {5.452, 5.450, 5.46, 4.99};
		double arr_exp[N] = {4.99, 5.450, 5.452, 5.46};
		
		load_list_double(head_a, arr1, n);
		
		res = sort(head_a, comporator_double);
		if (compare_list_arr_double(res, arr_exp))
			printf("test 3 in sort PASSED\n");
		else
			printf("test 3 in sort FAILED\n");
	}
	{
		// 4 тип char
		int n = 4;
		node_t *head_a = malloc(sizeof(node_t));
		node_t *res;
		
		
		char arr1[N] = {'9', '4', '6', '0'};
		char arr_exp[N] = {'0', '4', '6', '9'};
		
		load_list_char(head_a, arr1, n);
		
		res = sort(head_a, comporator_char);
		if (compare_list_arr_char(res, arr_exp))
			printf("test 4 in sort PASSED\n");
		else
			printf("test 4 in sort FAILED\n");
	}
}


int main(void)
{
	test_pop_front();
	test_insert();
	test_reverse();
	test_front_back_split();
	test_sorted_merge();
	test_sort();
	return 0;	
}