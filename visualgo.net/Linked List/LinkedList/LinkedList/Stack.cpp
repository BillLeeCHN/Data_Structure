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
bool IsEmpty(Stack* ps);
int Peek(Stack* ps);
void Pop(Stack* ps);
void Clear(Stack* ps);
void Traverse(Stack* ps);

int main()
{
	// Create
	Stack s;
	Create(&s);
	// Push element
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);
	Push(&s, 40);
	// Pop element
	Pop(&s);
	Pop(&s);
	// Peek
	int result = Peek(&s);
	printf("%d\n", result);
	// Traverse
	Traverse(&s);
	// Clear
	Clear(&s);
	if (!IsEmpty(&s))
	{
		result = Peek(&s);
		printf("%d\n", result);
	}
	else
	{
		printf("The stack is empty.\n");
	}
	
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
	pnew->data = 0;

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
	pnew->data = value;

	// Push
	pnew->next = ps->pTop;
	ps->pTop = pnew;
}

// Function: Is the stack empty?
bool IsEmpty(Stack* ps)
{
	if (ps->pTop == ps->pButton)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function: Peek the top element of stack
int Peek(Stack* ps)
{
	if (IsEmpty(ps))
	{
		printf("There is no element in this stack!\n");
		return 0;
	}
	else
	{
		return ps->pTop->data;
	}
}

// Function: Pop the top element of stack
void Pop(Stack* ps)
{
	if (IsEmpty(ps))
	{
		printf("The stack is empty.\n");
	}
	else
	{
		node* ptemp = ps->pTop;
		ps->pTop = ptemp->next;
		free(ptemp);
	}
}

// Function: Clear the stack
void Clear(Stack* ps)
{
	while (!IsEmpty(ps))
	{
		Pop(ps);
	}

	//printf("The stack has cleared.\n");
	return;
}

//
void Traverse(Stack* ps)
{
	node* ptemp = ps->pTop;
	while (ptemp != ps->pButton)
	{
		printf("%d\n", ptemp->data);
		ptemp = ptemp->next;
	}
}
		