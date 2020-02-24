#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> preOrder;
unordered_map<int,bool> isExist;
int u,v,a,m,n;
int main(){
    cin>>m>>n;
    preOrder.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&preOrder[i]);
        isExist[preOrder[i]]=true;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        for(int i=0;i<n;i++){
            a=preOrder[i];
            if((u>=a&&v<=a)||(u<=a&&v>=a))break;
        }
        if(!isExist[u]&&!isExist[v])printf("ERROR: %d and %d are not found.\n",u,v);
        else if(!isExist[u])printf("ERROR: %d is not found.\n",u);
        else if(!isExist[v])printf("ERROR: %d is not found.\n",v);
        else if(u==a)printf("%d is an ancestor of %d.\n",u,v);
        else if(v==a)printf("%d is an ancestor of %d.\n",v,u);
        else printf("LCA of %d and %d is %d.\n",u,v,a);
    }
    return 0;
}
