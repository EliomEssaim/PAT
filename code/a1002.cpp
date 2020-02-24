#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include<iomanip>
using namespace std;
const int lenth=1000;
const float eps=1e-10;
float aPloy[lenth]={0},cof;
string ans;
int main(){
    int n,exp,validCnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>exp>>cof;
        aPloy[exp]=cof;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>exp>>cof;
        aPloy[exp]+=cof;
    }
    for(int i=lenth-1;i>=0;i--)
        if(fabs(aPloy[i])>eps){
            validCnt++;
            stringstream ss;
            ss<<setprecision(1)<<fixed<<aPloy[i];
            ans+=" "+to_string(i)+" "+ss.str();
        }
    cout<<validCnt<<ans;
    if(validCnt==0)cout<<" 0 0"<<endl;
    return 0;
}
