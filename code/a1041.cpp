#include<iostream>
#include<vector>
using namespace std;
int cntOccur[100100]={0};
vector<int> numList;
int main(){
    int n;
    cin>>n;
    numList.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&numList[i]);
        cntOccur[numList[i]]++;
    }
    for(int i=0;i<n;i++)
    if(cntOccur[numList[i]]==1){
        cout<<numList[i];
        return 0;
    }
    cout<<"None"<<endl;
    return 0;
}
