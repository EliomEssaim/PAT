
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
char z[31]={0};
int main()
{
	int a,b,sum,d,i=0;
	scanf("%d%d%d",&a,&b,&d);
	sum=a+b;
	do
	{
		z[i++]=sum%d;
		sum=sum/d;
	}while(sum!=0);
	
	for(i=i-1;i>=0;i--)
		printf("%d",z[i]);
	printf("\n");

	return 0;
}

