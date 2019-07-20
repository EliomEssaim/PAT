#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV=1010;
int G[MAXV][MAXV]={0};
bool VertexVisited[MAXV]={false};
void DFS(int index,bool *VertexVisited){
    VertexVisited[index]=true;//不熟练
    for(int i=1;i<MAXV;i++){
        if(G[index][i]!=0&&VertexVisited[i]==false){
                //放在了这里导致判断失误1-3 3-1 都被判断了
            DFS(i,VertexVisited);//dfs图要思考一会要干什么
        //这里写成G[index][i]了，没有搞清楚传入的是什么
        }
    }
}
int main(){
    int n,m,k,cityA,cityB;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d",&cityA,&cityB);
        G[cityA][cityB]=G[cityB][cityA]=1;
    }
    int ConcernedCities;
    for(int i=0;i<k;i++){
        scanf("%d",&ConcernedCities);
        fill(VertexVisited,VertexVisited+MAXV,false);
        VertexVisited[ConcernedCities]=true;//ConcernedCities[i]写成了i
        int cntConnectedComponent=0;
        for(int j=1;j<=n;j++){//这里是n而不是k
            if(VertexVisited[j]==false){
                DFS(j,VertexVisited);
                cntConnectedComponent++;
            }
        }
        printf("%d\n",cntConnectedComponent-1);//这里应该再减去1
    }
    return 0;
}
//第一次code 失败
//没有体会到题目想考连通分量的计数
int G[maxv][maxv];
bool visited[maxv];
void DFS(int u){
    visited[u]=true;
    for(int v=0;v<maxv;v++){
        if(G[u][v]!=inf&&visited[v]==false){
            DFS(v);
        }
    }
}
//问题？for循环第一次判断失败就会退出吗

