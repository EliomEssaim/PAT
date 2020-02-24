#include<iostream>
#include<vector>
using namespace std;
vector<int> preOrder,inOrder;
bool found=false;
int n;
void searchPostFirst(int start,int End,int rootIndexInPre){
    if(start>End)return;
    if(start==End){
        if(found)return;
        printf("%d",inOrder[start]);
        found=true;
    }
    int rootIndexInIn=start;
    for(;rootIndexInIn<End&&preOrder[rootIndexInPre]!=inOrder[rootIndexInIn];rootIndexInIn++);
    int leftSize=rootIndexInIn-start;
    searchPostFirst(start,rootIndexInIn-1,rootIndexInPre+1);
    searchPostFirst(rootIndexInIn+1,End,rootIndexInPre+leftSize+1);
}
int main(){
    cin>>n;
    preOrder.resize(n);
    inOrder.resize(n);
    for(int i=0;i<n;i++)scanf("%d",&preOrder[i]);
    for(int i=0;i<n;i++)scanf("%d",&inOrder[i]);
    searchPostFirst(0,n-1,0);
    return 0;
}
