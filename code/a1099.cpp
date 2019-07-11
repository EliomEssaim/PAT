#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int key,LeftChild,RightChild;
};
vector<node> tree;vector<int> Sequence,level;int j=0,leveli=0;
void BuildSearchTree(int root){
    if(root==-1) return ;
    BuildSearchTree(tree[root].LeftChild);
    tree[root].key=Sequence[j++];
    BuildSearchTree(tree[root].RightChild);
}
void LevelOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        level[leveli++]=tree[q.front()].key;//方便写法？
        if(tree[q.front()].LeftChild!=-1)
            q.push(tree[q.front()].LeftChild);
        if(tree[q.front()].RightChild!=-1)
            q.push(tree[q.front()].RightChild);
        q.pop();
    }
}
int main(){
    int n,lvalue,rvalue;
    scanf("%d",&n);
    Sequence.resize(n);
    level.resize(n);
    tree.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&lvalue,&rvalue);
        tree[i].LeftChild=lvalue;
        tree[i].RightChild=rvalue;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&Sequence[i]);
    }
    sort(Sequence.begin(),Sequence.end());
    BuildSearchTree(0);
    LevelOrder(0);
    for(int i=0;i<n;i++)
        printf("%d%c",level[i],i==n-1?'\n':' ');
    return 0;
}
//层序问题都可以用i解决
