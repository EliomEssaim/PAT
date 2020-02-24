#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int tmpRank,ID,Rank;
};
vector<int> orders,rankList;
vector<node> members;
int score[2000],revRank[2000],appear[2000];
bool cmp(node a,node b){
    return a.tmpRank<b.tmpRank;
}
int main(){
    int Np,Ng,revRankCnt=1,j,cntZero=0,lastOne=-1,maxScore=-1;
    cin>>Np>>Ng;
    orders.resize(Np);
    rankList.resize(Np);
    members.resize(Np);
    for(int i=0;i<Np;i++)scanf("%d",&score[i]);
    for(int i=0;i<Np;i++)scanf("%d",&orders[i]);
    for(int i=0;i<Np;i++)appear[i]=score[orders[i]];
    do{
        cntZero=0;
        for(int i=0;i<(int)orders.size();i=j){
            if(cntZero%Ng==0)
                lastOne=-1,maxScore=-1;
            for(j=i;j<i+Ng&&j<(int)orders.size();j++){
                if(revRank[j]==0){
                    cntZero++;
                    if(appear[j]>maxScore){
                        maxScore=appear[j];
                        revRank[j]=0;
                        if(lastOne!=-1)
                            revRank[lastOne]=revRankCnt;
                        lastOne=j;
                    }else revRank[j]=revRankCnt;
                }
            }
        }
        if(cntZero==1)revRank[lastOne]=revRankCnt;
        revRankCnt++;
    }while(cntZero>1);
    for(int i=0;i<Np;i++){
        members[i].ID=i;
        members[orders[i]].tmpRank=revRankCnt-revRank[i];
    }
    sort(members.begin(),members.end(),cmp);
    members[0].Rank=1;
    for(int i=1;i<(int)members.size();i++){
        if(members[i].tmpRank==members[i-1].tmpRank)members[i].Rank=members[i-1].Rank;
        else members[i].Rank=i+1;
    }
    for(int i=0;i<Np;i++)
        rankList[members[i].ID]=members[i].Rank;
    for(int i=0;i<Np;i++){
        if(i!=0)cout<<" ";
        cout<<rankList[i];
    }
    return 0;
}
