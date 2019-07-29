#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXV=510,INF=0x3fffffff;
int G[MAXV][MAXV],dist[MAXV],Cmax,N,Sp,M,choosed=INF;
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
        int extraORlackBikes=0;
        for(int i=0;i<(int)tempPath.size();i++){
            extraORlackBikes+=abs(tempPath[i]-Cmax);//假定路途上的都偏full或lack
        }
        if(extraORlackBikes<choosed) {
            choosed=extraORlackBikes;
            path=tempPath;
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
    int lack;
    if(bikes[Sp]-5<0) lack=choosed;
    else lack=0;
    printf("%d ",lack);
    for(int i=(int)path.size()-1;i>=0;i--){
        printf("%d%s",path[i],i==0?" ":"->");
    }
    printf("%d\n",choosed-lack);
    return 0;
}
