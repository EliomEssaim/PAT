#include<iostream>
#include<vector>
using namespace std;
vector<int> fullScore,answer;
int main(){
    int n,m,tmpAns,getScore=0;
    cin>>n>>m;
    fullScore.resize(m);answer.resize(m);
    for(int i=0;i<m;i++)cin>>fullScore[i];
    for(int i=0;i<m;i++)cin>>answer[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tmpAns;
            if(answer[j]==tmpAns)
            getScore+=fullScore[j];
        }
        cout<<getScore<<endl;
        getScore=0;
    }

    return 0;
}
