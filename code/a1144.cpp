#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool> isExist;
int main(){
    int n,tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp>0)isExist[tmp]=true;
    }
    for(int i=1;1;i++)
    if(!isExist[i]){
        printf("%d",i);
        break;
    }
    return 0;
}
