//Queue data structure from GeeksforGeeks

// A C program to demonstrate linked list based implementation of queue 
#include <stdlib.h> 
#include <stdio.h> 

// A linked list (LL) node to store a queue entry 
typedef struct QNode 
{ 
	int key; 
	struct QNode *next; 
}QNode; 
  
// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
typedef struct Queue 
{ 
	struct QNode *front, *rear; 
} Queue; 


Queue *initQueue(Queue *q) 
void enQueue(struct Queue *q, int k)
struct QNode *deQueue(struct Queue *q);

  
// A utility function to create a new linked list node. 
QNode* newNode(int k) 
{ 
	QNode *temp = (QNode*)malloc(sizeof(QNode)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp;  
} 
  
// A utility function to create an empty queue
Queue *initQueue(Queue *q) 
{ 
	q->front = q->rear = NULL; 
	return q; 
} 
  
// The function to add a key k to q 
void enQueue(Queue *q, int k) 
{ 
	// Create a new LL node 
	QNode *temp = newNode(k); 
  
	// If queue is empty, then new node is front and rear both 
	if (q->rear == NULL) 
	{ 
		q->front = q->rear = temp; 
		return; 
	} 
  
	// Add the new node at the end of queue and change rear 
	q->rear->next = temp; 
	q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
QNode *deQueue(Queue *q) 
{ 
	// If queue is empty, return NULL. 
	if (q->front == NULL) 
		return NULL; 
  
	// Store previous front and move front one node ahead 
	QNode *temp = q->front; 
	q->front = q->front->next; 
  
	// If front becomes NULL, then change rear also as NULL 
	if (q->front == NULL) 
		q->rear = NULL; 
	return temp; 
}
