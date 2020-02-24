#include<iostream>
#include<string>
using namespace std;

int main(){
    string dend,ans;int sor;
    cin>>dend>>sor;
    int res=0,readNum;
    for(int i=0;i<(int)dend.size();i++){
        readNum=res*10+stoi(dend.substr(i,1));
        if(readNum<sor){
            ans+=to_string(0);
            res=dend[i]-'0';//Íü¼ÇÐ´ÁË
        }
        else{
            res=readNum%sor;
            ans+=to_string(readNum/sor);//Ð´´í
        }
    }
    auto it=ans.begin();
    while(ans!="0"&&it!=ans.end()){
        if(*it!='0') break;
        ans.erase(it);
        it=ans.begin();
    }
    cout<<ans<<" "<<res<<endl;
    return 0;
}
