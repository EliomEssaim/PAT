#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct node{
    double products;
    vector<int> childAddr;
};
vector<node> Node;
double totalSales=0,p,r;
void dfs(int index,int depth){
    if(Node[index].childAddr.empty()){
        totalSales+=pow((1+r),(double)depth)*Node[index].products;
        return ;
    }
    for(int i=0;i<(int)Node[index].childAddr.size();i++){
        dfs(Node[index].childAddr[i],depth+1);
    }
}
int main(){
    int childSize,n;
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100.0;
    Node.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&childSize);
        if(childSize) Node[i].childAddr.resize(childSize);
        else scanf("%lf",&Node[i].products);
        for(int j=0;j<childSize;j++){
            scanf("%d",&Node[i].childAddr[j]);
        }
    }
    dfs(0,0);
    printf("%.1f\n",p*totalSales);
    return 0;
}
