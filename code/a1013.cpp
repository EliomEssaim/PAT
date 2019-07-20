#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV=1010;
int G[MAXV][MAXV]={0};
bool VertexVisited[MAXV]={false};
void DFS(int index,bool *VertexVisited){
    VertexVisited[index]=true;//������
    for(int i=1;i<MAXV;i++){
        if(G[index][i]!=0&&VertexVisited[i]==false){
                //���������ﵼ���ж�ʧ��1-3 3-1 �����ж���
            DFS(i,VertexVisited);//dfsͼҪ˼��һ��Ҫ��ʲô
        //����д��G[index][i]�ˣ�û�и�����������ʲô
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
        VertexVisited[ConcernedCities]=true;//ConcernedCities[i]д����i
        int cntConnectedComponent=0;
        for(int j=1;j<=n;j++){//������n������k
            if(VertexVisited[j]==false){
                DFS(j,VertexVisited);
                cntConnectedComponent++;
            }
        }
        printf("%d\n",cntConnectedComponent-1);//����Ӧ���ټ�ȥ1
    }
    return 0;
}
//��һ��code ʧ��
//û����ᵽ��Ŀ�뿼��ͨ�����ļ���
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
//���⣿forѭ����һ���ж�ʧ�ܾͻ��˳���

