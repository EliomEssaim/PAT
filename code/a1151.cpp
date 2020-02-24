#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int n,a,b,u,v,m;
vector<int> preOrder,inOrder,father,mediaSeq;
unordered_map<int,int> add2value,value2add,fatherList;
void buildTree(int start,int End,int rootInPre,int lastRoot){
    if(start>End)return;
    father[preOrder[rootInPre]]=preOrder[lastRoot];
    int rootInIn=start;//写错好多次
    for(;rootInIn<End&&preOrder[rootInPre]!=inOrder[rootInIn];rootInIn++);//写错好多次 范围从start 到 end
    int leftSize=rootInIn-start;
    buildTree(start,rootInIn-1,rootInPre+1,rootInPre);
    buildTree(rootInIn+1,End,rootInPre+leftSize+1,rootInPre);
}
bool ancestor=false;
int main(){
    cin>>m>>n;
    preOrder.resize(n);
    inOrder.resize(n);
    father.resize(n);
    mediaSeq.resize(n);
    for(int i=0;i<n;i++)father[i]=i;
    for(int i=0;i<n;i++) scanf("%d",&mediaSeq[i]);
    inOrder=mediaSeq;
    sort(mediaSeq.begin(),mediaSeq.end());
    for(int i=0;i<n;i++){
        value2add[mediaSeq[i]]=i;
        add2value[i]=mediaSeq[i];
    }
    for(int i=0;i<n;i++)inOrder[i]=value2add[inOrder[i]];
    for(int i=0;i<n;i++){
        scanf("%d",&preOrder[i]);
        preOrder[i]=value2add[preOrder[i]];
    }
    buildTree(0,n-1,0,0);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(value2add.count(a)==0||value2add.count(b)==0){
            if(value2add.count(a)==0&&value2add.count(b)==0)printf("ERROR: %d and %d are not found.\n",a,b);
            else if(value2add.count(a)==0)printf("ERROR: %d is not found.\n",a);
            else printf("ERROR: %d is not found.\n",b);
            continue;
        }
        u=value2add[a];
        v=value2add[b];
        int tmpU=u,tmpV=v;
        fatherList.clear();
        ancestor=false;
        while(father[tmpU]!=tmpU){
            tmpU=father[tmpU];
            fatherList[tmpU]=1;
            if(tmpU==v){
                printf("%d is an ancestor of %d.\n",add2value[v],add2value[u]);
                ancestor=true;
                break;
            }
        }
        if(ancestor)continue;
        while(father[tmpV]!=tmpV){
            tmpV=father[tmpV];
            if(tmpV==u){
                printf("%d is an ancestor of %d.\n",add2value[u],add2value[v]);
                break;
            }
            if(fatherList[tmpV]==1){
                printf("LCA of %d and %d is %d.\n",add2value[u],add2value[v],add2value[tmpV]);
                break;
            }
        }
    }
    return 0;
}
