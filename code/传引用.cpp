
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int main()
{
	char sign,side,i,j,n;
	scanf("%d %c",&side,&sign);
	if(side%2==1)
		n=side/2+1;
	else
		n=side/2; 
	for(j=0;j<n;j++)
	{
		if(j==0||j==n-1)
		{
			for(i=0;i<side;i++)
				printf("%c",sign);
			printf("\n");
		}
		else
		{
			printf("%c",sign);
			for(i=1;i<side-1;i++)
				printf(" ",sign);
			printf("%c",sign);
			printf("\n");
		}
	}
	

	return 0;
}
//整数的四舍五入用分类讨论
