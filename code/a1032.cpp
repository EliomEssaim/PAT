#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct node{
    char data;
    int next;
    bool flag;
}Node[100000];
int main()
{
    int word1Head,word2Head;
    int n;
    scanf("%d %d %d",&word1Head,&word2Head,&n);
    int adr1,adr2;
    char tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d %c %d",&adr1,&tmp,&adr2);
        Node[adr1].data=tmp;
        Node[adr1].next=adr2;
    }
    for(int i=word1Head;i!=-1;i=Node[i].next)
        Node[i].flag=true;
    for(int i=word2Head;i!=-1;i=Node[i].next)
    {
        if(Node[i].flag)
        {printf("%05d\n",i);return 0;}//Íü¼Ç²¹ÆëÎ»Êý
    }
    printf("-1\n");

    return 0;
}
