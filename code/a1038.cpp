#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string a,string b){
    a.size()<b.size()?a.insert(a.size(),b.substr(0,b.size()-a.size())):b.insert(b.size(),a.substr(0,a.size()-b.size()));
    return a<b;
}
vector<string> numList;
int main(){
    int n,index=0;
    cin>>n;
    string str,ans;
    numList.resize(n);
    for(int i=0;i<n;i++) cin>>numList[i];
    sort(numList.begin(),numList.end(),cmp);
    for(int i=0;i<(int)numList.size();i++) ans+=numList[i];
    while(ans[index]=='0'&&index<(int)ans.size())index++;
    ans=ans.substr(index);
    if(ans.empty())cout<<"0";
    else cout<<ans;
    return 0;
}
