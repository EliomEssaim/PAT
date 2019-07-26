#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x3fffffff
using namespace std;
vector<vector<int>> G;
vector<int> dist,TeamsInCity,TeamsCnt,paths;
vector<bool> visited;int n;
void Dijkstra(int source){
    fill(dist.begin(),dist.end(),INF);
    fill(TeamsCnt.begin(),TeamsCnt.end(),0);
    dist[source]=0;paths[source]=1;
    TeamsCnt[source]=TeamsInCity[source];
    for(int i=0;i<n;i++){
        int u=-1,minWeight=INF;
        for(int v=0;v<n;v++){
            if(visited[v]==false&&dist[v]<minWeight){
                minWeight=dist[v];u=v;//segementfault
            }
        }
        if(u==-1) return;
        visited[u]=true;//差点忘了
        for(int v=0;v<n;v++){
            if(visited[v]==false&&G[u][v]!=INF){
                    //未被访问没写 访问未在集合内的邻结点
                if(dist[u]+G[u][v]<dist[v]){
                dist[v]=dist[u]+G[u][v];
                TeamsCnt[v]=TeamsCnt[u]+TeamsInCity[v];
                //这里写错了
                paths[v]=paths[u];
                //停顿时间长 这里是优化了TeamsCnt 为下一次的判断做准备
                //回去研究一下性质
                }else if(dist[u]+G[u][v]==dist[v]){
                    //写错了 这里应该也要保证是未访问过的
                    paths[v]+=paths[u];//这里不能用path 可能求只是局部最短
                    if(TeamsInCity[v]+TeamsCnt[u]>TeamsCnt[v])
                        TeamsCnt[v]=TeamsInCity[v]+TeamsCnt[u];
                }
            }
        }
    }
}
int main(){
    int m,c1,c2;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    dist.resize(n);TeamsCnt.resize(n);
    paths.resize(n);TeamsInCity.resize(n);
    visited.resize(n);fill(visited.begin(),visited.end(),false);
    G.resize(n);for(int i=0;i<n;i++) G[i].resize(n);
    for(int i=0;i<n;i++){for(int j=0;j<n;j++) G[i][j]=INF;}
    for(int i=0;i<n;i++) scanf("%d",&TeamsInCity[i]);
    for(int i=0;i<m;i++){
        int a,b,weight;
        scanf("%d%d%d",&a,&b,&weight);
        G[a][b]=G[b][a]=weight;
    }
    Dijkstra(c1);
    printf("%d %d\n",paths[c2],TeamsCnt[c2]);
    return 0;
}
//这里是+= 因为paths的含义是 到这个点有几条
//最短路径可以走，下一个节点如果走法唯一将加上这个值
//因为这个值也是到这个点最短路径的走法。
//遇到了多个相等的情况 就会把多个相等的路径相加求这个路径的全部走法的目的
//我的思考是要做个乘法 但是那样的话需要一大堆不同的情况讨论
//因为对加在访问里面的dist的数组性质的不熟悉 导致思考的方向单一
