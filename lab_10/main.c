#include <stdio.h>
#include <stdlib.h>


typedef struct node node_t;
struct node
{
	void *data;
	node_t *next;
};


void* pop_front(node_t **head)
{
	if (!*head)
		return NULL;
	node_t *tmp = *head;
	void *data = tmp->data;
	*head = (*head)->next;
	free(tmp);
	return data;
}


void insert(node_t **head, node_t *elem, node_t *before)
{
	node_t *tmp = *head;
	node_t *prev = NULL;

	while (tmp)
	{
		if (tmp == elem)
		{
			if (prev)
			{
				prev->next = before;
				before->next = elem;
			}
			else
			{
				before->next = elem;
				*head = before;
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
	
	
	
node_t* reverse(node_t *head)
{
	node_t *h;
    if(head->next->next)
    {
        node_t* node = head->next;
		h = reverse(node); 
		node->next=head;
        head->next = NULL;
    }
	else
		h = head;
	return h;
}
	
	
void print_list(node_t *head)
{
	while(head)
	{
		printf("%d ",*(int*)(head->data));
		head = head->next;
	}
	printf("\n");
}



	
int main(void)
{
	node_t *head = malloc(sizeof(node_t));
	node_t *head1;
	head->next = NULL;
	head->data = NULL;
	node_t *copy_head = head;
	node_t *tmp;
	node_t *elem;
	int bef = 1222;
	node_t *before =  malloc(sizeof(node_t));
	before->next = NULL;
	before->data = &bef;
	int *arr = malloc(20*sizeof(int));
	
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
		copy_head->data = (int*)&arr[i];
		
		tmp = malloc(sizeof(node_t));
		tmp->next = NULL;
		tmp->data = NULL;
		
		copy_head->next = tmp;
		if (i == 5)
			elem = copy_head;
		copy_head = copy_head->next;
	}
	
	//print_list(head);
	
	insert(&head, elem, before);
	//print_list(head);
	printf("%d\n",*(int*)pop_front(&head));
	//print_list(head);
	head1 = reverse(head);
	printf("%d\n", *(int*)head1->data);
	print_list(head1);
	
	return 0;
}