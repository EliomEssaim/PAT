#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    vector<int> childAddr;
};
vector<node> tree;vector<int> layerLeaves;
void bfs(int root){//也有先序写法更简洁
    queue<int> q;
    int layerEnd=root;
    int layer=0;
    q.push(root);
    while(!q.empty()){
        int frontAddr=q.front();
        q.pop();
        if(tree[frontAddr].childAddr.empty()) layerLeaves[layer]++;
        for(int i=0;i<(int)tree[frontAddr].childAddr.size();i++){
            q.push(tree[frontAddr].childAddr[i]);
        }
        if(frontAddr==layerEnd){
            if(layerEnd!=root)printf(" %d",layerLeaves[layer]);
            else printf("%d",layerLeaves[layer]);
            if(!q.empty()) layerEnd=q.back();
            layer++;
        }
    }
}
int main(){
    int n,m,node,nodeSize;
    scanf("%d%d",&n,&m);
    tree.resize(n+1);layerLeaves.resize(n+1);
    fill(layerLeaves.begin(),layerLeaves.end(),0);
    for(int i=0;i<m;i++){
        scanf("%d%d",&node,&nodeSize);
        tree[node].childAddr.resize(nodeSize);
        for(int j=0;j<nodeSize;j++){
            scanf("%d",&tree[node].childAddr[j]);
        }
    }
    bfs(1);
    return 0;
}
