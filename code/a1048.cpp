#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> coins;
int n,m,other;
int isExitst[600];
int main(){
    scanf("%d%d",&n,&m);
    coins.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
        isExitst[coins[i]]++;
    }
    sort(coins.begin(),coins.end());
    for(int i=0;i<n;i++){
        other=m-coins[i];
        if(other<0)break;
        if((other!=coins[i]&&isExitst[other])||(other==coins[i]&&isExitst[other]>=2)){
            printf("%d %d",coins[i],other);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
