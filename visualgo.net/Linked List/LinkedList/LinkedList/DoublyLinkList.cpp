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
bool IsEmpty(dbList* pdl);
void Insert(dbList* pdl, int index, int value);
int Size(dbList* pdl);
void Remove(dbList* pdl, int index);
void RemoveRange(dbList* pdl, int index, int cnt);

int main()
{
	dbList dl;
	Create(&dl);
	// Add
	Add(&dl, 10);
	// IsEmpty
	if (IsEmpty(&dl))
	{
		printf("empty\n");
	}
	else
	{
		printf("not empty\n");
	}
	// Insert
	Insert(&dl, 1, 20);
	// Remove
	Remove(&dl,1);
	// RemoveRange
	//RemoveRange(&dl,1,1);
	// Size
	int size_list = Size(&dl);
	printf("The size of list is %d\n", size_list);
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

// Is the doubly llist empty?
bool IsEmpty(dbList* pdl)
{
	if (pdl->head == pdl->tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Insert element
void Insert(dbList* pdl, int index, int value)
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

	// Insert a node
	dbNode* ptemp = pdl->head;
	dbNode* pprev = pdl->head;
	while (index != 0)
	{
		if (NULL == ptemp->next)
		{
			printf("Please enter a valid index!\n");
			return;
		}
		ptemp = ptemp->next;
		pprev = pprev->next;
		index--;
	}
	// if the postion is the tail of list,
	// just call Add funtion
	if (NULL == ptemp->next)
	{
		Add(pdl, value);
		return;
	}
	// otherwise
	ptemp = ptemp->next;
	pprev->next = pnew;
	pnew->prev = pprev;
	pnew->next = ptemp;
	ptemp->prev = pnew;
}

int Size(dbList* pdl)
{
	int count = 0;
	dbNode* ptemp = pdl->head;

	while (pdl->tail != ptemp)
	{
		ptemp = ptemp->next;
		count++;
	}
	return count;
}

void Remove(dbList* pdl, int index)
{
	RemoveRange(pdl, index, 1);
}

void RemoveRange(dbList* pdl, int index, int cnt)
{
	// if the doubly linked list is empty
	// it can not be removed any element
	int count = Size(pdl);

	if (0 == count)
	{
		printf("There is no element in this doubly linked list.\n");
		//return;
	}
	else if (count < (index + 1))
	{
		printf("The index is greater than size of this list.\n");
		//return;
	}
	else if (count < (index + cnt))
	{
		printf("The number of elements to be removed is greater.\n");
	}
	else
	{
		dbNode* ptemp = pdl->head->next;
		dbNode* pprev = pdl->head;
		int index_element = 0;
		while (index_element != index)
		{
			pprev = ptemp;
			ptemp = ptemp->next;
			index_element++;
		}

		for (int i = 0; i < cnt; i++)
		{
			// if the node is tail node
			if (NULL == ptemp->next)
			{
				free(ptemp);
				pprev->next = NULL;
				pdl->tail = pprev; // do not forget the tail pointer
				return;
			}
			else // oterwise
			{
				pprev->next = ptemp->next;
				ptemp->next->prev = pprev;
				free(ptemp);
				ptemp = pprev->next;
			}
		}
		
	}

}
