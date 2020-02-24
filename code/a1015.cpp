#include<iostream>
using namespace std;
int num,radix;
bool isPrime(int num){
    if(num==0||num==1)return false;
    for(int i=2;i*i<num;i++)
        if(num%i==0)return false;
    return true;
}
int main(){
    while(1){
        cin>>num;
        if(num<0)break;
        cin>>radix;
        if(!isPrime(num)){cout<<"No"<<endl;continue;}
        int  lenth=0,arr[100];
        for(;num!=0;num/=radix)arr[lenth++]=num%radix;
        for(int i=lenth-1,factor=1;i>=0;i--,factor*=radix)num+=arr[i]*factor;
        isPrime(num)?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
