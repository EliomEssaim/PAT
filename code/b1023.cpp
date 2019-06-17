#include<stdio.h>
#include<algorithm>
using namespace std;
int num[60]={0};
int cnt=10;
int main()
{
	int i,tmp,j=0;
	for(i=0;i<cnt;i++)
	{
		scanf("%d",&tmp);
		while(tmp--)
			num[j++]=i;
	}
//	sort(num,num+j); 
	
	for(i=1;i<j;i++)
	{
		if(num[i]!=0)
			break;
	}
	printf("%d",num[i]);
	num[i]=-1;//review：这里可以赋值成11吗？为什么？ 
//	sort(num,num+j);

	for(i=0;i<j;i++)
	{
		if(num[i]!=-1)
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}
//思考漏洞： 
//算法冗余：不需要排序自然成序 
