#include<iostream>
#include<string>
#include<map>
using namespace std;
string str,ans;
map<char,int> cntChar;
bool fail=false;
int main(){
    int carryBit=0;
    getline(cin,str);
    for(int i=(int)str.size()-1;i>=0;i--){
        cntChar[str[i]]++;
        ans.insert(0,to_string((carryBit+str[i]-'0'+str[i]-'0')%10));
        carryBit=(carryBit+str[i]-'0'+str[i]-'0')/10;
    }
    if(carryBit==1)ans.insert(0,"1");
    for(int i=0;i<(int)ans.size()&&!fail;i++)
        if(cntChar.count(ans[i])==0)fail=true;
        else cntChar[ans[i]]--;
    for(auto unit:cntChar)
        if(unit.second!=0)fail=true;
    if(fail)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    cout<<ans;
    return 0;
}
