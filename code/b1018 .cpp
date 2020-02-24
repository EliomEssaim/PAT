#include<iostream>
#include<string>
#include<map>
using namespace std;
int judge(string a,string b){
    int flag=1;
    if(a==b)return 0;
    if(a>b){
        string tmp;
        tmp=a;a=b;b=tmp;
        flag=-1;
    }
    a.insert(1,b);
    if(a=="BC") return flag*1;
    else if(a=="BJ") return flag*-1;
    else return flag*1;
}
int main(){
    int jiaWin=0,jiaLose=0,jiaTie=0,n;
    map<string,int> jia,yi;
    jia["B"]=0;jia["C"]=0;jia["J"]=0;
    yi["B"]=0;yi["C"]=0;yi["J"]=0;
    cin>>n;string tmpa,tmpb;
    for(int i=0;i<n;i++){
        cin>>tmpa>>tmpb;
        if(judge(tmpa,tmpb)==1){
            jiaWin++;jia[tmpa]++;
        }
        else if(judge(tmpa,tmpb)==-1){
            jiaLose++;
            yi[tmpb]++;
        }
        else jiaTie++;
    }
    printf("%d %d %d\n",jiaWin,jiaTie,jiaLose);
    printf("%d %d %d\n",jiaLose,jiaTie,jiaWin);
    auto it1=jia.begin(),it2=yi.begin();
    auto it=it1;it++;
    if(it->second>it1->second) it1=it;
    it++;
    if(it->second>it1->second) it1=it;

    it=it2;it++;
    if(it->second>it2->second) it2=it;
    it++;
    if(it->second>it2->second) it2=it;

    cout<<it1->first<<" ";
    cout<<it2->first<<endl;
    return 0;
}
