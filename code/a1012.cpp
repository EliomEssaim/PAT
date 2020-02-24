#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int id,bestRank,posRank;
    int subRank[4],score[4];
};
int isExist[1000010]={0},index=0;
int subSwitch,inqureID;
bool cmp(node a,node b){
    return a.score[subSwitch]>b.score[subSwitch];
}
vector<node> stuList;
char str[5]="ACME";
int main(){
    int n,m;
    cin>>n>>m;
    stuList.resize(n);
    for(auto &val:stuList){
        scanf("%d%d%d%d",&val.id,&val.score[1],&val.score[2],&val.score[3]);
        val.score[0]=((double)(val.score[1]+val.score[2]+val.score[3])/3.0+0.5);
    }
    for(int i=0;i<4;i++){
        subSwitch=i;
        sort(stuList.begin(),stuList.end(),cmp);
        stuList[0].subRank[i]=1;
        for(int j=1;j<n;j++)
            stuList[j].subRank[i]=stuList[j].score[i]==stuList[j-1].score[i]?stuList[j-1].subRank[i]:j+1;
    }
    for(int i=0;i<(int)stuList.size();i++){
        isExist[stuList[i].id]=i+1;
        stuList[i].bestRank=stuList[i].subRank[0];
        stuList[i].posRank=0;
        for(int j=1;j<4;j++)
            if(stuList[i].bestRank>stuList[i].subRank[j]){
                 stuList[i].bestRank=stuList[i].subRank[j];
                 stuList[i].posRank=j;
            }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&inqureID);
        if((index=isExist[inqureID])!=0)printf("%d %c\n",stuList[index-1].bestRank,str[stuList[index-1].posRank]);
        else printf("N/A\n");
    }
    return 0;
}
