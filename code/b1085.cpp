#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
struct node{
    string sch;
    int score,cnt;
};
bool cmp(node a,node b)
{
    if(a.score!=b.score) return a.score>b.score;
    else if(a.cnt!=b.cnt) return a.cnt<b.cnt;
    else return a.sch<b.sch;
}
int main()
{
    int n;
    scanf("%d",&n);
    string id,sch;
    float score;
    unordered_map<string,int> sum_sch;
    unordered_map<string,float> sum_score;
    vector<node> ans;
    for(int i=0;i<n;i++)
    {
        cin>>id>>score>>sch;
        for(int i=0;i<sch.size();i++)
            sch[i]=tolower(sch[i]);
        sum_sch[sch]++;
        if(id[0]=='A')
            sum_score[sch]+=score;
        else if(id[0]=='B')
            sum_score[sch]+=score/1.5;
        else
            sum_score[sch]+=score*1.5;
    }
    for(auto it=sum_sch.begin();it!=sum_sch.end();it++)//node含有不同的map的赋值处理
        ans.push_back(node{it->first,(int)sum_score[it->first],it->second});
    sort(ans.begin(),ans.end(),cmp);
    int rankk=1;
    cout<<ans.size()<<endl;
    cout<<rankk<<" "<<ans[0].sch<<" "<<ans[0].score<<" "<<ans[0].cnt<<endl;
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i].score==ans[i-1].score)
            cout<<rankk<<" "<<ans[i].sch<<" "<<ans[i].score<<" "<<ans[i].cnt<<endl;
        else
        {
            cout<<i+1<<" "<<ans[i].sch<<" "<<ans[i].score<<" "<<ans[i].cnt<<endl;
            rankk=i+1;
        }
    }


    return 0;
}
//什么时候用map？
//map适合用来当hash，查找string过于麻烦时，如录入名单
//或者题目存在string与int的对应关系时
