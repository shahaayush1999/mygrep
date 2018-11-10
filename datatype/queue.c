#include<stdlib.h>
#include"queue.h"
#include <string.h>

void qinit(queue *q) {
	q->head = q->tail = NULL;
	q->c = 0;
}

void enqueue(queue *q, char *name) {
	qnode *temp;
	temp = (qnode *)malloc(sizeof(qnode));
	temp->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(temp->name, name);
	temp->next = q->head;
	temp->prev = NULL;
	q->c++;
	if(q->tail == NULL) 
		q->tail = temp;
	else
		q->head->prev = temp;
	q->head = temp;
}

char *dequeue(queue *q) {
	char name[64];
	qnode *temp2;
	q->c--;
	strcpy(name, q->tail->name);
	temp2 = q->tail;
	if(q->tail == q->head) {
		q->tail = NULL;
		q->head = NULL;
	} else {
		q->tail = q->tail->prev;
		q->tail->next = NULL;
	}
	free(temp2->name);
	free(temp2);
	return name;
}

int qisfull(queue *q) {
	return 0;
}

int qisempty(queue *q) {
	return q->c == 0;
}
