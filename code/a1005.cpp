#include<iostream>
#include<string>
using namespace std;
string toEng[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string input;
int sum=0;
bool firstOut=true;
int main(){
    getline(cin,input);
    for(auto val:input)
        sum+=val-'0';
    for(auto &val:to_string(sum)){
        if(!firstOut)cout<<" ";
        cout<<toEng[val-'0'];firstOut=false;
    }

    return 0;
}
