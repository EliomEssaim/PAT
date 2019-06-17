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
//获得的按uprice从大到小的GD排序
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
 //流程化思维！ 没想好，想好就很简单
 //首先 没有想到使用结构体！导致不方便 后来修改成结构体；
 //其次 想最后一个for循环时候花了很久在想如何实现算法
 //review：看完题目， 1、如何计算？（算法）
 //2、获得了按uprice从大到小的GD排序
 //如何实现输出最大利润？
