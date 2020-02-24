#include<iostream>
using namespace std;
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
bool firstOut=true;
int main(){
    int n1,m1,n2,m2,k;
    char c;
    cin>>n1>>c>>m1>>n2>>c>>m2>>k;
    int m1m2Gcd=gcd(m1,m2),minGANm1m2=m1*m2/m1m2Gcd;
    int finGcd=gcd(minGANm1m2,k),finGAN=minGANm1m2*k/finGcd;
    int start=finGAN/m1*n1,end=finGAN/m2*n2,plusFactorK=finGAN/k;
    if(end<start) swap(start,end);
    for(int i=start+1;i<end;i++)
    if(i%plusFactorK==0&&gcd(i/plusFactorK,k)==1){
        if(!firstOut)cout<<" ";
        cout<<i/plusFactorK<<"/"<<k;
        firstOut=false;
    }
    return 0;
}
