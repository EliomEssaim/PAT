#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXV=510,INF=0x3fffffff;
int G[MAXV][MAXV],dist[MAXV],Cmax,N,Sp,M,minSend=INF,minBack=INF;
bool visit[MAXV]={false};
vector<int> pre[MAXV],tempPath,path,bikes;
void Dijkstra(int s){
    fill(dist,dist+MAXV,INF);
    dist[s]=0;
    for(int i=0;i<N;i++){
        int u=-1,minWeight=INF;
        for(int j=0;j<=N;j++){
            if(visit[j]==false&&dist[j]<minWeight){
                minWeight=dist[j];
                u=j;
            }
        }
        if(u==-1) return ;
        visit[u]=true;
        for(int v=0;v<=N;v++){
            if(G[u][v]!=INF&&visit[v]==false){
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
void DFS(int vertex){
    tempPath.push_back(vertex);
    if(vertex==0){//不考虑perfect状态
        int need = 0, back = 0,imperfect;
        for(int i = tempPath.size() - 2; i >= 0; i--) {
            int id = tempPath[i];
            imperfect=bikes[id]-Cmax;
            if(imperfect > 0) {
                back += imperfect;
            } else {
                if(back > (0 - imperfect)) {
                    back += imperfect;
                } else {
                    need += ((0 - imperfect) - back);
                    back = 0;
                }
            }
        }
        if(need < minSend) {
            minSend = need;
            minBack = back;
            path = tempPath;
        } else if(need == minSend && back < minBack) {
            minBack = back;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i=0;i<(int)pre[vertex].size();i++)
        DFS(pre[vertex][i]);
    tempPath.pop_back();
}
int main(){
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
    Cmax=Cmax/2;bikes.resize(N+1);
    fill(G[0],G[0]+MAXV*MAXV,INF);
    bikes[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&bikes[i]);
    }
    for(int i=0;i<M;i++){
        int a,b,distantce;
        scanf("%d%d%d",&a,&b,&distantce);
        G[a][b]=G[b][a]=distantce;
    }
    Dijkstra(0);
    DFS(Sp);
    printf("%d ",minSend);
    for(int i=(int)path.size()-1;i>=0;i--){
        printf("%d%s",path[i],i==0?" ":"->");
    }
    printf("%d\n",minBack);
    return 0;
}
//题意理解错误：
//要先送车子到问题城市，回来的图中调整，而不是
