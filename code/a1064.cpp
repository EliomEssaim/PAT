#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int maxn,cntFill=0;
vector<int> tree,preOrder;
void buildTree(int root){
    if(root*2<=maxn)buildTree(root*2);
    tree[root]=preOrder[cntFill++];
    if(root*2+1<=maxn)buildTree(root*2+1);
    return;
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top=q.front();
        if(top!=1)printf(" ");
        printf("%d",tree[top]);
        q.pop();
        if(top*2<=maxn)q.push(top*2);
        if(top*2+1<=maxn)q.push(top*2+1);
    }
}
int main(){
    cin>>maxn;
    tree.resize(maxn+1);
    preOrder.resize(maxn);
    for(int i=0;i<maxn;i++)
        scanf("%d",&preOrder[i]);
    sort(preOrder.begin(),preOrder.end());
    buildTree(1);
    bfs(1);
    return 0;
}
