#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void* pop_front(node_t **head)
{
	if (!head)
	{
		return NULL;
	}
	if (!*head)
	{
		return NULL;
	}
	
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
		if (tmp == before)
		{
			if (prev)
			{
				prev->next = elem;
				elem->next = before;
			}
			else
			{
				elem->next = before;
				*head = elem;
			}
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
	
node_t* reverse(node_t *head)
{
	if (!head)
	{
		return NULL;
	}
	
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

void front_back_split(node_t* head, node_t** back)
{
	if (!head)
		return;
	node_t *copy_head = head;
	int count = 0;
	while (copy_head)
	{
		count++;
		copy_head = copy_head->next;
	}
	
	if (count % 2 != 0)
		count = count / 2 + 1;
	else
		count = count / 2;
	//printf("%d \n", count);
	for (int i = 0; i < count-1; i++)
	{
		head = head->next;
	}
	(*back) = head->next;
	head->next = NULL;

}

node_t* sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
	node_t *res = NULL;
	node_t *copy_res = NULL;
	
	if (!*head_b || !(*head_b)->data)
	{
		copy_res = *head_a;
		*head_a = NULL;
		return copy_res;
	}
	if (!*head_a || !(*head_a)->data)
	{
		copy_res = *head_b;
		*head_b = NULL;
		return copy_res;
	}
	
	if (comparator((*head_a)->data, (*head_b)->data) <= 0)
	{
		copy_res = *head_a;
		res = copy_res;
		*head_a = (*head_a)->next;
	}	
	else
	{
		copy_res = *head_b;
		res = copy_res;
		*head_b = (*head_b)->next;
	}
	
	while (*head_a  && *head_b)
	{
		if (comparator((*head_a)->data, (*head_b)->data) <= 0)
		{
			copy_res->next = *head_a;
			copy_res = copy_res->next;
			*head_a = (*head_a)->next;
		}
		else
		{
			copy_res->next = *head_b;
			copy_res = copy_res->next;
			*head_b = (*head_b)->next;
		}
	}
	while (*head_a)
	{
		copy_res->next = *head_a;
		copy_res = copy_res->next;
		*head_a = (*head_a)->next;
	}
	while (*head_b)
	{
		copy_res->next = *head_b;
		copy_res = copy_res->next;
		*head_b = (*head_b)->next;
	}
	return res;	
}


node_t* sort(node_t *head_a, int (*comparator)(const void *, const void *))
{
	if (!head_a)
	{
		return NULL;
	}
	node_t* back = NULL;
	front_back_split(head_a, &back);
	if (head_a && head_a->next)
		head_a = sort(head_a, comparator);
	if (back && back->next)
		back = sort(back, comparator);
	head_a = sorted_merge(&head_a, &back, comparator);
	return head_a;
}
