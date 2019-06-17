
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int month[2][13]={
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool IsLeapYear(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}
int main()
{
	int y1,m1,d1;
	int y2,m2,d2;
	int tmp,cnt;
	int time1,time2;
	//cnt错误位置 
	while(scanf("%d%d",&time1,&time2)!=EOF)
	{
		if(time2>time1)
		{
			tmp=time1;
			time1=time2;
			time2=tmp;
		}
		y1=time1/10000;
		y2=time2/10000;
		m1=time1%10000/100;
		m2=time2%10000/100;
		d1=time1%100;
		d2=time2%100;
		cnt=0;
		while(y1>y2||m1>m2||d1>d2)
		{
			d2++;
			if(d2==month[IsLeapYear(y2)][m2]+1)
			{
				d2=1;
				m2++;
			}
			if(m2==13)
			{
				y2++;
				m2=1;
			}
			cnt++;
		}
		printf("%d\n",cnt+1);
	}

	return 0;
}

//错误：没有对scanf取地址 对取20130101的day算法有误 
//错误：判断时间的函数放置的位置出错：流程设计有问题，因为不是自己想的流程； 
//错误：理解题意出错 最后得到的差值不是cnt而是cnt+1 
//错误：cnt的位置有误 
//常识：闰年的二月份有29天 
