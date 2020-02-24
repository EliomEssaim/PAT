#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int arrive,startTime=-1,process;
};
int hh,mm,ss,pro,timeTmp,busyWindowCnt=0,totalClock=8*60*60,waitTime=0,serveCnt=0;
vector<node> customList,windows;
bool cmp(node a,node b){
    return a.arrive<b.arrive;
}
int main(){
    int n,k;
    cin>>n>>k;
    windows.resize(k);
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&pro);
        timeTmp=hh*60*60+mm*60+ss;
        if(timeTmp>17*60*60)continue;
        node tmpNode;
        tmpNode.arrive=timeTmp;
        tmpNode.process=pro>60?60*60:pro*60;
        customList.push_back(tmpNode);
    }
    sort(customList.begin(),customList.end(),cmp);
    for(;serveCnt<(int)customList.size();totalClock++){//windows[i].startTime==-1
        for(int i=0;i<(int)   .size();i++)
            if(serveCnt<(int)customList.size()&&customList[serveCnt].arrive<=totalClock) {
                if((windows[i].startTime!=-1&&(windows[i].startTime+windows[i].process)<=totalClock)||(windows[i].startTime==-1)){
                    windows[i]=customList[serveCnt++];
                    windows[i].startTime=totalClock;
                    waitTime+=totalClock-windows[i].arrive;
                }
            }
    }
    printf("%.1f",(float)waitTime/serveCnt/60.0);
    return 0;
}
