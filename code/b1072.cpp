#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isBanItem[10010]={0};
vector<int> banList;
int main(){
    int n,m,id,tmp,problemStu=0,banItems=0;
    string name;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>id;
        isBanItem[id]=true;
    }
    for(int i=0;i<n;i++){
        cin>>name>>tmp;
        banList.clear();
        for(int j=0;j<tmp;j++){
            cin>>id;
            if(isBanItem[id]){
                banList.push_back(id);
                banItems++;
            }
        }
        if(!banList.empty()){
            cout<<name<<":";
            problemStu++;
        }
        for(int k=0;k<(int)banList.size();k++)printf(" %04d",banList[k]);
        if(!banList.empty())cout<<endl;
    }
    cout<<problemStu<<" "<<banItems<<endl;
    return 0;
}
