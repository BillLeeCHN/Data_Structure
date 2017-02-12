#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}node;

typedef struct _queue
{
	node* front;
	node* rear;
}Queue;

void Create(Queue* pq);
bool IsEmpty(Queue* pq);
void Enqueue(Queue* pq, int value);

int main()
{
	Queue q;
	// Create
	Create(&q);
	//enqueue
	Enqueue(&q, 10);
	// empty?
	if (IsEmpty(&q))
	{
		printf("The queue is empty.\n");
	}
	else
	{
		printf("The queue is not empty.\n");
	}

	
	
	
	
}

// Create a new queue
void Create(Queue* pq)
{
	// Create a new node
	node* pnew = (node*)malloc(sizeof(node));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->next = NULL;

	//
	pq->front = pnew;
	pq->rear = pnew;
}

// Is the queue empty?
bool IsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// put element into the queue
void Enqueue(Queue* pq, int value)
{
	// Create a new node
	node* pnew = (node*)malloc(sizeof(node));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->next = NULL;
	pnew->data = value;

	// enqueue
	pq->rear->next = pnew;
	pq->rear = pnew;
}
