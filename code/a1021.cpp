#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define dfs_flag 0
#define travel_flag 0
#define input_flag 0
using namespace std;
int maxheight=0,n;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;
#if dfs_flag
void dfs(int u,int depth){
    visit[u]=true;
    if(depth==maxheight) temp.push_back(u);
    if(depth>maxheight){
        maxheight=depth;
        temp.clear();
        temp.push_back(u);
    }
    for(int i=0;i<(int)v[u].size();i++){
        if(visit[v[u][i]]==false){
            dfs(v[u][i],depth+1);
        }
    }
}
#endif // dfs
#if !dfs_flag
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i <(int) v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
#endif
int main(){
    #if input_flag
    scanf("%d",&n);
    v.resize(n+1);
    int a,b,cnt=0,s1=0;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    #endif // input_flag
    #if !input_flag
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    #endif
    #if travel_flag
    for(int i=1;i<=n;i++){//这里该写maxv-1
        if(visit[i]==false){
            dfs(i,1);
            if(i==1){
                if(!temp.empty()) s1=temp[0];
                for(int j=0;j<(int)temp.size();j++){
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }
    if(cnt>=2){
        printf("Error: %d components",cnt);
    }else{
        temp.clear();
        maxheight =0;
        fill(visit,visit+1010,false);
        dfs(s1,1);
        for(auto itt=s.begin();itt!=s.end();itt++)
        printf("%d\n",*itt);
    }
    #endif // travel_flag
    #if !travel_flag
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j <(int) temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < (int)temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    #endif
    return 0;
}
//没有意识到自己算法是N2级别的
//想不到deepest root怎么求
//图的问题不要通过遍历所有顶点实现
