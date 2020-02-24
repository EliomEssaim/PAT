#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<unordered_set<int>> sets;
int main(){
    int n,m,num,k,aset,bset,nt,nc;
    cin>>n;
    sets.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&num);
            sets[i].insert(num);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&aset,&bset);
        nc=nt=0;
        nt =sets[aset].size();
        for(auto unit:sets[bset])
            if(sets[aset].find(unit)!=sets[aset].end())nc++;
            else nt++;
        printf("%.1f%%\n",(float)nc/nt*100.0);
    }
    return 0;
}
