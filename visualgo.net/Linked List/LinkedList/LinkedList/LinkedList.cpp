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

// ����һ���յ���������ͷ����ͷָ��
LList* Create()
{
	LList* head; // ͷָ��
	head = (LList*)malloc(sizeof(LList));

	//����ʧ�ܷ���
	if (head==NULL) 
	{ 
        printf("��������ʧ�ܣ�");
        return NULL;
    }

	head->next = NULL;
	return head;
}