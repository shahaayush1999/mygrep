typedef struct node {
	char *name;
	struct node* next;
} node;
typedef node* stack;

void init(stack *s);
int isempty(stack *s);
int isfull(stack *s);
void push(stack *s, char *name);
char *pop(stack *s);
