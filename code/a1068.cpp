#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,target,nextValue,coins[10010],dp[10010];
bool firstOut=true,carry[10010][110];
int main() {
	cin >> n >> target;
    for(int i=1;i<=n;i++)scanf("%d",&coins[i]);
    coins[0]=1000000000;
    sort(coins,coins+10010);
    reverse(coins,coins+10010);
    for(int i=1;i<=n;i++)
    for(int v=target;v>=coins[i];v--){
        if((dp[v-coins[i]]+coins[i])>=dp[v]){
            dp[v]=dp[v-coins[i]]+coins[i];
            carry[i][v]=1;
        }else carry[i][v]=false;
    }
    if(dp[target]!=target)printf("No Solution\n");
    else{
        nextValue=target;
        for(int i=n;i>=1;i--)
        if(carry[i][nextValue]==1){
            nextValue-=coins[i];
            printf("%s%d",firstOut?"":" ",coins[i]);
            firstOut=false;
            if(nextValue<=0)break;
        }
    }
	return 0;
}
