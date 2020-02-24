#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
unordered_map<string,set<int>> ans;
int main(){
    string name;
    name.resize(6);
    int n,k,indice,stuNum;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&indice,&stuNum);
        for(int j=0;j<stuNum;j++){
            scanf("%s",&name[0]);
            ans[name].insert(indice);
        }
    }
    for(int i=0;i<n;i++){
        scanf("%s",&name[0]);
        printf("%s ",name.c_str());
        printf("%d",ans[name].size());
        for(auto &unit:ans[name])
            printf(" %d",unit);
        printf("\n");
    }
    return 0;
}
