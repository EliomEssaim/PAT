#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> say,isLiar,isWolf;
int main(){
    int n,cntLiar;
    cin>>n;
    isLiar.resize(n+1);isWolf.resize(n+1);say.resize(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&say[i]);
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        fill(isWolf.begin(),isWolf.end(),1);
        isWolf[i]=-1;isWolf[j]=-1;
        cntLiar=0;
        for(int k=1;k<=n;k++){
            if(isWolf[abs(say[k])]*say[k]<0){
                cntLiar++;
                isLiar[k]=1;
            }else isLiar[k]=-1;
        }
        if(cntLiar==2&&(isLiar[i]+isLiar[j])==0){
            printf("%d %d",i,j);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
