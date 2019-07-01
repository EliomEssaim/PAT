#include<iostream>
#include<vector>
#include<queue>
#define maxn 1000
using namespace std;
struct node{
    int data;
    int layer;
    vector<int> child;
} Node[maxn];
void PreOrder(int root){
    printf("%d",Node[root].data);
    for(int i=0; i<(int)Node[root].child.size(); i++)
        PreOrder(Node[root].child[i]);
}
void LayerOrder(int root){
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int tmp=Q.front();
        Q.pop();
        printf("%d",Node[tmp].data);
        for(int i=0;i<Node[tmp].child.size();i++){
            int child=Node[tmp].child[i];//这个是地址
            Node[child].layer=Node[tmp].layer+1;
            Q.push(Node[tmp].child[i]);
        }
    }
}
int main()
{

    return 0;
}
