#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,bool> cannotList;
vector<int> inCompatible[100010];
bool complict=false;
int a,b,n,m,k;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        inCompatible[a].push_back(b);
        inCompatible[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&k);
        cannotList.clear();
        complict=false;
        for(int j=0;j<k;j++){
            scanf("%d",&a);
            if(cannotList[a]==true)complict=true;
            else if(!inCompatible[a].empty()){
                for(int i=0;i<(int)inCompatible[a].size();i++)
                    cannotList[inCompatible[a][i]]=true;
            }
        }
        printf("%s\n",complict?"No":"Yes");
    }
    return 0;
}
