#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;
const int maxLenth=10010;
bool isPrime[maxLenth], isCheck[maxLenth],isExist[maxLenth];
vector<string> reward(maxLenth);
int main(){
    memset(isPrime,true,sizeof(bool)*maxLenth);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<maxLenth;i++)
        for(int j=2;i*j<maxLenth;j++)
        isPrime[i*j]=false;
    int n,id;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>id;
        isExist[id]=true;
        if(i==1)reward[id]="Mystery Award";
        else if(isPrime[i])reward[id]="Minion";
        else reward[id]="Chocolate";
    }
    int k;cin>>k;
    for(int i=0;i<k;i++){
        cin>>id;
        cout<<setw(4)<<setfill('0')<<id<<": ";
        if(isCheck[id]==false&&isExist[id]){
            cout<<reward[id]<<endl;
            isCheck[id]=true;
        }else if(isCheck[id]) cout<<"Checked"<<endl;
        else cout<<"Are you kidding?"<<endl;
    }
    return 0;
}
