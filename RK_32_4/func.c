#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"


students_t *creat_node(char name[MAX_NAME], char group[MAX_GROUP])
{
	students_t *stud = malloc(sizeof(students_t));
	if (!stud)
		return NULL;
	memmove(stud->name, name, MAX_NAME);
	memmove(stud->group, group, MAX_GROUP);
	stud->next = NULL;
	return stud;
}

int load_from_file(FILE *f, char name[MAX_NAME], char group[MAX_GROUP]) 
{
	if (fscanf(f,"%69s", name) != 1)
		return -1;
	if (fscanf(f,"%9s", group) != 1)
		return -1;
	return 0;
}

void insert_node(students_t **head, students_t *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		students_t *tmp = *head;
		while(tmp && strcmp(tmp->group,node->group ))
		{
			tmp = tmp->next;
		}
		if (tmp)
		{
			node->next = tmp->next;
			tmp->next = node;
		}
		else
		{
			node->next = *head;
			*head = node;
		}
	}
}

void free_memory(students_t *head)
{
	students_t *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void print_list(students_t *head)
{
	for (;head;head = head->next)
	{
		printf("%s\n%s\n",head->name, head->group);
	}
}