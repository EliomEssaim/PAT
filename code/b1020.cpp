#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct goods{
	float store;
	float price;
	float uprice;
}GD;
bool cmp(GD a,GD b)
{
	return a.uprice>b.uprice;
}
int main()
{
	int N;
	int i;
	float D,mount;
	float mprofit=0;
	GD *gdp;

	scanf("%d%f",&N,&D);

	gdp=(GD *)malloc(sizeof(GD)*N);

	for(i=0;i<N;i++)
		scanf("%f",&gdp[i].store);
	for(i=0;i<N;i++)
	{
		scanf("%f",&gdp[i].price);
		gdp[i].uprice=gdp[i].price/gdp[i].store;

	}
	sort(gdp,gdp+N,cmp);
//��õİ�uprice�Ӵ�С��GD����
	for(i=0;i<N;i++)
	{
		if(D-gdp[i].store>0)
		{
			mprofit+=gdp[i].price;
			D-=gdp[i].store;
		}
		else
		{
			mount=D;
			mprofit+=mount*gdp[i].uprice;
			break;
		}
	}

	printf("%.2f",mprofit);
	return 0;
 }
 //���̻�˼ά�� û��ã���þͺܼ�
 //���� û���뵽ʹ�ýṹ�壡���²����� �����޸ĳɽṹ�壻
 //��� �����һ��forѭ��ʱ���˺ܾ��������ʵ���㷨
 //review��������Ŀ�� 1����μ��㣿���㷨��
 //2������˰�uprice�Ӵ�С��GD����
 //���ʵ������������
