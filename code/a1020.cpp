#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int pos,key;
};
vector<int> in,post;
vector<node> tree;
void pre(int postL,int postR,int inL,int inR,int posBegin){
    if(inL>inR)
        return;
    int k;
    for(int i=inL;i<=inR;i++)
        if(in[i]==post[postR]) {k=i;break;}
    tree.push_back(node{posBegin,in[k]});
    pre(postL,postL+k-inL-1,inL,k-1,2*posBegin);//这里写成了postL+k-inL不必要写两个区间
    pre(postL+k-inL,postR-1,k+1,inR,2*posBegin+1);//这里写错成pre(postL+k-inL,postR,k+1,inR,2*posBegin+1);
}
bool cmp(node a,node b){
    return  a.pos<b.pos;
}
int main() {
    int n;
    scanf("%d",&n);
    in.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    pre(0,n-1,0,n-1,1);
    sort(tree.begin(),tree.end(),cmp);
    for(int i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%d",tree[i].key);
    }

    return 0;
}
//后序+中序如何转层序
//从零开始要加上申请的空间是n+1
