#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct node{
    string name;
    int age,wealth;
};
vector<node> richerList;
bool cmp(node &a,node &b){
    if(a.wealth!=b.wealth)return a.wealth>b.wealth;
    else if(a.age!=b.age)return a.age<b.age;
    else return a.name<b.name;
}
int main(){
    int n,k,m,amin,amax;
    cin>>n>>k;
    richerList.resize(n);
    for(int i=0;i<n;i++){
        cin>>richerList[i].name;
        scanf("%d%d",&richerList[i].age,&richerList[i].wealth);
    }
    sort(richerList.begin(),richerList.end(),cmp);
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&m,&amin,&amax);
        printf("Case #%d:\n",i);
        int cntOutput=0;
        for(int j=0;j<(int)richerList.size()&&cntOutput<m;j++)
            if(richerList[j].age>=amin&&richerList[j].age<=amax){
                printf("%s %d %d\n",richerList[j].name.c_str(),richerList[j].age,richerList[j].wealth);
                cntOutput++;
            }
        if(cntOutput==0)printf("None\n");
    }
    return 0;
}
