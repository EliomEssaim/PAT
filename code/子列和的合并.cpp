#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L = (List)malloc(sizeof(struct Node));
	L = L1;
	while (L)
	{
		printf("%d",L->Data);
		L = L->Next;
	}
	//	L2 = Read();
	//    L = Merge(L1, L2);
	//    Print(L);
	//    Print(L1);
	//    Print(L2);
	return 0;
}
List Read() {
	List p = (List)malloc(sizeof(struct Node));
	List last = (List)malloc(sizeof(struct Node));
	p->Next = NULL;
	last = p;
	int n;
	scanf("%d", &n);
	while (n)
	{
		List p_new = (List)malloc(sizeof(struct Node));
		scanf("%d", &(p_new->Data));
		p_new->Next = NULL;
		last->Next = p_new;
		last = p_new;
		n--;
		free(p_new);
	}
	free(last);

	return p;
}
//С֪ʶ���ṹ�Ĵ�С�����Ա��С����С����������Ҫ���ںͣ������ǽṹ���ַ��Ҫ���� 
