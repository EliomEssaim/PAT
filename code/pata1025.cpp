#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct StuList{
	char reg[15];
	int score;
	int loc;
	int loc_rank;
	int rank;	
} Stu;
bool cmp(Stu a,Stu b)//含有结构体比较 cmp的输入参数如何定义 
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.reg,b.reg)<0;//字符串的比较大小 
}
int main()
{
	int loc_num,i,j,cls_num,num;
	int beg;
	Stu list[30010];
	num=0;
	scanf("%d",&loc_num);
	for(i=0;i<loc_num;i++)
	{
		scanf("%d",&cls_num);
		beg=num;//这个教室的开始序号 
		for(j=0;j<cls_num;j++)
		{
			scanf("%s",list[num].reg);
			scanf("%d",&list[num].score);
			list[num].loc=i+1;
			num++;
		}
		sort(list+beg,list+cls_num+beg,cmp);
		
		list[beg].loc_rank=1;
		for(j=beg+1;j<beg+cls_num;j++)
		{
			if(list[j].score==list[j-1].score)
				list[j].loc_rank=list[j-1].loc_rank;
			else
				list[j].loc_rank=j+1-beg;
		}
		
	}
	
	sort(list,list+num,cmp);
	list[0].rank=1;
	for(j=0;j<num;j++)
	{
		if(list[j].score==list[j-1].score)
			list[j].rank=list[j-1].rank;
		else
			list[j].rank=j+1;
	}
	
	printf("%d\n",num);
	for(j=0;j<num;j++)
	{
		printf("%s %d %d %d\n",list[j].reg,list[j].rank,list[j].loc,list[j].loc_rank);
	} 
	 
	 return 0;
} 
