#ifndef FUNC
#define FUNC

#define MAX_NAME 70
#define MAX_GROUP 10

typedef struct students
{
	char name[MAX_NAME];
	char group[MAX_GROUP];
	struct students *next;

} students_t;

students_t *creat_node(char name[MAX_NAME], char group[MAX_GROUP]);
int load_from_file(FILE *f, char name[MAX_NAME], char group[MAX_GROUP]) ;
void insert_node(students_t **head, students_t *node);
void free_memory(students_t *head);
void print_list(students_t *head);

#endif //  FUNC