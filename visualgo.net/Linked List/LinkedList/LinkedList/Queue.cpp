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

int main()
{
	Queue q;

	Create(&q);

}

//
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
