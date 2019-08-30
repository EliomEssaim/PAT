#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> eva;
int main(){
    string owner,target;
    getline(cin,owner);
    getline(cin,target);
    for(int i=0;i<(int)target.size();i++)
        eva[target[i]]++;
    int extra=owner.size(),scanty=target.size();
    for(int i=0;i<(int)owner.size();i++){
        if(eva.find(owner[i])!=eva.end()&&eva[owner[i]]!=0){//È±ÉÙÌõ¼ş
            eva[owner[i]]--;
            scanty--;extra--;
        }
    }
    if(scanty!=0)cout<<"No "<<scanty;
    else cout<<"Yes "<<extra;
    return 0;
}
