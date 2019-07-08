#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,post,in;
bool isUnique=true;int inPos=0;
void inOrder(int root,int start,int eend){
    if(start>eend) return;
    int leftEnd=eend;
    while(pre[root+1]!=post[leftEnd]&&leftEnd!=-1) leftEnd--;
    int leftEndSize=leftEnd-start+1;
    if((start-eend+1)%2==0) isUnique=false;
    inOrder(root+1,start,leftEnd);
    in[inPos++]=pre[root];
    if(leftEnd!=-1) inOrder(root+1+leftEndSize,leftEnd+1,eend-1);
    else inOrder(root+1+leftEndSize,start+1,eend-1);//����д�����߼��������
}
int main(){
    int n;
    scanf("%d",&n);
    pre.resize(n);
    post.resize(n);
    in.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    inOrder(0,0,n-1);
    if(isUnique) printf("Yes\n");
    else printf("No\n");
    for(int i=0;i<n;i++)
        printf("%d%c",in[i],i==n-1?'\n':' ');
    return 0;
}
/*******************************************/
/*
�߼������������start��end˭��˭��û�����
Ӧ��һ�������ṩ���ڵ�һ�����������Լ�ȥ������һ�����ڵ㣻ͬʱ����һ���Լ��Ĳ��ҷ�Χ��
���Ȿ�β�ͬ����ͨ����������������������leftEnd=-1���������û�г�ֿ���=-1�������
�Ժ����ĳ����Ӱ�죨�����������ĺ����������Χ����ֱ仯��

�߼��������
��������һ����ǰ����ת������������һ��ȡֵ����
�����´ο��Կ���һ��ʲô����Ҫ��ʲô���������������
��root start eend������������Ͳ�����ģ���ĵط��ˡ�

ģ��Ľ��⣺
����������µ�ֵҪ���Ƕ�ԭ��ģ��Ĵ����Ӱ��

ѧϰ��ʽ��
�����ģ�庯���������������壬�ı����������ʲôӰ��

���Դ��ڵĵ��ã�
����-�����Դ���-������
����-�����Դ���-������ջ
*/
/********************************************/
