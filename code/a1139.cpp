#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int maxn=10000;
bool gender[maxn]={0},tmpGender;
unordered_map<int,bool> isContact;
unordered_set<int> classMate;
vector<vector<int>> adj(maxn);
vector<int> output;
string stra,strb;
int main(){
    int n,m,a,b,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>stra>>strb;
        if(stra[0]!='-')gender[abs(stoi(stra))]=1;
        a=abs(stoi(stra));
        if(strb[0]!='-')gender[abs(stoi(strb))]=1;
        b=abs(stoi(strb));
        adj[a].push_back(b);
        adj[b].push_back(a);
        classMate.insert(a);
        classMate.insert(b);
    }
    scanf("%d",&k);
    for(auto &unit:classMate)
        sort(adj[unit].begin(),adj[unit].end());
    for(int i=0;i<k;i++){
        scanf("%d%d",&a,&b);
        isContact.clear();
        output.clear();
        tmpGender=b<0?false:true;
        b=abs(b);
        for(int i=0;i<(int)adj[b].size();i++)
            if(!(gender[adj[b][i]] ^ tmpGender)&&adj[b][i]!=abs(a))
                isContact[adj[b][i]]=true;
        tmpGender=a<0?false:true;
        a=abs(a);
        for(int i=0;i<(int)adj[a].size();i++){
            if(!(gender[adj[a][i]] ^ tmpGender)&&adj[a][i]!=b){
                int oneFriend=adj[a][i];
                for(int j=0;j<(int)adj[oneFriend].size();j++)
                    if(isContact[adj[oneFriend][j]]){
                        output.push_back(oneFriend);
                        output.push_back(adj[oneFriend][j]);
                    }
            }
        }
        printf("%d\n",output.size()/2);
        for(int i=1;i<(int)output.size();i+=2)
            printf("%04d %04d\n",output[i-1],output[i]);
    }
    return 0;
}
