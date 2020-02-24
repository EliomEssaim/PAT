#include<iostream>
#include<vector>
using namespace std;
vector<long long> aSeq,bSeq,ans;
int main(){
    int n,m,pos,aIndex=0,bIndex=0;
    scanf("%d",&n);aSeq.resize(n);
    for(auto &unit:aSeq)scanf("%lld",&unit);
    scanf("%d",&m);bSeq.resize(m);
    for(auto &unit:bSeq)scanf("%lld",&unit);
    pos=(m+n)/2;
    if((m+n)%2==0)pos--;
    ans.resize(m+n);
    for(int i=0;i<m+n;i++){
        if(aIndex<n&&bIndex<m)
            ans[i]=aSeq[aIndex]<bSeq[bIndex]?aSeq[aIndex++]:bSeq[bIndex++];
        else ans[i]=aIndex==n?bSeq[bIndex++]:aSeq[aIndex++];
        if(i==pos)break;
    }
    printf("%lld",ans[pos]);
    return 0;
}
