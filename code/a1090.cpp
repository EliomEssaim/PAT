#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxDepth=0,num=1;
vector<int> tree[100010];
void dfs(int index,int d){
    if(tree[index].empty()){
        if(d>maxDepth){
            maxDepth=d;
            num=1;
        }else if(d==maxDepth){
            num++;
        }
    }
    for(int i=0;i<(int)tree[index].size();i++){
        dfs(tree[index][i],d+1);
    }
    return;
}
double p,r,maxPrice;
int main(){
    int n;
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;int root=0,tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);//不熟悉下标和值的关系
        if(tmp==-1) root=i;
        else tree[tmp].push_back(i);
    }
    dfs(root,0);
    maxPrice=p*pow(1+r,maxDepth);
    printf("%.2f %d",maxPrice,num);

    return 0;
}

