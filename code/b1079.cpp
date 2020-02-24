#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string sum,revStr,str;
string addStr(string &a,string &b){
    string ans;
    int carryBit=0,sum=0;
    for(int i=a.size()-1;i>=0;i--){
        sum=a[i]-'0'+b[i]-'0'+carryBit;
        ans.insert(0,to_string(sum%10));
        carryBit=sum/10;
    }
    if(carryBit==1)ans.insert(0,"1");
    return ans;
}
int main(){
    int iteratorTimes=0;
    cin>>str;
    while(iteratorTimes<10){
        revStr=str;
        reverse(revStr.begin(),revStr.end());
        if(revStr==str){
            cout<<str<<" is a palindromic number."<<endl;
            return 0;
        }
        sum=addStr(str,revStr);
        cout<<str<<" + "<<revStr<<" = "<<sum<<endl;
        str=sum;
        iteratorTimes++;
    }
    cout<<"Not found in 10 iterations." <<endl;
    return 0;
}
