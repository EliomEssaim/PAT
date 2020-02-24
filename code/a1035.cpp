#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,char> trans;
string ID,pwd,ans;
bool isModify=false;
int main(){
    trans['1']='@';
    trans['0']='%';
    trans['l']='L';
    trans['O']='o';
    int n,cntModify=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ID>>pwd;
        isModify=false;
        for(int j=0;j<(int)pwd.size();j++)
            if(trans.count(pwd[j])!=0){
                 pwd[j]=trans[pwd[j]];
                 isModify=true;
            }
        if(isModify)ans+=ID+" "+pwd+"\n";
        if(isModify)cntModify++;
    }
    if(cntModify==0){
        if(n==1)cout<<"There is 1 account and no account is modified"<<endl;
        else cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }else{
        cout<<cntModify<<endl;
        cout<<ans;
    }
    return 0;
}
