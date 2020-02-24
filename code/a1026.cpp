#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int veryBig=1000000000;
struct node{
    int arriveTime,serveTime=veryBig,tag=0,dealTime;
};
bool cmp(node a,node b){
    return a.serveTime==b.serveTime?a.arriveTime<b.arriveTime:a.serveTime<b.serveTime;
}
vector<int> vipTableNum,tableServeCnt;
queue<int> vipNum;
vector<node> nodes;
bool isVIPTable[110]={0};
int n,hh,mm,ss,totalClock=8*60*60,k,m,noPriOne=-1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        node tmpNode;
        scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&tmpNode.dealTime,&tmpNode.tag);
        tmpNode.dealTime*=60;
        if(tmpNode.dealTime>2*60*60)tmpNode.dealTime=2*60*60;
        tmpNode.arriveTime=hh*60*60+mm*60+ss;
        if(tmpNode.arriveTime>=21*60*60)continue;
        nodes.push_back(tmpNode);
    }
    scanf("%d%d",&k,&m);
    vipTableNum.resize(m);
    for(int i=0;i<m;i++){
        scanf("%d",&vipTableNum[i]);
        isVIPTable[vipTableNum[i]]=true;
    }
    sort(nodes.begin(),nodes.end(),cmp);
    for(int i=0;i<n;i++)
        if(nodes[i].tag==1)vipNum.push(i);
    vector<int> finTime(k+1,8*60*60),tableServeCnt(k+1,0);
    for(int i=0;i<(int)nodes.size();i++){
        if(nodes[i].tag==1){
            if(nodes[i].serveTime!=veryBig)continue;
            int minVTime=veryBig,minVNum=-1;
            for(int j=0;j<m;j++)
            if(finTime[vipTableNum[j]]<minVTime){
                minVTime=finTime[vipTableNum[j]];
                minVNum=vipTableNum[j];
            }
            if((nodes[i].arriveTime>=minVTime)||noPriOne!=-1){
                nodes[i].serveTime=max(nodes[i].arriveTime,minVTime);
                finTime[minVNum]=nodes[i].serveTime+nodes[i].dealTime;
                tableServeCnt[minVNum]++;
                vipNum.pop();
                if(noPriOne!=-1){
                    i=noPriOne-1;
                    noPriOne=-1;
                }
                continue;
            }
        }
        int minTime=veryBig,minNum=-1;
        for(int j=1;j<=k;j++)
        if(finTime[j]<minTime){
            minTime=finTime[j];
            minNum=j;
        }
        if(minTime>=21*60*60)break;
        if(isVIPTable[minNum]&&nodes[i].tag==0&&!vipNum.empty()&&nodes[vipNum.front()].arriveTime<=minTime){
            noPriOne=i;
            i=vipNum.front()-1;
            continue;
        }
        if(nodes[i].tag==1) vipNum.pop();
        nodes[i].serveTime=max(minTime,nodes[i].arriveTime);
        finTime[minNum]=nodes[i].serveTime+nodes[i].dealTime;
        tableServeCnt[minNum]++;
    }
    sort(nodes.begin(),nodes.end(),cmp);
    for(int i=0;i<(int)nodes.size();i++){
        if(nodes[i].serveTime==veryBig||nodes[i].serveTime>=21*60*60) break;
        int arrT=nodes[i].arriveTime,serT=nodes[i].serveTime,waitT=(serT-arrT+30)/60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",arrT/60/60,arrT/60%60,arrT%60,serT/60/60,serT/60%60,serT%60,waitT);
    }
    for(int i=1;i<=k;i++){
        if(i!=1)cout<<" ";
        cout<<tableServeCnt[i];
    }
    return 0;
}
