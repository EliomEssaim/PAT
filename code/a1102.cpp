#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int lchild;
    int rchild;
};
vector<node> tree;bool flag=true;
void Level(int root){//也可以用dfs+层用sort排序输出也层序遍历更简洁
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int frontIndex=q.front();
        if(q.front()!=root) printf(" %d",frontIndex);
        else printf("%d",frontIndex);
        q.pop();
        if(tree[frontIndex].lchild!=-1)
            q.push(tree[frontIndex].lchild);
        if(tree[frontIndex].rchild!=-1)
            q.push(tree[frontIndex].rchild);
    }
    printf("\n");
}
void inOrder(int index){
    if(index==-1) return;
    inOrder(tree[index].lchild);
    if(flag) {printf("%d",index);flag=false;}
    else printf(" %d",index);
    inOrder(tree[index].rchild);
}
int main(){
    int n,root=0;
    vector<bool> rootFake;
    char L,R;
    scanf("%d",&n);
    getchar();
    tree.resize(n);rootFake.resize(n);
    for(int i=0;i<n;i++){
        scanf("%c %c",&L,&R);
        getchar();
        if(L!='-') {tree[i].rchild=L-'0';rootFake[L-'0']=true;}
        else {tree[i].rchild=-1;}
        if(R!='-') {tree[i].lchild=R-'0';rootFake[R-'0']=true;}
        else {tree[i].lchild=-1;}
    }
    while(rootFake[root]) root++;
    Level(root);
    inOrder(root);
    return 0;
}
