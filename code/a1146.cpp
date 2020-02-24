#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> degree,tmpDegree,ans;
bool wrong=false;
vector<vector<int>> adj(maxn);
int main(){
    int n,m,a,b,k,tmp;
    cin>>n>>m;
    degree.resize(n+1);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        degree[b]++;
        adj[a].push_back(b);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        wrong=false;
        tmpDegree=degree;
        for(int j=0;j<n;j++){
            scanf("%d",&tmp);
            if(wrong)continue;
            if(tmpDegree[tmp]!=0)wrong=true;
            else {
                for(int k=0;k<(int)adj[tmp].size();k++)
                    tmpDegree[adj[tmp][k]]--;
            }
        }
        if(wrong)ans.push_back(i);
    }
    for(int i=0;i<(int)ans.size();i++){
        if(i!=0)printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}
