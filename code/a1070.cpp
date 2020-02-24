#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    float price,unitPrice,inventory;
};
bool cmp(node a,node b){
    return a.unitPrice>b.unitPrice;
}
vector<node> moonCake;
int main(){
    int n,need;
    float profits=0.0;
    scanf("%d%d",&n,&need);
    moonCake.resize(n);
    for(int i=0;i<n;i++)scanf("%f",&moonCake[i].inventory);
    for(int i=0;i<n;i++){
        scanf("%f",&moonCake[i].price);
        moonCake[i].unitPrice=moonCake[i].price/moonCake[i].inventory;
    }
    sort(moonCake.begin(),moonCake.end(),cmp);
    int satisfy=0;
    for(int i=0;satisfy<need&&i<(int)moonCake.size();i++){
        if(need-satisfy>=moonCake[i].inventory){
            satisfy+=moonCake[i].inventory;
            profits+=moonCake[i].price;
        }else{
            profits+=moonCake[i].unitPrice*(need-satisfy);
            satisfy=need;
        }
    }
    printf("%.2f",profits);
    return 0;
}
