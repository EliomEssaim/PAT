#include<iostream>
#include<vector>
#include<cmath>
#include<cfloat>
using namespace std;
struct node{
    vector<int> childAddr;
};
vector<node> tree;
double p,r,minPrice=DBL_MAX;int numRetailers=0;
void dfs(int index,int depth){
    if(tree[index].childAddr.empty()){//��������
        double tmpPrice=p*pow(1+r,depth);//���ʹ���
        if(tmpPrice<minPrice){
            minPrice=tmpPrice;
            numRetailers=1;
        }
        else if(tmpPrice==minPrice) numRetailers++;
        return ;
    }
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        dfs(tree[index].childAddr[i],depth+1);
    }
}
int main(){
    int n,kids,id;
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;
    tree.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&kids);
        if(kids){
            tree[i].childAddr.resize(kids);
            for(int j=0;j<kids;j++){//д������������
                scanf("%d",&id);
                tree[i].childAddr[j]=id;//û�и�ֵ
            }
        }
    }
    dfs(0,0);
    printf("%.4f %d",minPrice,numRetailers);
    return 0;
}
