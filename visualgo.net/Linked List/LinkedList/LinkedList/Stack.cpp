#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}node;

typedef struct _Stack
{
	node* pTop;
	node* pButton;
}Stack;

void Create(Stack* ps);
void Push(Stack* ps, int value);

int main()
{
	Stack s;
	Create(&s);

	Push(&s, 12);

	return 0;
}

// Function: Create an empty stack
void Create(Stack* ps)
{
	// Create a new node
	node* pnew = (node*)malloc(sizeof(node));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->next = NULL;

	ps->pTop = pnew;
	ps->pButton = pnew;
}

// Function: Push a new element into stack
void Push(Stack* ps, int value)
{
	// Create a new node
	node* pnew = (node*)malloc(sizeof(node));
	if (NULL == pnew)
	{
		printf("create failed!\n");
		return;
	}
	pnew->next = NULL;

	// Push
	pnew->next = ps->pTop;
	ps->pTop = pnew;
}