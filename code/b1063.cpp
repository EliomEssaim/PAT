#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double tmpModulus,maxModulus=0;
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        tmpModulus=sqrt(a*a+b*b);
        if(tmpModulus>maxModulus)maxModulus=tmpModulus;
    }
    cout<<setprecision(2)<<fixed<<maxModulus;
    return 0;
}
