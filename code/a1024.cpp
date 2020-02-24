#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string addStr(string a,string b){
    string ans;
    int carryBit=0;
    for(int i=(int)a.size()-1;i>=0;i--){
        ans.insert(0,to_string((carryBit+a[i]-'0'+b[i]-'0')%10));
        carryBit=(carryBit+a[i]-'0'+b[i]-'0')/10;
    }
    if(carryBit==1)ans.insert(0,"1");
    return ans;
}
int main(){
    int steps,k;
    string input,rev;
    cin>>input>>k;
    for(steps=0;steps<k;steps++){
        rev=input;
        reverse(input.begin(),input.end());
        if(input==rev){
            cout<<input<<endl;
            cout<<steps<<endl;
            return 0;
        }
        input=addStr(rev,input);
    }
    cout<<input<<endl;
    cout<<steps<<endl;
    return 0;
}
