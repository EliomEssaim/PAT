#include<iostream>
using namespace std;
int championId,tailId,minDistance=30000,tmpDistance,maxDistance=0;
int main(){
    int n,x,y,tmpId;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmpId>>x>>y;
        tmpDistance=x*x+y*y;
        if(tmpDistance>maxDistance){
            maxDistance=tmpDistance;
            tailId=tmpId;
        }
        if(tmpDistance<minDistance){
            championId=tmpId;
            minDistance=tmpDistance;
        }
    }
    printf("%04d %04d",championId,tailId);
    return 0;
}
