#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int veryBig=1000000000,maxn=2000;
double bestAvr=1000000000.0,tmpAvr;
int bestGas=-1,n,m,k,Ds,weigh,a,b,tmpSum=0,tmpFar,bestFar=0;
struct node{
    int vertex,weigh;
};
bool failGas=false;
string aPos,bPos;
vector<int> dist(maxn);
vector<vector<node>> adj(maxn);
void dijkstra(int source){
    fill(dist.begin(),dist.end(),veryBig);
    vector<bool> isVisit(maxn,0);
    dist[source]=0;
    for(int i=1;i<=n+m;i++){
        int minDist=veryBig,minV=-1;
        for(int i=1;i<=n+m;i++)
        if(dist[i]<minDist&&isVisit[i]==false){
            minDist=dist[i];
            minV=i;
        }
        if(minV==-1)return;
        isVisit[minV]=true;
        for(int i=0;i<(int)adj[minV].size();i++){
            int adjV=adj[minV][i].vertex;
            if(!isVisit[adjV]&&dist[adjV]>dist[minV]+adj[minV][i].weigh){
                dist[adjV]=dist[minV]+adj[minV][i].weigh;
            }
        }
    }
}
int main(){
    cin>>n>>m>>k>>Ds;
    for(int i=0;i<k;i++){
        cin>>aPos>>bPos>>weigh;
        a=aPos[0]!='G'?stoi(aPos):stoi(aPos.substr(1))+n;
        b=bPos[0]!='G'?stoi(bPos):stoi(bPos.substr(1))+n;
        adj[a].push_back(node{b,weigh});
        adj[b].push_back(node{a,weigh});
    }
    for(int i=1;i<=m;i++){
        dijkstra(n+i);
        tmpSum=0;tmpFar=veryBig;
        failGas=false;
        for(int i=1;i<=n&&!failGas;i++){
            tmpSum+=dist[i];
            if(tmpFar>dist[i])tmpFar=dist[i];
            if(dist[i]>Ds)failGas=true;
        }
        if(failGas)continue;
        tmpAvr=(float)tmpSum/n;
        if(tmpFar>bestFar||(tmpFar==bestFar&&tmpAvr<bestAvr)){
            bestGas=n+i;
            bestFar=tmpFar;
            bestAvr=tmpAvr;
        }
    }
    if (bestGas != -1) {
		printf("G%d\n", bestGas - n);
		printf("%.1f %.1f",(float)bestFar, bestAvr);
	}
	else printf("No Solution");
    return 0;
}
