#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    float price,curDis;
};
bool cmp(node a,node b){
    return a.curDis<b.curDis;
}
float maxRange,disPerOil,carPos,carDis,cheaperOne=-1,lastPos,leftDis=0;
double maxOil,totalPrice=0.0;
bool loopEnd=false;
vector<node> oilStation;
int main(){
    float Cmax,destination,disPerOil,stationNum;
    cin>>Cmax>>destination>>disPerOil>>stationNum;
    maxRange=Cmax*disPerOil;
    oilStation.resize(stationNum);
    for(auto &unit:oilStation)
        cin>>unit.price>>unit.curDis;
    oilStation.push_back(node{0.0,destination});
    sort(oilStation.begin(),oilStation.end(),cmp);
    if(oilStation[0].curDis!=0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    for(carPos=0;carPos<(int)oilStation.size();){
        cheaperOne=-1;
        loopEnd=false;
        float minCheaper=1000000000.0;
        for(int i=carPos+1;i<(int)oilStation.size()&&oilStation[i].curDis<=oilStation[carPos].curDis+maxRange;i++){
            if(oilStation[i].price<oilStation[carPos].price){
                totalPrice+=(double)(oilStation[i].curDis-oilStation[carPos].curDis-leftDis)*oilStation[carPos].price/disPerOil;
                carPos=i;
                leftDis=0.0;
                if(oilStation[carPos].curDis==destination){
                    printf("%.2f",totalPrice);
                    return 0;
                }
                loopEnd=true;
                break;
            }
            if(oilStation[i].price<minCheaper){
                minCheaper=oilStation[i].price;
                cheaperOne=i;
            }
        }
        if(!loopEnd&&cheaperOne==-1){
            printf("The maximum travel distance = %.2f",oilStation[carPos].curDis+maxRange);
            return 0;
        }
        if(!loopEnd&&minCheaper>oilStation[carPos].price){
            totalPrice+=(double)(maxRange-leftDis)*oilStation[carPos].price/disPerOil;
            leftDis=maxRange-(oilStation[cheaperOne].curDis-oilStation[carPos].curDis);
            carPos=cheaperOne;
        }
    }
    return 0;
}
