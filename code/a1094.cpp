#include<iostream>
#include<vector>
using namespace std;
struct node{
    vector<int> childAddr;
};
vector<node> tree;
vector<int> depth;
int maxdepth=1,maxnum=1;
void dfs(int index,int d){
    depth[d]++;
    if(depth[d]>maxnum) {maxnum=depth[d];maxdepth=d;}
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        dfs(tree[index].childAddr[i],d+1);
    }
    return ;
}
int main(){
    int n,m,id,childNum;
    scanf("%d%d",&n,&m);
    tree.resize(n+1);
    depth.resize(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&childNum);
        tree[id].childAddr.resize(childNum);
        for(int j=0;j<childNum;j++)
            scanf("%d",&tree[id].childAddr[j]);
    }
    dfs(1,1);
    printf("%d %d\n",maxnum,maxdepth);
    return 0;
}
