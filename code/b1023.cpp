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
	num[i]=-1;//review��������Ը�ֵ��11��Ϊʲô�� 
//	sort(num,num+j);

	for(i=0;i<j;i++)
	{
		if(num[i]!=-1)
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}
//˼��©���� 
//�㷨���ࣺ����Ҫ������Ȼ���� 
