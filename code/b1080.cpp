#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include<cstdio>
using namespace std;
struct node{
    string id;
    int Gp,Gm,Gf,G;
};
bool cmp(node a,node b)
{
    return a.G==b.G?a.id<b.id:a.G>b.G;
}
int main()
{
    int p,m,n;
    scanf("%d%d%d",&p,&m,&n);
    map<string,int> FitStuListPos;
    vector<node> List,ans;
    string name;
    int score,cnt=1;
    for(int i=0;i<p;i++)
    {
        cin>>name>>score;
        if(score>=200)
        {
            List.push_back(node{name,score,-1,-1,-1});
            FitStuListPos[name]=cnt++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>name>>score;
        if(FitStuListPos[name]!=0)
            List[FitStuListPos[name]-1].Gm=score;
    }
     for(int i=0;i<n;i++)
     {
        cin>>name>>score;
        if(FitStuListPos[name]!=0)
        {
            List[FitStuListPos[name]-1].Gf=score;
            if(List[FitStuListPos[name]-1].Gm>List[FitStuListPos[name]-1].Gf)
            {
                float tmp=(float)List[FitStuListPos[name]-1].Gm*0.4+(float)List[FitStuListPos[name]-1].Gf*0.6;
                List[FitStuListPos[name]-1].G=(int)(tmp+0.5);
            }
            else
                List[FitStuListPos[name]-1].G=List[FitStuListPos[name]-1].Gf;
        }
     }
    for(int i=0;i<List.size();i++)
        if(List[i].G>=60) ans.push_back(List[i]);
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++)
        printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].Gp,ans[i].Gm,ans[i].Gf,ans[i].G);
    return 0;
}
//û��Ҫ�洢����ѧ������Ϣ���ɸѡ�ͺ���
//map��ϰ��map����ȷ����������Ƿ���ֹ�Ҳ����hash map<string,int>int�ᱻ��ʼ��Ϊ0
