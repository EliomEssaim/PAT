
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int main()
{
	char sign,side,i,j,tmp;
	scanf("%d %c",&sign,&side);
	tmp=((int)((float)n/2.0+0.5)%1.0);
	for(j=0;j<tmp;j++)
	{
		if(j==1||j==n-1)
			for(i=0;i<n;i++)
				printf("%c",sign);
		else
		{
			printf("%c",sign);
			for(i=1;i<n-1;i++)
				printf(" ",sign);
			printf("%c",sign);
		}
	}
	



	return 0;
}
