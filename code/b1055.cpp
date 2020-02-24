#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct node{
    string name;int height;
};
bool cmp(node a,node b){
    if(a.height!=b.height)return a.height>b.height;
    else return a.name<b.name;
}
vector<node> List;
int main(){
    int n,k,cntList=0;cin>>n>>k;
    List.resize(n);
    for(int i=0;i<n;i++)cin>>List[i].name>>List[i].height;
    sort(List.begin(),List.end(),cmp);
    int rowNum=n/k,lastRow=n-(rowNum)*(k-1),eachRowNum;
    vector<string> display;
    for(int i=0;i<k;i++){
        eachRowNum=i==0?lastRow:rowNum;
        display.resize(eachRowNum);
        int mid=eachRowNum/2,j=1,sign=-1;
        display[mid]=List[cntList++].name;
        for(int i=1;i<eachRowNum;i++,sign=-sign){
            display[mid+j*sign]=List[cntList++].name;
            if(sign==1)j++;
        }
        for(int k=0;k<(int)display.size();k++){
            cout<<display[k];
            k==((int)display.size()-1)?cout<<endl:cout<<" ";
        }
    }
    return 0;
}
