#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

# define OK 0
# define INCORRECT_FILE -1
# define INCORRECT_ARG -2
# define MEMORY_ERROR -3

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("./app.exe <input.txt>\n");
		return INCORRECT_ARG;
	}
	
	FILE *f = fopen(argv[1], "r");
	if (!f)
	{
		printf("Такого файла нет");
		return INCORRECT_FILE;
	}
	char name[MAX_NAME];
	char group[MAX_GROUP];
	students_t *head = NULL;
	students_t *tmp = NULL;
	while (load_from_file(f, name, group) == 0)
	{
		tmp = creat_node(name, group);
		if (!tmp)
		{
			fclose(f);
			return MEMORY_ERROR;
		}
		insert_node(&head, tmp);
	}
	print_list(head);
	free_memory(head);
	fclose(f);
	return OK;
}



