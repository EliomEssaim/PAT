#include<iostream>
#include<string>
using namespace std;
bool dotFlag=false,digitFlag=false,alphabetFlag=false,otherFlag=false;
string input;
int main(){
    int n;
    cin>>n;
    while(cin.get()!='\n');
    for(int i=0;i<n;i++){
        input.clear();
        dotFlag=false,digitFlag=false,alphabetFlag=false,otherFlag=false;
        getline(cin,input);
        for(int j=0;j<(int)input.size();j++)
            if(isdigit(input[j]))digitFlag=true;
            else if(isalpha(input[j]))alphabetFlag=true;
            else if(input[j]=='.')dotFlag=true;
            else otherFlag=true;
        if(input.size()<6)cout<<"Your password is tai duan le."<<endl;
        else if(otherFlag)cout<<"Your password is tai luan le."<<endl;
        else if(!digitFlag)cout<<"Your password needs shu zi."<<endl;
        else if(!alphabetFlag)cout<<"Your password needs zi mu."<<endl;
        else cout<<"Your password is wan mei."<<endl;
    }

    return 0;
}
