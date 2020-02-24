#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    float uPrice;int quota,totalSale;
};
bool cmp(node a,node b){
    return a.uPrice>b.uPrice;
}
int market,leftMarket,n;float sale;
vector<node> goods;
int main(){
    cin>>n>>market;leftMarket=market;
    goods.resize(n);sale=0.0;
    for(int i=0;i<n;i++){
        cin>>goods[i].quota;
    }
    for(int i=0;i<n;i++){
        cin>>goods[i].totalSale;
        goods[i].uPrice=(float)goods[i].totalSale/(float)goods[i].quota;
    }
    sort(goods.begin(),goods.end(),cmp);
    int index=0;
    while(leftMarket>0&&index<market){
        if(goods[index].quota<leftMarket){
            leftMarket-=goods[index].quota;
            sale+=(float)goods[index].totalSale;
        }else{
            sale+=(float)leftMarket*goods[index].uPrice;
            leftMarket=0;
        }
        index++;
    }
    printf("%.2f\n",sale);
    return 0;
}
