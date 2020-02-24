#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> virgin(55),ans(55);
vector<int> shuffing(55);
string cardF="SHCDJ";
int main(){
    int cntVirgin=1,n;
    for(int i=0;i<(int)cardF.size();i++)
        for(int j=1;j<=13;j++)
            if(cntVirgin<55)
                virgin[cntVirgin++]=cardF.substr(i,1)+to_string(j);
    cin>>n;
    for(int i=1;i<(int)shuffing.size();i++)cin>>shuffing[i];
    for(int i=0;i<n;i++){
        for(int j=1;j<55;j++)
            ans[shuffing[j]]=virgin[j];
        virgin=ans;
    }
    for(int i=1;i<(int)ans.size();i++){
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }

    return 0;
}
