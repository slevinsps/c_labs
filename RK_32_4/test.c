#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

void insert_node_haos(students_t **head, students_t *node)
{
    node->next = *head;
    *head = node;
}

        
int compare(students_t *head1, students_t *head2)
{
    while (head1)
    {
        if (strcmp(head1->group,head2->group) != 0 || strcmp(head1->name,head2->name) != 0)
        {        
            return -1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
    
}

void test_list_sort_insert(void)
{
    // test 1
    { 
        FILE *f = fopen("test1.txt", "r");
        FILE *f_c = fopen("correct1.txt", "r");
        char name[MAX_NAME];
        char group[MAX_GROUP];
        students_t *head = NULL;
        students_t *head_c = NULL;
        while (load_from_file(f, name, group) == 0)
        {
            insert_node(&head, creat_node(name, group));
        }    
        while (load_from_file(f_c, name, group) == 0)
        {
            insert_node_haos(&head_c, creat_node(name, group));
        }
        
        if (compare(head, head_c) == 0)
            printf("Test1 passed\n");
        else
        {
            printf("Test1 failed\n");
        }
        free_memory(head);
        free_memory(head_c);
        fclose(f);
        fclose(f_c);
        
    }
    // test 2
    { 
        FILE *f = fopen("test2.txt", "r");
        FILE *f_c = fopen("correct2.txt", "r");
        char name[MAX_NAME];
        char group[MAX_GROUP];
        students_t *head = NULL;
        students_t *head_c = NULL;
        while (load_from_file(f, name, group) == 0)
        {
            insert_node(&head, creat_node(name, group));
        }    
        while (load_from_file(f_c, name, group) == 0)
        {
            insert_node_haos(&head_c, creat_node(name, group));
        }
        
        if (compare(head, head_c) == 0)
            printf("Test2 passed\n");
        else
        {
            printf("Test2 failed\n");
            print_list(head_c);
            printf("\n");
            print_list(head);
        }
        free_memory(head);
        free_memory(head_c);
        fclose(f);
        fclose(f_c);
    }
    // test 3
    { 
        FILE *f = fopen("test3.txt", "r");
        FILE *f_c = fopen("correct3.txt", "r");
        char name[MAX_NAME];
        char group[MAX_GROUP];
        students_t *head = NULL;
        students_t *head_c = NULL;
        while (load_from_file(f, name, group) == 0)
        {
            insert_node(&head, creat_node(name, group));
        }    
        while (load_from_file(f_c, name, group) == 0)
        {
            insert_node_haos(&head_c, creat_node(name, group));
        }
        
        if (compare(head, head_c) == 0)
            printf("Test3 passed\n");
        else
        {
            printf("Test3 failed\n");
            print_list(head_c);
            printf("\n");
            print_list(head);
        }
        free_memory(head);
        free_memory(head_c);
        fclose(f);
        fclose(f_c);
    }
    // test 4
    { 
        FILE *f = fopen("test4.txt", "r");
        FILE *f_c = fopen("correct4.txt", "r");
        char name[MAX_NAME];
        char group[MAX_GROUP];
        students_t *head = NULL;
        students_t *head_c = NULL;
        while (load_from_file(f, name, group) == 0)
        {
            insert_node(&head, creat_node(name, group));
        }    
        while (load_from_file(f_c, name, group) == 0)
        {
            insert_node_haos(&head_c, creat_node(name, group));
        }
        
        if (compare(head, head_c) == 0)
            printf("Test4 passed\n");
        else
        {
            printf("Test4 failed\n");
            print_list(head_c);
            printf("\n");
            print_list(head);
        }
        free_memory(head);
        free_memory(head_c);
        fclose(f);
        fclose(f_c);
    }
}

int main(void)
{
    test_list_sort_insert();

}