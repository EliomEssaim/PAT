#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int MAXV=300,INF=0x3fffffff;string startCity;
int G[MAXV][MAXV],dist[MAXV],happiness[MAXV],shortest[MAXV],numCities,k,iCity=0;
bool visited[MAXV]={false};int maximumHappy=0,maximumAvrhappy=0;
vector<int> pre[MAXV],tmpPath,path;
map<string,int> st2int;
map<int,string> int2st;
int string2int(string name){
    int tmp=iCity;
    if(st2int.find(name)==st2int.end()){
        st2int[name]=iCity;
        int2st[iCity++]=name;
    }else{
        return st2int[name];
    }
    return tmp;
}
string int2string(int i){return int2st[i];}//保证输入合法
void Dijkstra(int st){
    fill(dist,dist+MAXV,INF);
    fill(shortest,shortest+MAXV,0);
    dist[st]=0;shortest[0]=1;
    for(int i=0;i<numCities;i++){
        int u=-1,minWeight=INF;
        for(int i=0;i<numCities;i++){
            if(visited[i]==false&&dist[i]<minWeight){
                u=i;minWeight=dist[i];
            }
        }
        if(u==-1) return ;
        visited[u]=true;
        for(int v=0;v<numCities;v++){
            if(G[u][v]!=INF&&visited[v]==false){
                if(G[u][v]+dist[u]<dist[v]){
                    dist[v]=G[u][v]+dist[u];
                    shortest[v]=shortest[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(G[u][v]+dist[u]==dist[v]){
                    pre[v].push_back(u);
                    shortest[v]+=shortest[u];
                }
            }
        }
    }
}
void DFS(int id){
    tmpPath.push_back(id);
    if(id==0){
        int cntHappiness=0,Avr=0;
        for(int i=tmpPath.size()-1;i>=0;i--){
            int id=tmpPath[i];
            cntHappiness+=happiness[id];
        }
        int sizePath=tmpPath.size()-1;
        Avr=(int)(cntHappiness*1.0/(1.0*(sizePath)));
        if(cntHappiness>maximumHappy){
            maximumHappy=cntHappiness;
            path=tmpPath;maximumAvrhappy=Avr;
        }else if(cntHappiness==maximumHappy&&Avr>maximumAvrhappy){
            maximumAvrhappy=Avr;
            path=tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    for(int i=0;i<(int)pre[id].size();i++){
        DFS(pre[id][i]);
    }
    tmpPath.pop_back();
}
int main(){
    string name,name2;int happyValue,cost;
    fill(G[0],G[0]+MAXV*MAXV,INF);
    scanf("%d%d",&numCities,&k);cin>>startCity;
    string2int(startCity);
    st2int["ROM"]=numCities-1;
    int2st[numCities-1]="ROM";
    for(int i=0;i<numCities-1;i++){
        cin>>name>>happyValue;
        int id=string2int(name);
        happiness[id]=happyValue;
    }
    for(int i=0;i<k;i++){
        cin>>name>>name2>>cost;
        int IDa=string2int(name);
        int IDb=string2int(name2);
        G[IDa][IDb]=G[IDb][IDa]=cost;
    }
    Dijkstra(0);
    DFS(numCities-1);string cityName;
    printf("%d %d %d %d\n",shortest[numCities-1],\
           dist[numCities-1],maximumHappy,maximumAvrhappy);
    for(int i=path.size()-1;i>=0;i--){
        cityName=int2string(path[i]);
        printf("%s%s",cityName.c_str(),i==0?"\n":"->");
    }
    return 0;
}
//avr 计算方法出错
//对ROM的初值赋值错误
//pre没有加【】
//IDa 和IDb没有反过来
//==写成了=

//柳神经验
//因为提供的数据比较齐全
//可以不用写string2int和int2string直接用map定义的映射就好了
//
