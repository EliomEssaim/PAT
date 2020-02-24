#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
struct node{
    string Id;int score;
};
bool cmp(node &a,node &b){
    return a.score!=b.score?a.score>b.score:a.Id<b.Id;
}
int totalScore[1010]={0},totalStu[1010]={0};
unordered_map<string,unordered_map<string,int>> dateLog;
unordered_map<string,vector<node>> dateOutput,stuList;
int main(){
    int n,m,orderTmp,classNum,scoreTmp;
    string str;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>str>>scoreTmp;
        stuList[str.substr(0,1)].push_back(node{str,scoreTmp});
        classNum=stoi(str.substr(1,3));
        totalScore[classNum]+=scoreTmp;
        totalStu[classNum]++;
        dateLog[str.substr(4,6)][str.substr(1,3)]++;
    }
    for(auto &it:dateLog){
        for(auto &it2:it.second)
            dateOutput[it.first].push_back(node{it2.first,it2.second});
        sort(dateOutput[it.first].begin(),dateOutput[it.first].end(),cmp);
    }
    for(auto &it:stuList) sort(it.second.begin(),it.second.end(),cmp);
    for(int i=1;i<=m;i++){
        cin>>orderTmp>>str;
        printf("Case %d: %d %s\n",i,orderTmp,str.c_str());
        if((orderTmp==1&&stuList.count(str.substr(0,1))==0)||(orderTmp==2&&totalStu[stoi(str)]==0)||(orderTmp==3&&dateLog.count(str)==0)){
             printf("NA\n");
             continue;
        }
        if(orderTmp==1)
            for(auto &it:stuList[str.substr(0,1)])
                printf("%s %d\n",it.Id.c_str(),it.score);
        else if(orderTmp==2) printf("%d %d\n",totalStu[stoi(str)],totalScore[stoi(str)]);
        else if(orderTmp==3)
             for(auto &i:dateOutput[str])
                printf("%s %d\n",i.Id.c_str(),i.score);
    }
    return 0;
}
