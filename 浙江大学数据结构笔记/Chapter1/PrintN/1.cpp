#include <stdio.h>

void Print_for(int N);
void Print_recur(int N);

int main()
{
	// ��������
	//Print_for(10000);
	// ��Nȥȡ 10,000 ʱ������
	Print_recur(1000);
}

// forѭ������
// �Ƽ�
void Print_for(int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }   
}

// �ݹ鷽��
// ȱ�㣺ռ�ô����ڴ棬��N̫���ǻᱬ�����Һ�ʱ��
// ���Ƽ�
void Print_recur(int N)
{
    if (N)
    {
        Print_recur(N - 1);
        printf("%d\n", N);
    }
}