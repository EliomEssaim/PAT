#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int> digits,ans,sumCandidate;
int k,p,n,maxSum=-1;
bool firstOut=true;
void dfs(int sum,int index,int factorSum){
    if(index!=-1)sum+=sumCandidate[digits[index]];
    if(index==k-1){
        if(sum==n&&factorSum>maxSum){
            maxSum=factorSum;
            ans=digits;
        }
        return;
    }
    for(int i=sumCandidate.size()-1;i>=1;i--){
        digits[index+1]=i;
        if((index>=1&&i>digits[index])||(sumCandidate[i]>=n&&index<k-1))continue;
        if(index==-1&&sumCandidate[i]*k<n)break;
        if((sum+sumCandidate[digits[index+1]])<=n)dfs(sum,index+1,factorSum+i);
    }
}
int main(){
    cin>>n>>k>>p;
    digits.resize(k);
    for(int i=0;pow(i,p)<=n;i++)
        sumCandidate.push_back(pow(i,p)+0.1);
    dfs(0,-1,0);
    if(maxSum==-1){
        printf("Impossible");
        return 0;
    }
    printf("%d",n);
    for(int i=0;i<(int)ans.size();i++){
        printf(" %s %d^%d",firstOut?"=":"+",ans[i],p);
        firstOut=false;
    }
    return 0;
}
