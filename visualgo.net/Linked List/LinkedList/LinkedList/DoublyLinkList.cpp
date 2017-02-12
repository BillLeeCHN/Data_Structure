#include <stdio.h>
#include <stdlib.h>

typedef struct _dbNode
{
	int data;
	struct _dbNode* prev;
	struct _dbNode* next;
}dbNode;

typedef struct _dbList
{
	dbNode* head;
	dbNode* tail;
}dbList;

void Create(dbList* pdl);
void Add(dbList* pdl, int value);

int main()
{
	dbList dl;
	Create(&dl);
	// Add
	Add(&dl, 10);


	return 0;
}

// Create a new doubly linked list
void Create(dbList* pdl)
{
	// Create a node
	dbNode* pnew = (dbNode*)malloc(sizeof(_dbNode));
	if (NULL == pnew)
	{
		printf("Create failed.\n");
		return;
	}
	pnew->prev = NULL;
	pnew->next = NULL;
	//
	pdl->head = pnew;
	pdl->tail = pnew;
}

// Add element to the tail of double linked list
void Add(dbList* pdl, int value)
{
	// Create a node
	dbNode* pnew = (dbNode*)malloc(sizeof(_dbNode));
	if (NULL == pnew)
	{
		printf("Create failed.\n");
		return;
	}
	pnew->prev = NULL;
	pnew->next = NULL;
	pnew->data = value;
	//Add node to the tail
	pdl->tail->next = pnew;
	pnew->prev = pdl->tail;
	pdl->tail = pnew;
}