#include"stdio.h"
int main()
{
	int n,step_num;
	step_num=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2==0)
			n=n/2;
		else
			n=(3*n+1)/2;
		step_num++;
	}
	printf("%d",step_num);
	
	return 0;
 } 
