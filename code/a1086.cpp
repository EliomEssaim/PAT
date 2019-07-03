#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
vector<int> pre,in,post;
int ipost=0;
void PostOrder(int root,int start,int eend){
    if(start>eend) return;
    int i=start;
    for(;i<eend;i++)if(in[i]==pre[root]) break;
    PostOrder(root+1,start,i-1);
    PostOrder(root+i-start+1,i+1,eend);
    post[ipost++]=pre[root];
}
int main()
{
    int n,num,ipre,iin;string command;
    stack<int> s;ipre=iin=0;
    scanf("%d",&n);
    pre.resize(n);in.resize(n);post.resize(n);
    while(ipre!=n||iin!=n){
        scanf("%s",&command[0]);
        if(command[1]=='u'){
            scanf("%d",&num);
            pre[ipre++]=num;
            s.push(num);
        }else{
            in[iin++]=s.top();
            s.pop();
        }
    }
    PostOrder(0,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d%c",post[i],i==n-1?'\n':' ');

    return 0;
}
