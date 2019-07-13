#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int dad,area=0,estate=0,minChild=10000,familyNums=0;
    double averArea,averEstate;
};
vector<node> father(10010);
vector<int> root(10010);
bool cmp(int a,int b){
    return a>b;
}
int findFather(int x){
    int fa=x;
    while(fa!=father[fa].dad) fa=father[fa].dad;
    int upfa=x;
    while(upfa!=fa){
        upfa=father[upfa].dad;
        father[x].dad=fa;
        x=upfa;
    }
    if(father[fa].minChild>x)
        father[fa].minChild=x;
    return fa;
}
void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb) father[fb].dad=fa;
}
int main(){
    int n,id,fat,mot,k,child,estate,area;
    scanf("%d",&n);
    for(int i=0;i<(int)father.size();i++)
        father[i].dad=i;
    for(int i=0;i<n;i++){
        bool isSole=true;
        scanf("%d%d%d%d",&id,&fat,&mot,&k);
        if(fat!=-1){
            int fa_fat=findFather(fat);
            if(fa_fat!=fat) isSole=false;
            Union(id,findFather(fat));
            father[id].familyNums++;
        }
        if(mot!=-1){
            int mot_fa=findFather(mot);
            if(mot_fa!=mot) isSole=false;
            Union(id,findFather(mot));
            father[id].familyNums++;
        }
        while(k--){
            scanf("%d",&child);
            int child_fa=findFather(child);
            if(child_fa!=child) isSole=false;
            Union(id,findFather(child));
            father[id].familyNums++;
        }
        scanf("%d%d",&estate,&area);
        father[id].estate=estate;
        father[id].area=area;
        father[id].familyNums++;
        int fa_id=findFather(id);
        if(fa_id!=id) isSole=false;
        if(!isSole){
            father[findFather(id)].area+=area;
            father[findFather(id)].estate+=estate;
            father[findFather(id)].familyNums+=father[id].familyNums;
        }
    }
    int cnt=0;
    for(int i=0;i<10010;i++){
        if(father[i].familyNums!=0){
            root[findFather(i)]++;
        }
    }
    vector<int> rootID;
    for(int i=0;i<10010;i++)
    if(root[i]!=0){
        cnt++;
        rootID.push_back(i);
        father[i].averArea=(double)father[i].area/(double)father[i].familyNums;
        father[i].averEstate=(double)father[i].estate/(double)father[i].familyNums;
    }
    sort(root.begin(),root.end(),cmp);
    for(int i=0;i<(int)root.size();i++){
        printf("%04d %d %.3lf %.3lf",\
      father[root[i]].minChild,\
      father[root[id]].familyNums,\
      father[root[id]].averArea,\
      father[root[id]].averEstate);
    }
}
