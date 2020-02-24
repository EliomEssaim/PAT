#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    string data[3];
};
int colSwitch=0;
bool cmp(node a,node b){
    return a.data[colSwitch]==b.data[colSwitch]?a.data[0]<b.data[0]:a.data[colSwitch]<b.data[colSwitch];
}
vector<node> stuList;
int main(){
    int n;
    cin>>n>>colSwitch;
    colSwitch--;
    stuList.resize(n);
    for(auto &unit:stuList)
        cin>>unit.data[0]>>unit.data[1]>>unit.data[2];
    sort(stuList.begin(),stuList.end(),cmp);
    for(auto &unit:stuList)
        cout<<unit.data[0]<<" "<<unit.data[1]<<" "<<unit.data[2]<<endl;
    return 0;
}
