#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int addr,value,next;
    bool flag=false;
}Node[100000];
bool cmp(node a,node b)
{
    return (a.flag&&b.flag)?a.value<b.value:a.flag>b.flag;
}
int main()
{
    int n,begAddr;
    scanf("%d%d",&n,&begAddr);
    int addr,key,next;
    while(n--)
    {
        scanf("%d%d%d",&addr,&key,&next);
        Node[addr].addr=addr;
        Node[addr].value=key;
        Node[addr].next=next;
    }
    int cnt=0;
    for(int i=begAddr;i!=-1;i=Node[i].next)
    {
        Node[i].flag=true;
        cnt++;
    }
    if(cnt==0) {printf("0 -1\n");return 0;}
    sort(Node,Node+100000,cmp);
    printf("%d %05d\n",cnt,Node[0].addr);
    for(int i=0;i<cnt;i++)
        if(i+1<cnt)
            printf("%05d %d %05d\n",Node[i].addr,Node[i].value,Node[i+1].addr);
        else
            printf("%05d %d -1\n",Node[i].addr,Node[i].value);
    return 0;
}
//while(Node[value+100000].cnt--)
//无法解决有多个链表的问题
