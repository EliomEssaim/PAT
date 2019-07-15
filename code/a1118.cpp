#include<iostream>
#include<vector>
#include<set>
#define MAXN 10010
using namespace std;
struct node{
    int fid;
    bool isExist=false;
};
node father[MAXN];
int findFather(int x){
    father[x].isExist=true;
    int fa=x;
    while(fa!=father[fa].fid) fa=father[fa].fid;
    int upfa=x;
    while(upfa!=father[upfa].fid){
        upfa=father[fa].fid;
        father[x].fid=fa;
        x=fa;
    }
    return fa;
}
void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa>fb) father[fa].fid=fb;
    if(fa<fb) father[fb].fid=fa;
}
int main(){
    int n,k,q,pairsA,pairsB;
    for(int i=0;i<MAXN;i++)
        father[i].fid=i;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        vector<int> birds;

        birds.resize(k);
        for(int j=0;j<k;j++)
            scanf("%d",&birds[j]);
        for(int cnt=1;cnt<(int)birds.size();cnt++)
            Union(birds[cnt-1],birds[cnt]);
    }
    int maxnum=0;set<int> st;
    scanf("%d",&q);
    for(int i=0;i<MAXN;i++){
        if(father[i].isExist==true){
            st.insert(findFather(i));
            maxnum++;
        }
    }
    printf("%d %d\n",st.size(),maxnum);
    for(int i=0;i<q;i++){
        scanf("%d%d",&pairsA,&pairsB);
        printf("%s\n",findFather(pairsA)==findFather(pairsB)?"Yes":"No");
    }
    return 0;
}
//如何实现根的计数？ 用数组标记再用for遍历
//或者直接用set
