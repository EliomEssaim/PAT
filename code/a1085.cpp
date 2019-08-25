#include<iostream>
using namespace std;
#define Type long long
bool sequen[1000000010]={false};
int main(){
    int n;
    Type p,minN=1000000010,tmp;
    scanf("%d%lld",n,p);
    for(int i=0;i<n;i++){
        scanf("%lld",tmp);
        if(tmp<minN) minN=tmp;
        sequen[tmp]=true;
    }
    Type maxN=minN*p;
    while(sequen[maxN]!=true&&maxN!=0) maxN--;
    Type cnt=0;
    for(int i=maxN;i>=0;i--) if(sequen[i]==true) cnt++;
    printf("%lld",cnt);
    return 0;
}
