#include<iostream>
#include<string>
using namespace std;
string ans,digit;
int repeatTimes=0,k;
int main(){
    cin>>digit>>repeatTimes;
    ans=digit;
    for(int i=0;i<repeatTimes-1;i++){
        ans.clear();
        for(int j=0;j<(int)digit.size();j=k){
            ans.push_back(digit[j]);
            for(k=j;k<(int)digit.size()&&digit[k]==digit[j];k++);
            ans+=to_string(k-j);
        }
        digit=ans;
    }
    cout<<ans;
    return 0;
}
