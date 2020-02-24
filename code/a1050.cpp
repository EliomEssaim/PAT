#include<iostream>
#include<string>
using namespace std;
bool isExist[300]={0};
string s1,s2;
int main(){
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<(int)s2.size();i++)
        isExist[(int)s2[i]]=true;
    for(int i=0;i<(int)s1.size();i++)
        if(!isExist[(int)s1[i]])printf("%c",s1[i]);
    return 0;
}
