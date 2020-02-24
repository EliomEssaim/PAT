#include<iostream>
#include<string.h>
using namespace std;
int say[110],isWolf[110];
bool isLiar[110];
int main(){
    int n,liarCnt;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>say[i];
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++){
        memset(isLiar,false,sizeof(bool)*(n+1));
        memset(isWolf,1,sizeof(int)*(n+1));
        liarCnt=0;
        isWolf[i]=-1;isWolf[j]=-1;
        for(int k=1;k<=n;k++)
            if(isWolf[abs(say[k])]*say[k]<0){
                isLiar[k]=true;
                liarCnt++;
            }
        if(liarCnt>2||!((isLiar[i]&&!isLiar[j])||(isLiar[j]&&!isLiar[i])))continue;
        cout<<i<<" "<<j<<endl;
        return 0;
    }
    cout<<"No Solution"<<endl;
    return 0;
}
