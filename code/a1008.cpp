#include<iostream>
using namespace std;
int main(){
    int lastFloor=0,time=0,n,curFloor;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>curFloor;
        time+=curFloor-lastFloor>0?(curFloor-lastFloor)*6:(-curFloor+lastFloor)*4;
        time+=5;
        lastFloor=curFloor;
    }
    cout<<time;
    return 0;
}
