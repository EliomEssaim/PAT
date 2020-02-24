#include<iostream>
#include<vector>
using namespace std;
vector<int> chain,higherList,sum;
int n,m,minHigher,tmpSum=0,low=0;
bool needHigher=true;
int main(){
    cin>>n>>m;
    minHigher=1000000000;
    chain.resize(n+1);
    sum.resize(n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&chain[i]);
        sum[i]+=sum[i-1]+chain[i];
       while(sum[i]-sum[low]>m){
            if(sum[i]-sum[low]<minHigher){
                minHigher=sum[i]-sum[low];
                higherList.clear();
                higherList.push_back(low+1);
                higherList.push_back(i);
            }else if(sum[i]-sum[low]==minHigher){
                higherList.push_back(low+1);
                higherList.push_back(i);
            }
            low++;
       }
       if(sum[i]-sum[low]==m){
            needHigher=false;
            printf("%d-%d\n",low+1,i);
       }
    }
    if(needHigher){
        for(int i=1;i<(int)higherList.size();i+=2)
            printf("%d-%d\n",higherList[i-1],higherList[i]);
    }
    return 0;
}
