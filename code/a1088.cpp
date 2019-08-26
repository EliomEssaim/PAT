#include<iostream>
#include<algorithm>
using namespace std;
typedef long long type;
type gcd(type a,type b){
    return a%b==0?b:gcd(b,a%b);
}
void display(int a1,int b1){
    if(a1==0) {cout<<0<<" ";return;}
    bool k=false;
    if(a1<0){cout<<"(-";a1=abs(a1);k=true;}
    if(a1>b1){cout<<a1/b1<<" ";a1=a1%b1;}
    else{
        cout<<a1<<"/"<<b1;
        if(k) cout<<") ";
        else cout<<" ";
    }
}
int main(){
    type a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    int g1=gcd(a1,b1),g2=gcd(a2,b2);
    a1/=g1;b1/=g1;a2/=g2;b2/=g2;
    display(a1,b1);cout<<"+ ";display(a2,b2);


    return 0;
}
