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
    else inOrder(root+1+leftEndSize,start+1,eend-1);//这里写错了逻辑不清楚，
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
逻辑不清楚，首先start和end谁是谁的没搞清楚
应该一个序列提供跟节点一个序列利用自己去锁定下一个根节点；同时更新一下自己的查找范围。
此外本次不同于普通的中序遍历，会出现特殊结果leftEnd=-1；的情况，没有充分考虑=-1的情况下
对后续的程序的影响（例如右子树的后序的锁定范围会出现变化）

逻辑想的慢：
正常：第一次做前后序转中序；难免会对下一次取值生疏
但是下次可以考量一下什么函数要做什么，这个变量的意义
如root start eend的意义搞清楚后就不会有模糊的地方了。

模板改进题：
如果出现了新的值要考虑对原有模板的代码的影响

学习方式：
搞清楚模板函数各个参量的意义，改变他会有造成什么影响

调试窗口的调用：
调试-》调试窗口-》监视
调试-》调试窗口-》调用栈
*/
/********************************************/
