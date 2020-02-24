#include<iostream>
#include<vector>
using namespace std;
bool isHeap,maxHeap,firstOut=true;
vector<int> tree;
void postPrint(int root){
    int left=root*2,right=left+1;
    if(left<(int)tree.size())postPrint(left);
    if(right<(int)tree.size())postPrint(right);
    printf("%s%d",firstOut?"":" ",tree[root]);
    firstOut=false;
}
void heapJudge(int root){
    if(isHeap==false)return;
    int left=root*2,right=left+1;
    if(left<(int)tree.size()){
        if(maxHeap&&tree[left]>tree[root])isHeap=false;
        if(!maxHeap&&tree[left]<tree[root])isHeap=false;
        heapJudge(left);
    }
    if(right<(int)tree.size()){
        if(maxHeap&&tree[left]>tree[root])isHeap=false;
        if(!maxHeap&&tree[left]<tree[root])isHeap=false;
        heapJudge(right);
    }
}
int main(){
    int n,m;
    cin>>m>>n;
    tree.resize(n+1);
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&tree[j]);
        int index=2;
        while(tree[index]==tree[1]&&index<=n)index++;
        maxHeap=tree[1]>tree[index]?true:false;
        isHeap=true;firstOut=true;
        heapJudge(1);
        if(isHeap)printf("%s\n",maxHeap?"Max Heap":"Min Heap");
        else printf("Not Heap\n");
        postPrint(1);
        printf("\n");
    }
    return 0;
}
