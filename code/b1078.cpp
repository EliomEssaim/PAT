#include<iostream>
#include<string>
using namespace std;
int main(){
    string command,originInput,ans;
    cin>>command;
    while(cin.get()!='\n');
    getline(cin,originInput);
    if(command=="C"){
        int leftIndex=0;
        for(int i=0;i<(int)originInput.size();i++){
            leftIndex=i;
            while(originInput[leftIndex]==originInput[i])i++;
            i--;
            if(i!=leftIndex)ans+=to_string(i-leftIndex+1);
            ans+=originInput.substr(leftIndex,1);
        }
        cout<<ans;
    }else {
        for(int i=0;i<(int)originInput.size();i++){
            if(!isdigit(originInput[i]))cout<<originInput[i];
            else{
                int repeatTimes,leftIndex=i;
                while(isdigit(originInput[i]))i++;
                repeatTimes=stoi(originInput.substr(leftIndex,i-leftIndex));
                for(int j=0;j<repeatTimes;j++)cout<<originInput[i];
            }
        }
    }
    return 0;
}
