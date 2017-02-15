#include <stdio.h>
#include <stdlib.h>

typedef struct _LList
{
	int data;
	struct _LList* next;
}LList;

LList* Create();
void Add(LList* head, int value);
void Insert(LList* head, int index, int value);
int Search(LList* head, int value);
void RemoveRange(LList* head, int index, int count);
int Size(LList* head);
void Print(LList* head);
int Get(LList* head, int index);

int main()
{
	// Create
	LList* p = Create();
	// Add
	Add(p, 10);
	Add(p, 20);
	Add(p, 30);
	Add(p, 40);
	// Insert
	Insert(p, 1, 10);
	// RemoveRange
	RemoveRange(p, 2, 4);
	// Search
	int re = Search(p, 40);
	printf("the index of this element is %d\n", re);
	// Size
	int size = Size(p);
	printf("the size of this list is %d\n", size);
	// Print
	Print(p);
	// Get
	int get_result = Get(p, 2);
	printf("The element you want is %d\n", get_result);

	return 0;
}

// Create an empty list which just has a head point and a head node
LList* Create()
{
	LList* head; // head pointer
	head = (LList*)malloc(sizeof(LList));

	//create failed
	if (NULL == head)
	{
		printf("Create failed.\n");
		exit(-1);
    }

	head->next = NULL;
	return head;
}

// Add new element into tail node
void Add(LList* head, int value)
{
	LList* ptemp = head;

	// if ptemp does not point to the tail node,
	// move ptemp to the next node until to the tail node
	while(ptemp->next != NULL)
	{
		ptemp = ptemp->next;
	}

	// Create a new node
	LList* pnew;
	pnew = (LList*)malloc(sizeof(LList));
	//Create failed
	if (NULL == pnew)
	{
		printf("Create failed.\n");
		exit(-1);
    }
	pnew->next = NULL;
	pnew->data = value; // assign a value

	// Add the new node
	ptemp->next = pnew;
}

// 功能：向链表的索引为 index 的位置插入一个值 value
void Insert(LList* head, int index, int value)
{
	LList* pnew;
	pnew = (LList*)malloc(sizeof(LList));
	//创建失败返回
	if (pnew==NULL)
	{
        printf("创建结点失败！\n");;
        return;
    }
	pnew->next = NULL;
	pnew->data = value;

	LList* ptemp = head;
	while (index != 0)
	{
		ptemp = ptemp->next;
		if (ptemp == NULL)
		{
			printf("Please enter a valid index!\n");
			return;
		}
		index--;
	}
	pnew->next = ptemp->next;
	ptemp->next = pnew;
}

// 功能：在链表中搜索某个值，返回所在的索引位置
int Search(LList* head, int value)
{
	LList* ptemp;

	// 判断链表有没有元素
	if (head->next == NULL)
	{
		printf("There is no element in this link list!");
		return -1;
	}

	ptemp = head->next;
	int index = 0;
	while (ptemp != NULL)
	{
		if (ptemp->data == value)
		{
			return index;
		}
		else
		{
			ptemp = ptemp->next;
			index++;
		}
	}
	printf("The value is not found");
	return -1;
}

// 功能：删除链表 index 位置的值
void RemoveRange(LList* head, int index, int count)
{
	LList* ptemp, *pprev;

	// 判断链表有没有元素
	if (head->next == NULL)
	{
		printf("There is no element in this link list!");
		return ;
	}

	ptemp = head->next;
	pprev = head;
	int index_ele = 0;
	while(index_ele != index)
	{
		if (ptemp->next == NULL)
		{
			printf("invalid removed index");
			return ;
		}
		index_ele++;
		pprev = ptemp;
		ptemp = ptemp->next;
	}
	// remove the node
	for (int i = 0; i < count; i++)
	{
		if (NULL == ptemp->next)  // if the node is the last node
		{
			pprev->next = NULL;
			free(ptemp);
			break;
		}
		else // if the node is not the last node
		{
			pprev->next = ptemp->next;
			ptemp->next = NULL;
			free(ptemp);
			ptemp = pprev->next;
		}
	}
}

// Function: Count the element
int Size(LList* head)
{
	LList* ptemp = head;
	int count = 0; // the number of element

	while (ptemp->next != NULL)
	{
		count++;
		ptemp = ptemp->next;
	}
	return count;
}

// Function: Print all the elements of this list
void Print(LList* head)
{
	LList* ptemp = head;
	while (ptemp->next != NULL)
	{
		ptemp = ptemp->next;
		printf("%d\n", ptemp->data);
	}
}

int Get(LList* head, int index)
{
	if (NULL == head->next)
	{
		printf("There is no element in this list.\n");
		exit(-1);
	}

	// this list is not empty.
	// Move to the target position(index)
	LList* ptemp = head->next;
	int index_ele = 0;
	int result;
	while (index_ele != index)
	{
		if (NULL == ptemp->next)
		{
			printf("Get funtion: the index is out of range.\n");
			exit(-1);
		}
		ptemp = ptemp->next;
		index_ele++;
	}
	result = ptemp->data;
	return result;
}
