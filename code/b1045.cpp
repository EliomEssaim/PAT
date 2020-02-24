#include<iostream>
#include<vector>
using namespace std;
vector<int> originList,maxFromLeft,minFromRight,ans;
int main(){
    int n,tmp;cin>>n;originList.resize(n);
    for(int i=0;i<n;i++){cin>>tmp;originList[i]=tmp;}
    maxFromLeft=originList;minFromRight=originList;
    for(int i=1;i<n;i++)
        if(originList[i]>maxFromLeft[i-1])maxFromLeft[i]=originList[i];
        else maxFromLeft[i]=maxFromLeft[i-1];
    for(int i=n-2;i>=0;i--)
        if(originList[i]<minFromRight[i+1])minFromRight[i]=originList[i];
        else minFromRight[i]=minFromRight[i+1];
    for(int i=0;i<n;i++)if(minFromRight[i]==maxFromLeft[i])ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int i=0;i<(int)ans.size();i++){
        if(i!=0)cout<<" ";
        cout<<minFromRight[ans[i]];
    }cout<<endl;
    return 0;
}
