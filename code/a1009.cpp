#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct node{
    int exp;float cof;
};
vector<node> a,b;
const int lenth=2010;
const float eps=1e-10;
float ans[lenth]={0};
int main(){
    int n,expTmp,cntValid=0;
    float cofTmp;
    cin>>n;
    a.resize(n);b.resize(n);
    for(auto &val:a)
        cin>>val.exp>>val.cof;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>expTmp>>cofTmp;
        for(int j=0;j<(int)a.size();j++){
            b[j].cof=cofTmp*a[j].cof;
            b[j].exp=expTmp+a[j].exp;
        }
        for(int j=0;j<(int)a.size();j++)ans[b[j].exp]+=b[j].cof;
    }
    for(int i=lenth-1;i>=0;i--)
        if(fabs(ans[i])>eps)cntValid++;
    cout<<cntValid;
    for(int i=lenth-1;i>=0;i--)
        if(fabs(ans[i])>eps)printf(" %d %.1f",i,ans[i]);
    return 0;
}
