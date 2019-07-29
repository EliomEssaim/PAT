#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV=510,INF=0x3fffffff;int n,m,s,d,optCost=INF;
int G[MAXV][MAXV],cost[MAXV][MAXV],dist[MAXV];
bool visited[MAXV]={false};
vector<int> path,tempPath,pre[MAXV];
void Dijkstra(int source){
    fill(dist,dist+MAXV,INF);
    dist[source]=0;
    for(int i=0;i<n;i++){
        int u=-1,minWeight=INF;
        for(int i=0;i<n;i++){
            if(visited[i]==false&&dist[i]<minWeight){
                u=i;minWeight=dist[i];
            }
        }
        if(u==-1) return;
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(G[u][v]!=INF&&visited[v]==false){
                if(dist[u]+G[u][v]<dist[v]){
                    dist[v]=dist[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[u]+G[u][v]==dist[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int node){
    tempPath.push_back(node);
    if(node==s){
        int TmpCost=0;
        for(int i=0;i<(int)tempPath.size()-1;i++){
            TmpCost+=cost[tempPath[i]][tempPath[i+1]];
        }
        if(TmpCost<optCost){
            optCost=TmpCost;
            path=tempPath;
        }
        tempPath.pop_back();//忘记写了！！！！
        return ;//忘记写了！！！！
    }
    for(int i=0;i<(int)pre[node].size();i++){
        DFS(pre[node][i]);
    }
    tempPath.pop_back();
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&d);
    fill(G[0],G[0]+MAXV*MAXV,INF);//为什么是G[0]
    for(int i=0;i<m;i++){
        int a,b,distan,acost;
        scanf("%d%d%d%d",&a,&b,&distan,&acost);
        G[a][b]=G[b][a]=distan;
        cost[a][b]=cost[b][a]=acost;
    }
    Dijkstra(s);
    DFS(d);
    for(int i=0;i<(int)path.size();i++){
        printf("%d ",path[path.size()-i-1]);
    }
    printf("%d %d\n",dist[d],optCost);
    return 0;
}
