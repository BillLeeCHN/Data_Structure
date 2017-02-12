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
void Remove(LList* head, int index);
int Size(LList* head);
void Print(LList* head);

int main()
{
	LList* p = Create();
	Add(p, 10);
	Add(p, 20);
	Add(p, 30);
	Add(p, 40);

	Insert(p, 1, 10);

	Remove(p, 2);

	int re = Search(p, 40);
	printf("the index of this element is %d\n", re);

	int size = Size(p);
	printf("the size of this list is %d\n", size);

	Print(p);
	
	return 0;
}

// ����һ���յ�����������ͷ����ͷָ��
LList* Create()
{
	LList* head; // head pointer
	head = (LList*)malloc(sizeof(LList));

	//create failed
	if (head==NULL) 
	{ 
        printf("��������ʧ�ܣ�");
        return NULL;
    }

	head->next = NULL;
	return head;
}

// ������β������Ԫ��
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
	//����ʧ�ܷ���
	if (pnew==NULL) 
	{ 
        printf("��������ʧ�ܣ�");
        return;
    }
	pnew->next = NULL;
	pnew->data = value; // assign a value

	// Add the new node
	ptemp->next = pnew;
}

// ���ܣ�������������Ϊ index ��λ�ò���һ��ֵ value
void Insert(LList* head, int index, int value)
{
	LList* pnew;
	pnew = (LList*)malloc(sizeof(LList));
	//����ʧ�ܷ���
	if (pnew==NULL) 
	{ 
        printf("�������ʧ�ܣ�");
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

// ���ܣ�������������ĳ��ֵ���������ڵ�����λ��
int Search(LList* head, int value)
{
	LList* ptemp;

	// �ж�������û��Ԫ��
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

// ���ܣ�ɾ������ index λ�õ�ֵ
void Remove(LList* head, int index)
{
	LList* ptemp, *pprev;

	// �ж�������û��Ԫ��
	if (head->next == NULL)
	{
		printf("There is no element in this link list!");
		return ;
	}

	ptemp = head->next;
	int index_ele = 0;
	while(index_ele != index)
	{
		index_ele++;
		pprev = ptemp;
		ptemp = ptemp->next;
		if (ptemp->next == NULL)
		{
			printf("invalid removed index");
			return ;
		}
	}
	pprev->next = ptemp->next;
	ptemp->next = NULL;
	free(ptemp);
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