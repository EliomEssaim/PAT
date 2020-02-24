#include<iostream>
using namespace std;
int pixiv[18000000]={0},ans=-1;
int main(){
    int n,m,color,target;
    cin>>n>>m;
    target=n*m/2;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&color);
            if(ans!=-1)continue;
            pixiv[color]++;
            if(pixiv[color]>target)
                ans=color;
        }
    cout<<ans;
    return 0;
}
