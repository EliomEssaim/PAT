#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct node{
    string name;
    int virGrade,talGrade,level,total;
};
vector<node> manList;
bool cmp(node a,node b){
    if(a.level!=b.level)return a.level<b.level;
    else{
        if(a.total!=b.total)return a.total>b.total;
        else if(a.virGrade!=b.virGrade)return a.virGrade>b.virGrade;
        else return a.name<b.name;
    }
}
int main(){
    int n,l,h,virScore,talScore,level;
    scanf("%d%d%d",&n,&l,&h);
    string name;
    for(int i=0;i<n;i++){
        cin>>name>>virScore>>talScore;
        if(virScore>=l&&talScore>=l){
            if(virScore>=h&&talScore>=h)level=1;
            else if(talScore<h&&virScore>=h)level=2;
            else if(talScore<h&&virScore<h&&virScore>=talScore)level=3;
            else level=4;
            manList.push_back(node{name,virScore,talScore,level,virScore+talScore});
        }
    }
    sort(manList.begin(),manList.end(),cmp);
    printf("%d\n",manList.size());
    for(int i=0;i<(int)manList.size();i++)
        printf("%s %d %d\n",manList[i].name.c_str(),manList[i].virGrade,manList[i].talGrade);
    return 0;
}
