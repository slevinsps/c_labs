#ifndef FUNC
#define FUNC
typedef struct node node_t;
struct node
{
	void *data;
	node_t *next;
};

void* pop_front(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);
node_t* reverse(node_t *head);

#endif // FUNC
