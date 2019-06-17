
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int main()
{

	int n,loc,tar;
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
		for(int i=0;i<n;i++)
		{
			if(tar==p[i])
			{
				loc=i;
				break;
			}
		}
		if(i==n)
			printf("%d\n",-1);
		else
			printf("%d\n",loc);
	}



	return 0;
}

