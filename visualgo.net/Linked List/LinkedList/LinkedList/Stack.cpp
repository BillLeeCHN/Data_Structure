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

int main()
{
	Stack s;
	Create(&s);

	return 0;
}

// Function: Create an empty stack
void Create(Stack* ps)
{
	node* pnew = (node*)malloc(sizeof(node));
	if (pnew == NULL)
	{
		printf("create failed!\n");
		return;
	}
	
	ps->pTop = pnew;
	ps->pButton = pnew;
	ps->pTop->next = NULL;
}