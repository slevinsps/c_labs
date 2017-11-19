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
void front_back_split(node_t* head, node_t** back);
node_t* sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));


#endif // FUNC
