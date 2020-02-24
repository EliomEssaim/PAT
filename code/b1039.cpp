#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> giveBeads(500);
int lackNum=0,lenthGiveBeads=0,lenthNeedBeads=0;
int main(){
    string giveStr;cin>>giveStr;
    for(int i=0;i<(int)giveStr.size();i++)giveBeads[giveStr[i]]++;
    while(cin>>tmp){
        if(--giveBeads[tmp]<0)lackNum++;
        lenthNeedBeads++;
    }
    if(lackNum!=0)cout<<"Yes "<<giveStr.size()-lenthNeedBeads<<endl;
    else cout<<"No "<<lackNum<<endl;
    return 0;
}
