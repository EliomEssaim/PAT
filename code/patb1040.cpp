#include<stdio.h>
#include<string.h>
int main()
{
	int len,i,ans=0;
	int LeftNumP[100010]={0},RightNumT[10010]={0};
	char str[100010];
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(i!=0)
		{
			if(str[i]=='P')
				LeftNumP[i]=LeftNumP[i-1]+1;
			else
				LeftNumP[i]=LeftNumP[i-1];
		
		
		
			if(str[len-1-i]=='T')
				RightNumT[len-1-i]=RightNumT[len-i]+1;
			else
				RightNumT[len-1-i]=RightNumT[len-i];
		
		}
		else
		{
			if(str[i]=='P')
				LeftNumP[i]+=1;
			if(str[len-1-i]=='T')
				RightNumT[len-1-i]+=1;
		}
		
	}
	
	for(i=0;i<len;i++)
	{
		if(str[i]=='A')
		{
			ans=(ans+LeftNumP[i]*RightNumT[i]%1000000007)%1000000007;
		}
	}
	
	printf("%d\n",ans);
	return 0;	
 } 
