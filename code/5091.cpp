#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,flg=0;
	char str[255];
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		for(i=0;i<=len-i-1;i++)
		{
			if(str[i]!=str[len-i-1])
				{
					flg=1;
					break;
				}
		 } 
		 if(flg)
		 	printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
//输入字符串必需是定长的 
