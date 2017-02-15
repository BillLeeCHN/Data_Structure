#include <stdio.h>
#include <stdlib.h>

typedef struct _dbnode
{
	int data;
	struct _dbnode* prev;
	struct _dbnode* next;
}dbNode;

typedef struct _dbqueue
{
	dbNode* front;
	dbNode* rear;
}dbQueue;

void Create(dbQueue* dbq);
bool IsEmpty(dbQueue* dbq);
int Size(dbQueue* dbq);
void Enqueue_front(dbQueue* dbq, int value);
void Enqueue_rear(dbQueue* dbq, int value);
void Dequeue_front(dbQueue* dbq);
void Dequeue_rear(dbQueue* dbq);
int Peek_front(dbQueue* dbq);
int Peek_rear(dbQueue* dbq);

int main()
{
	dbQueue dbq;

	//Create
	Create(&dbq);
	// IsEmpty
	if (IsEmpty(&dbq))
	{
		printf("The deque is empty.\n");
	}
	else
	{
		printf("The deque is not empty.\n");
	}
	
	// Enqueue_front
	Enqueue_front(&dbq, 10);
	Enqueue_front(&dbq, 40);
	// Enqueue_rear
	Enqueue_rear(&dbq, 20);
	Enqueue_rear(&dbq, 30);
	//Dequeue_front
	Dequeue_front(&dbq);
	//Dequeue_rear
	Dequeue_rear(&dbq);
	//Peek_front
	int re = Peek_front(&dbq);
	printf("The element you peek is %d\n", re);
	//Peek_rear
	re = Peek_rear(&dbq);
	printf("The element you peek is %d\n", re);
	//Size
	int cnt = Size(&dbq);
	printf("The size of deque is %d\n", cnt);

}

void Create(dbQueue* dbq)
{
	// Create a new node
	dbNode* pnew = (dbNode*)malloc(sizeof(dbNode));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->prev = NULL;
	pnew->next = NULL;
	//
	dbq->front = pnew;
	dbq->rear  = pnew;
}

bool IsEmpty(dbQueue* dbq)
{
	if (dbq->front == dbq->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Size(dbQueue* dbq)
{
	int count = 0;
	dbNode* ptemp = dbq->front;
	if (!IsEmpty(dbq))
	{
		count++;
		while (ptemp->next != dbq->rear)
		{
			ptemp = ptemp->next;
			count++;
		}
	}
	return count;

}

void Enqueue_front(dbQueue* dbq, int value)
{
	// Create a new node
	dbNode* pnew = (dbNode*)malloc(sizeof(dbNode));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->prev = NULL;
	pnew->next = NULL;
	pnew->data = value;
	// Enqueue
	if (!IsEmpty(dbq))// not empty
	{
		dbNode* ptemp = dbq->front->next;

		dbq->front->next = pnew;
		pnew->prev = dbq->front;

		pnew->next = ptemp;
		ptemp->prev = pnew;
	}
	else // empty
	{
		dbq->front->next = pnew;
		pnew->prev = dbq->front;
		dbq->rear = pnew;
	}
}

void Enqueue_rear(dbQueue* dbq, int value)
{
	// Create a new node
	dbNode* pnew = (dbNode*)malloc(sizeof(dbNode));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->prev = NULL;
	pnew->next = NULL;
	pnew->data = value;
	// Enqueue
	dbq->rear->next = pnew;
	pnew->prev = dbq->rear;
	dbq->rear = pnew;

}

void Dequeue_front(dbQueue* dbq)
{
	int count = Size(dbq);

	if (0 == count)
	{
		printf("The dequeue is empty, can not be removed any element.\n");
	}
	else if (1 == count)
	{
		dbq->front->next = NULL;
		free(dbq->rear);
		dbq->rear = dbq->front;
	}
	else
	{
		dbNode* ptarget = dbq->front->next;
		dbNode* ptemp = ptarget->next;
		dbq->front->next = ptemp;
		ptemp->prev = dbq->front;
		free(ptarget);
	}
}

void Dequeue_rear(dbQueue* dbq)
{
	if (IsEmpty(dbq))
	{
		printf("The dequeue is empty, can not be removed any element.\n");
	}
	else
	{
		dbNode* ptemp = dbq->rear->prev;
		ptemp->next = NULL;
		free(dbq->rear);
		dbq->rear = ptemp;
	}

}

int Peek_front(dbQueue* dbq)
{
	int result;
	if (IsEmpty(dbq))
	{
		printf("There is no element to peek.\n");
		exit(-1);
	}
	else
	{
		result = dbq->front->next->data;
	}
	return result;
}

int Peek_rear(dbQueue* dbq)
{
	int result;
	if (IsEmpty(dbq))
	{
		printf("There is no element to peek.\n");
		exit(-1);
	}
	else
	{
		result = dbq->rear->data;
	}
	return result;

}