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
int Peek(Queue* pq);
int Size(Queue* pq);
void Traverse(Queue* pq);

int main()
{
	Queue q;
	// Create
	Create(&q);
	//enqueue
	Enqueue(&q, 10);
	Enqueue(&q, 20);
	Enqueue(&q, 30);
	Enqueue(&q, 40);
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
	// peek
	if (!IsEmpty(&q))
	{
		printf("haha");
		int result = Peek(&q);
		printf("The peeked element is %d\n", result);
	}
	else
	{
		printf("The queue is empty.\n");
	}
	
	int re = Size(&q);
	printf("size %d\n", re);
	

	Traverse(&q);
	
	
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
		result = ptemp->data;
		if (NULL == ptemp->next)
		{
			pq->rear = pq->front;
		}
		else
		{
			pq->front->next = ptemp->next;
		}

		
		
		free(ptemp);
	}
	else
	{
		//printf("The queue is empty.\n");
	}
	return result;	
}

// Peek the front element
int Peek(Queue* pq)
{
	if (!IsEmpty(pq))
	{
		return pq->front->next->data;
	}
	else
	{
		// printf("The queue is empty.\n");
	}
}

// Count the number of elements
int Size(Queue* pq)
{
	node* ptemp = pq->front;
	int count = 0;

	if (!IsEmpty(pq))
	{
		count++;
		while (ptemp->next != pq->rear)
		{
			ptemp = ptemp->next;
			count++;
		}
	}
	return count;
}

// Traverse all elements
void Traverse(Queue* pq)
{
	node* ptemp = pq->front;
	if (IsEmpty(pq))
	{
		printf("There is no element in this queue.\n");
	}
	else
	{
		printf("%d\n",ptemp->next->data);
		while (ptemp->next != pq->rear)
		{
			ptemp = ptemp->next;
			printf("%d\n",ptemp->next->data);
		}
	}

}