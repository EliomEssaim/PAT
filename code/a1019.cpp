#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,radix;
    cin>>n>>radix;
    vector<int> rev,virgin;
    for(;n!=0;n/=radix)
        rev.push_back(n%radix);
    virgin=rev;
    reverse(virgin.begin(),virgin.end());
    if(virgin==rev)printf("Yes\n");
    else printf("No\n");
    if(virgin.empty())virgin.push_back(0);
    for(int i=0;i<(int)virgin.size();i++){
        if(i!=0)cout<<" ";
        cout<<virgin[i];
    }
    return 0;
}
