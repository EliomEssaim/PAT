#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> dp,seq,favorColor;
unordered_map<int,int> book;
int ans=-1,n,m,tmp;
int main(){
    cin>>n>>n;
    favorColor.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&favorColor[i]);
        book[favorColor[i]]=i;
    }
    cin>>m;
    seq.push_back(0);
    for(int i=1;i<=m;i++){
        scanf("%d",&tmp);
        if(book.count(tmp)!=0)
            seq.push_back(book[tmp]);
    }
    dp.resize(seq.size()+1);
    for(int i=1;i<=(int)seq.size();i++){
        dp[i]=1;
        for(int j=1;j<i;j++)
            if(seq[i]>=seq[j])
               dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
