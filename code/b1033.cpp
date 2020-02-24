#include<iostream>
#include<string>
using namespace std;
bool broken[500]={0};
bool plusFlag=false;
int main(){
    string str;
    getline(cin,str);
    for(int i=0;i<(int)str.size();i++){
        if(str[i]!='+') {
            broken[str[i]]=true;
            broken[tolower(str[i])]=true;
        }
        else plusFlag=true;
    }
    getline(cin,str);
    for(int i=0;i<(int)str.size();i++){
        if(broken[str[i]])continue;
        if(plusFlag&&isupper    (str[i]))continue;
        cout<<str[i];
    }
    return 0;
}
