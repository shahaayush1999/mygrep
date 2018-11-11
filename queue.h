typedef struct qnode {
	char *name;
	struct qnode *next;
	struct qnode *prev;
}qnode;

typedef struct queue {
	qnode *head;
	qnode *tail;
	int c;
}queue;

void qinit(queue *q);
void enqueue(queue *q, char *name);
char *dequeue(queue *q);
int qisfull(queue *q);
int qisempty(queue *q);
