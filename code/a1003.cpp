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
        visited[u]=true;//�������
        for(int v=0;v<n;v++){
            if(visited[v]==false&&G[u][v]!=INF){
                    //δ������ûд ����δ�ڼ����ڵ��ڽ��
                if(dist[u]+G[u][v]<dist[v]){
                dist[v]=dist[u]+G[u][v];
                TeamsCnt[v]=TeamsCnt[u]+TeamsInCity[v];
                //����д����
                paths[v]=paths[u];
                //ͣ��ʱ�䳤 �������Ż���TeamsCnt Ϊ��һ�ε��ж���׼��
                //��ȥ�о�һ������
                }else if(dist[u]+G[u][v]==dist[v]){
                    //д���� ����Ӧ��ҲҪ��֤��δ���ʹ���
                    paths[v]+=paths[u];//���ﲻ����path ������ֻ�Ǿֲ����
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
//������+= ��Ϊpaths�ĺ����� ��������м���
//���·�������ߣ���һ���ڵ�����߷�Ψһ���������ֵ
//��Ϊ���ֵҲ�ǵ���������·�����߷���
//�����˶����ȵ���� �ͻ�Ѷ����ȵ�·����������·����ȫ���߷���Ŀ��
//�ҵ�˼����Ҫ�����˷� ���������Ļ���Ҫһ��Ѳ�ͬ���������
//��Ϊ�Լ��ڷ��������dist���������ʵĲ���Ϥ ����˼���ķ���һ
