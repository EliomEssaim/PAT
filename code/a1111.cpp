#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXV=510,INF=0x3fffffff;
int G[MAXV][MAXV],dist[MAXV],n,st;
bool visited[MAXV]=false;
vector<int> path,tmpPath,pre[MAXV];
void Dijkstra(int st){
    fill(dist,dist+MAXV,INF);
    dist[st]=0;
    for(int i=0;i<n;i++){
        int u=-1,minWeight=INF;
        if(visited[i]==false&&dist[i]<minWeight){
            u=i;minWeight=dist[i];
        }
        if(u==-1) return;
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(G[u][v]!=INF&&visited[i]==false){
                if(dist[u]+G[u][v]<dist[v]){
                    dist[v]=dist[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[u]+G[u][v]==dist[v])
                    pre[v].push_back(u);
            }
        }
    }
}
void DFS(int id){
    tmpPath.push_back(id);
    if(id==st){
        tmpPath.pop_back();
        return ;
    }
    for(int i=0;i<(int)pre[id].size();i++){
        DFS(pre[id][i]);
    }
    tmpPath.pop_back();
}
int main(){
    fill(G[0],G[0]+MAXV*MAXV,INF);
    return 0;
}
