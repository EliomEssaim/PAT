#include<iostream>
using namespace std;
int saleData[110]={0},maxSale=0;
bool firstOut=true;
int main(){
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            saleData[j]+=tmp;
            if(saleData[j]>maxSale)maxSale=saleData[j];
        }
    }
    cout<<maxSale<<endl;
    for(int j=1;j<=n;j++)
    if(saleData[j]==maxSale){
        if(!firstOut)cout<<" ";
        cout<<j;firstOut=false;
    }
    return 0;
}
