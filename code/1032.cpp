
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int sn, score, MaxID, Max = 0,tmp;
	int n;
	int *schID;
	scanf("%d", &n);
	n = n + 1;
	schID = (int *)malloc(n *sizeof(schID));
	tmp = sizeof(schID);
	memset(schID, 0,n*(sizeof(int))/sizeof(char));

	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &sn, &score);
		schID[sn] += score;
	}
	for (int i = 1; i < n; i++)
	{
		if (schID[i] > Max)
		{
			MaxID = i;
			Max = schID[i];
		}
	}
	
	free(schID);
	printf("%d %d\n", MaxID, Max);

	return 0;
}
//�ܽ᣺memset���ֽڷ����ڴ棬�����������char����Ļ����Ѷ��丳ֵ
//�������������0��ֵֻҪ��ĩβ�ĳ�sizeof��int��/sizeof��char���Ϳ���
//������ֵ
