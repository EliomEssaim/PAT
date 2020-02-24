#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> coupon,product;
long long maxGet=0;
int main(){
    int n;
    cin>>n; coupon.resize(n);
    for(auto &unit:coupon)cin>>unit;
    sort(coupon.begin(),coupon.end());
    cin>>n;product.resize(n);
    for(auto &unit:product)cin>>unit;
    sort(product.begin(),product.end());
    int cLeft=0,cRight=coupon.size()-1,pLeft=0,pRight=product.size()-1;
    while(cLeft<(int)coupon.size()&&pLeft<(int)product.size()&&coupon[cLeft]<0&&product[pLeft]<0){
        maxGet+=coupon[cLeft]*product[pLeft];
        cLeft++;pLeft++;
    }
    while(cRight>=0&&pRight>=0&&coupon[cRight]>0&&product[pRight]>0){
        maxGet+=coupon[cRight]*product[pRight];
        cRight--;pRight--;
    }
    cout<<maxGet;
    return 0;
}
