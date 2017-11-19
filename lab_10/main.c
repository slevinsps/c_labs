#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void print_list(node_t *head)
{
	while(head)
	{
		printf("%d ",*(int*)(head->data));
		head = head->next;
	}
	printf("\n");
}


/* int main(void)
{
	return 0;
}  */

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



int main(void)
{
	node_t *head = malloc(sizeof(node_t));
	node_t *head1 = malloc(sizeof(node_t));
	//head->next = NULL;
	//head->data = NULL;
	node_t *copy_head = head;
	
	node_t *elem;
	int bef = 1222;
	node_t *before =  malloc(sizeof(node_t));
	before->next = NULL;
	before->data = &bef;
	
	int n = 2;
	int *arr = malloc(n*sizeof(int));
	int *arr2 = malloc(n*sizeof(int));
	int k = 0;
	for (int i = n; i > 0; i--)
	{
		arr[k] = i;
		k++;
	}
	
	for (int i = 0; i < n; i++)
	{
		arr2[i] = i+2;
	}
	node_t *res;
	load_list(head, arr, n);
	print_list(head);
	//print_list(head);
	head = sort(head);
	//res = sorted_merge(&head, &head1, comporator);
	
	print_list(head);
	//front_back_split(head, &head1);
	//print_list(head);
	//print_list(head1);
	//print_list(head);
	
	//insert(&head, elem, before);
	//print_list(head);
    //pop_front(&head);
	//print_list(head);
	//head1 = reverse(head);
	//printf("%d\n", *(int*)head1->data);
	

	return 0;
}