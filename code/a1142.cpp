#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=210;
bool G[maxn][maxn]={0},isVisit[maxn],isClique,isMax,isInTest[maxn];
vector<vector<int>> adj(maxn);
vector<int> vertexes;
int Nv,Ne,a,b;
int main(){
    cin>>Nv>>Ne;
    for(int i=0;i<Ne;i++){
        scanf("%d%d",&a,&b);
        G[a][b]=G[b][a]=true;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k,m;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&m);
        memset(isInTest,0,sizeof(bool)*maxn);
        vertexes.clear();
        vertexes.resize(m);
        isClique=true;isMax=true;
        for(int j=0;j<m;j++){
            scanf("%d",&vertexes[j]);
            isInTest[vertexes[j]]=true;
        }
        for(int j=0;j<m;j++)
            for(int k=j+1;k<m;k++)
        if(G[vertexes[j]][vertexes[k]]==false){
            isClique=false;
            break;
        }
        if(!isClique){
            printf("Not a Clique\n");
            continue;
        }else{
            for(int j=0;j<(int)adj[vertexes[0]].size();j++)
                if(isInTest[adj[vertexes[0]][j]]==false){
                    isMax=false;
                    int testVertex=adj[vertexes[0]][j];
                    for(int k=1;k<m;k++)
                        if(G[vertexes[k]][testVertex]==false){
                            isMax=true;
                            break;
                        }
                }
            if(isMax)printf("Yes\n");
            else printf("Not Maximal\n");
        }
    }
    return 0;
}
