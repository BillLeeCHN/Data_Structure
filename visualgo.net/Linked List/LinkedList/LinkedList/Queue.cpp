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
int Dequeue(Queue* pq);

int main()
{
	Queue q;
	// Create
	Create(&q);
	//enqueue
	Enqueue(&q, 10);
	// dequeue
	if (!IsEmpty(&q))
	{
		int result = Dequeue(&q);
		printf("The deleted element is %d\n", result);
	}
	else
	{
		printf("The queue is empty.\n");
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

// delete an element from queue
// and return the deleted element
int Dequeue(Queue* pq)
{
	int result = 0;
	if (!IsEmpty(pq))
	{
		node* ptemp = pq->front->next;
		pq->front->next = ptemp->next;
		result = ptemp->data;
		free(ptemp);
	}
	else
	{
		//printf("The queue is empty.\n");
	}
	return result;	
}
