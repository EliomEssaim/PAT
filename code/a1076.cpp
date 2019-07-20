#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXV=1010;
vector<int> Adj[MAXV];int N,L,ansIndex=0;
vector<int> ans;
void BFS(int poster){
    bool OnceInQueue[MAXV]={false};
    queue<int> q;int level=0,levelEnd;
    q.push(poster);
    levelEnd=poster;
    OnceInQueue[poster]=true;
    while(!q.empty()){
        int frontElment=q.front();
        q.pop();
        for(int i=0;i<(int)Adj[frontElment].size()&&level<L;i++){
            if(OnceInQueue[Adj[frontElment][i]]==false){
                q.push(Adj[frontElment][i]);
                OnceInQueue[Adj[frontElment][i]]=true;
                ans[ansIndex]++;
            }
        }
        if(frontElment==levelEnd){
            level++;
            levelEnd=q.back();
        }
    }
}
int main(){
    int userListI,FollowedBy;
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;i++){
        scanf("%d",&userListI);
        for(int j=0;j<userListI;j++){
            scanf("%d",&FollowedBy);
            Adj[FollowedBy].push_back(i);
        }
    }
    int TestCasesNum;vector<int> TestCases;
    scanf("%d",&TestCasesNum);
    TestCases.resize(TestCasesNum);ans.resize(TestCasesNum);
    for(int i=0;i<TestCasesNum;i++){
        scanf("%d",&TestCases[i]);
        BFS(TestCases[i]);
        ansIndex++;
    }
    for(int i=0;i<(int)ans.size();i++)
    printf("%d\n",ans[i]);
    return 0;
}
//第一次code失败

//level处判断失误应该是<
//level 在判断代码的后面更新具有滞后性所以
//应该用 < 使得滞后值 不再执行滞后+1的操作

//level写错了
//1、level不是进入一次for就加一层（对根节点是这样的）
//但是对于非根节点 这个是有问题的 根节点会有多个子节点
//子节点又有可能有子子节点，当子节点遍历时，会导致level++
//这时已经脱离本意
//2、BFS是层序遍历 但是for不代表一层for负责把子节点加入队列中
//某种意义上for（BFS while循环中的for循环）是dfs
//或者说带for的遍历都是种DFS

//确定层序 level 的办法
//1、设置levelend到达levelend时level++(不熟练）
//2、设置node 增加layer 进入一次就把layer+1
