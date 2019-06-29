#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int data,next,addr;
}Node[100000];
int main()
{
    int firstNode,N,K;
    scanf("%d%d%d",&firstNode,&N,&K);
    int pos,tmp=N,key,next;
    while(tmp--)
    {
        scanf("%d%d%d",&pos,&key,&next);
        Node[pos].data=key;Node[pos].next=next;Node[pos].addr=pos;
    }
    vector<node> List(N);
    int ListLen=0;
    for(int i=firstNode;i!=-1;i=Node[i].next,ListLen++){
            List[ListLen].data=Node[i].data;List[ListLen].addr=i;
    }
    for(int i=1;List.begin()+K*i<=List.begin()+ListLen;i++)
        reverse(List.begin()+K*(i-1),List.begin()+K*i);
    for(int i=0;i<ListLen-1;i++)
        printf("%05d %d %05d\n",List[i].addr,List[i].data,List[i+1].addr);
    printf("%05d %d %d\n",List[ListLen-1].addr,List[ListLen-1].data,-1);
    return 0;
}
//如何将链表反转的思路？
//不是静态链表的话可以用头插法解决，来一个拆一个
//静态链表可以使用数组解决，形成顺序。
