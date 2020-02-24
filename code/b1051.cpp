#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double r1,r2,p1,p2;
int main(){
    cin>>r1>>p1>>r2>>p2;
    double r=r1*r2,p=p1+p2;
    double a=r*cos(p),b=r*sin(p);
    if(a+0.005>=0&&a<0)cout<<setprecision(2)<<fixed<<0.00;
    else cout<<setprecision(2)<<fixed<<a;
    if(b+0.005>=0&&b<0){
        cout<<"+";
        cout<<setprecision(2)<<fixed<<0.00;
    }
    else{
        if(r*sin(p)>0)cout<<"+";
        cout<<setprecision(2)<<fixed<<b;
    }
    cout<<"i"<<endl;
    return 0;
}
