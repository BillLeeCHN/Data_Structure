#include <stdio.h>
#include <stdlib.h>

typedef struct _LList
{
	int data;
	struct _LList* next;
}LList;

LList* Create();

int main()
{
	LList* p = Create();
	
	return 0;
}

// 创建一个空的链表，仅有头结点和头指针
LList* Create()
{
	LList* head; // 头指针
	head = (LList*)malloc(sizeof(LList));

	//创建失败返回
	if (head==NULL) 
	{ 
        printf("创建链表失败！");
        return NULL;
    }

	head->next = NULL;
	return head;
}