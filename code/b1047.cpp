#include<iostream>
#include<map>
using namespace std;
int tmpTeam,tmp,tmpScore,maxID,maxScore=-1;
map<int,int> team;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d-%d %d",&tmpTeam,&tmp,&tmpScore);
        team[tmpTeam]+=tmpScore;
        if(team[tmpTeam]>maxScore){
            maxScore=team[tmpTeam];
            maxID=tmpTeam;
        }
    }
    cout<<maxID<<" "<<maxScore<<endl;
    return 0;
}
