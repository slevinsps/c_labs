#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void* pop_front(node_t **head)
{
	return (*head)->data;
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
    if(head->next)
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