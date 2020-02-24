#include<iostream>
#include<vector>
using namespace std;
vector<int> dis,sum;
int totalLenth=0,n,m,tmp,tmp2;
int main(){
    cin>>n;
    dis.resize(n+1);
    sum.resize(n+2);
    sum[0]=sum[1]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        dis[i]=tmp;
        sum[i+1]=sum[i]+tmp;
        totalLenth+=tmp;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&tmp,&tmp2);
        if(tmp2<tmp)swap(tmp2,tmp);
        int tmpSum=sum[tmp2]-sum[tmp];
        printf("%d\n",min(tmpSum,totalLenth-tmpSum));
    }
    return 0;
}
