#include<stdio.h>
#include<string.h>
int main()
{
	int num=0,i;
	char ans[90][90];
	while(scanf("%s",ans[num])!=EOF)
		num++;
	for(i=num-1;i>=0;i--)
	{
		printf("%s",ans[i]);
		if(i!=0) printf(" ");
	}
	
	
	return 0;
}

