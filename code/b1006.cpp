#include<iostream>
#include<string>
using namespace std;
string output;
string geFull="123456789";
int main(){
    string input;
    cin>>input;
    int i=input.size()-1;
    output=geFull.substr(0,input[i]-'0');
    if(input.size()>=2) {
        i--;for(int j=0;j<input[i]-'0';j++) output.insert(0,"S");
    }
    if(input.size()>=3){
         i--;for(int j=0;j<input[i]-'0';j++) output.insert(0,"B");
    }
    cout<<output;
    return 0;
}
