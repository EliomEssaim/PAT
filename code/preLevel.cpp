#include<iostream>
using namespace std;
int in[6]={1,3,7,2,6,4};
int level[6]={2,3,6,1,7,4};
bool isVisit[6]={0};
void createTree(int root,int start,int eend){
    if(start>eend) return ;
    printf("%d ",level[root]);
    isVisit[root]=1;
    int k=start,i,j;
    i=j=root;
    while(in[k]!=level[root]) k++;
    while(isVisit[i]!=1) i++;
    j=i+1;
    createTree(root+i,start,k-1);
    createTree(root+j,i+1,eend);
}
int main(){

}
