#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
unordered_map<int,vector<string>> courseTable;
bool cmp(string &a,string &b){
    return a<b;
}
int main(){
    int n,m,tmpSum,course;
    string name;
    name.resize(5);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s%d",&name[0],&tmpSum);
        for(int j=0;j<tmpSum;j++){
            scanf("%d",&course);
            courseTable[course].push_back(name);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d %u\n",i,courseTable[i].size());
        sort(courseTable[i].begin(),courseTable[i].end(),cmp);
        for(auto &unit:courseTable[i])
            printf("%s\n",unit.c_str());
    }
    return 0;
}
