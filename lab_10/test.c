#include <stdio.h>
#include <stdlib.h>
#include "func.h"


void load_list(node_t *head, int *arr, int n)
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
		
		load_list(head, arr, n);
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
		load_list(head, arr, n);
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



/* void test_insert(void)
{
	{
		// 1 в списке несколько элементов
		int n = 5;
		node_t *head = malloc(sizeof(node_t));
		int arr[5] = {8, 1, 4, 5, 4};
		int arr_exp[6] = {8, 1, 100, 4, 5, 4};
		node_t *expect;
		int expect2 = arr[1];
		
		load_list(head, arr, n);
		actual = pop_front(&head);
		
		if (*actual == expect1 && *(int*)(head->data) == expect2)
			printf("test 1 in pop_front PASSED\n");
		else
			printf("test 1 in pop_front FAILED\n");
		
		insert(node_t **head, node_t *elem, node_t *before)

	}
	
} */

int main(void)
{
	test_pop_front();
	//test_insert();
	return 0;	
}