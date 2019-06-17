
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int main()
{

	int n,loc,tar,j;
	int *p;
	while(scanf("%d",&n)!=EOF)
	{
		p=(int *)malloc(n*sizeof(int));
		memset(p,0,n*sizeof(int)/sizeof(char));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		scanf("%d",&tar);
		for(j=0;j<n;j++)
		{
			if(tar==p[j])
			{
				loc=j;
				break;
			}
		}
		if(j==n)
			printf("%d\n",-1);
		else
			printf("%d\n",loc);
	}



	return 0;
}
