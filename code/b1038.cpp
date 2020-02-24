#include<iostream>
#include<vector>
using namespace std;
vector<int> cntScores(200);
int main(){
    int n,num;cin>>n;
    for(int i=0;i<n;i++){cin>>num;cntScores[num]++;}
    int k;cin>>k;
    for(int i=0;i<k;i++){
        if(i!=0)cout<<" ";
        cin>>num;cout<<cntScores[num];
    }
    return 0;
}
