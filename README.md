[TOC]





# 英语词汇

## 单词

- consecutive **连续**
- utility**实用**
- Deduplication**去重**
- degree**度**，代表树中所有节点的子节点数目最大的那个数
- depth/height**深度/高度**；对树而言都是一个东西
- parentheses**括号**
- corresponding**相应的**
- emitter**发射器**（emission排放）
- seniority**资历**
- stat**统计**
- pedigree **血统**
- exception**异常**
- Clusters**集群**
- estate**房产**
- ascending **上升**
- indices**指数**
- queries**咨询**
- iterates**迭代**
- Connected Component**连通分量**
- acyclic **无环**

### 树/图类专业名词

- 树   Tree
- 二叉树   Binary   tree
- 满二叉树   Full   binary   tree
- 完全二叉树   Complete   binary   tree
- 二叉排序树   Binary   sort   tree
- 二叉搜索树   Binary   search   tree
- 前序遍历   Preorder   traversal
- 中序遍历   Inorder   traversal
- 后序遍历   Postorder   traversal
- 哈夫曼树   Huffman   tree
- 线索二叉树 threaded binary tree
- 回溯   Backtrackins
- 图   Graph
- 有向图   Directed   graph   (digraph)
- 无向图   Undirected   graph   (undigraph)
- 有向完全图   Undirected   Complete   Graph
- 无向完全图   directed   complete   graph
- 非连通图 unconnected graph
- 强连通图 strongly connected graph 
- 弱连通图 weakly connected graph
- 稀疏图   Sparse   graph
- 稠密图   Dense   graph
- 网点   Network
- 邻结点   Adjacent
- 度   Degree
- 出度   Outdegree
- 入度   Indegree
- 连通图   Connected   graph
- **连通分支**   **Connected   component**
- 强连通图   Strong   graph
- **生成树   Spanning   tree**
- 邻接矩阵   **Adjacency**  matrix
- 邻接表   Adjacency   lists
- 邻接多重表   Adjacency   multilists
- 深度优先索引   Depth-First   Search
- 广度优先索引   Breath-First   Search
- 最小生成树   Minimum   spanning   tree
- 最短路径   Shortest   path
- 有向无环图   Directed   **acyclic** graph
- 拓扑排序   Topological   sort

### 其他专有名词

- 顺序存储结构   **Sequential**   storage   structure
- 直接前驱   Immediate   **predecessor**
- 直接后继   Immediate   successor
- 循环链表   Circylar   linked   lists
- 双向链表   Double   linked   lists
- 双向循环链表   Double   circular   linked   list

- 特殊矩阵   Special   matrices
- 稀疏矩阵   **Sparse   matrices**
- 分块检索   Blocking   search
- 直接定址   Immediately   allocate
- 平方取中法   Mid-square   method
- 开放定址法   Open   addressing
- 直接选择排序   Straight   selection   sort
- 基数排序   Radix   sorting
- 最低位优先(LSD)   Least   Significant   Digit   First
- 最高位优先(MSD)   Most   Significant   Digit   First

## 句子

The quick brown fox jumps over the lazy dog.

**significant digits**有效数字

**not compatible** 不兼容

**5-digit**五位

warning: suggest parentheses around assignment used as truth value **==**写成了**=**

**distinct** positive integer 不同的正整数

accurate up to 1 decimal **place**精确到小数点后1位

Then the next line contains *N* numbers, each number *S**i* is the index of the supplier for the *i*-th member. *S**r**o**o**t* for the root supplier is defined to be −1.

# 数据结构

## 最优化题目

- 1090. Highest Price in Supply Chain (25)-PAT甲级真题（DFS） 父亲表示法怎么转变为孩子表示；

## 链表

- A1032

- A1052

- A1047（如何反转静态链表？如何反转普通的链表？）

- ~~~C++
  //数据定义
  struct node{
      typename data;
      node* next;
  }
  //静态链表的定义
  struct node{
      int data;
      int next;
  }Node[10010];
  //插入元素
  void insert(node* head,int pos,int x){
      int workPointer=head->next;
  	while(workPointer!=NULL&&pos!=0){
          workPointer=workPointer->next;
          pos--;
  	}
          
      if(workPointer!=NULL){
          node* p=new node;
          p.next=workPointer.next;
          p.data=x;
          workPointer.next=p;
      }
  }
  if(delans.size()){//不写这个会出现段错误
          for(int i=0;(unsigned)i<delans.size()-1;i++)
              printf("%05d %d %05d\n",delans[i].addr,delans[i].key,delans[i+1].addr);
        printf("%05d %d -1\n",delans[delans.size()-1].addr,delans[delans.size()-1].key);
      }
  ~~~


## 堆栈与队列

## 树

### 二叉树

~~~C++
//树的结构体定义
struct node{
    int data;
    node* lchild;
    node* rchild;
}
//节点的创建
node* newNode(int v){
    node* tmp=new node;
    tmp->data=v;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    return tmp;
}
//节点的查找以及修改
void searchAndModifyNode(node* root,int x,int newData){
    if(root==NULL)
        return;
    if(root->data==x){
        root->data=newData;
    }else{
        searchAndModifyNode(root->lchild,x,newData);
        searchAndModifyNode(root->rchild,x,newData);
    }
    return ;
}
//插入节点（视情况而定，这里不完整）
void insertNode(node* &root,int data){
    if(root==NULL){
        root=newNode(data);
        return;
    }
    return ;
}
//四种遍历
void preorder(node* root){
    if(root==NULL)
        return ;
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(node* root){
    if(root==NULL)
        return ;
    preorder(root->lchild);
    printf("%d",root->data);
    preorder(root->rchild);
}
void postorder(node* root){
    if(root==NULL)
        return ;
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d",root->data);
}
void layerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp=q.front();
        q.pop();
        printf("%d",tmp->data);
        if(tmp->lchild!=NULL)
            q.push(tmp->lchild);
        if(tmp->rchild!=NULL)
            q.push(tmp->rchild);
    }
    return ;
}
//先序+中序创建唯一树
TreeNode* buildTree(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    TreeNode* t = new TreeNode();
    t->left = buildTree(root + 1, start, i - 1);
    t->right = buildTree(root + 1 + i - start, i + 1, end);
    t->data = pre[root];
    return t;
}
/*说明一下经常模糊的地方*/
//1、数组的两个下标相减+1为两个下标之间的长度
//2、pos~pos+lenth实际有lenth+1长所以实际要写入时要减一 string左闭右开就成立了 
/*后序+中序转先序*/
#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {//root是后序的root，start是中序的start
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]);
    pre(root - 1 - end + i, start, i - 1);
    pre(root - 1, i + 1, end);
}
//求二叉树的高度
int PostOrderGetHeight(BinTree){
    int HL,HR,MaxH;
    if(BT){
        HL=PostOrderGetHeight(BT->Left);
        HR=PostOrderGetHeight(BT->Right);
        MaxH=(HL>HR)?HL:HR;
        return (MaxH+1);
    }else return 0;
}
~~~

#### 二叉查找树

- 二叉搜索树的前序遍历就是二叉搜索树的插入顺序

~~~C++
//查找 很简单和二叉树的差不多
void search(node* root,int x){
    if(root==NULL) {printf("failed to locate!\n");return ;}
    if(root->key==x)
        printf("It's here!\n");
    if(x<root->key)
        search(root->left,x);
    if(root->key<x)
        search(root->right,x);
}
//插入结点在搜索的基础上改造了一下
void insert(node* &root,int x){/*这里是传引用！！！*/
    if(root==NULL) {root=newnode(x);return ;}
    if(root->key==x)
        return;
    if(x<root->key)
        search(root->left,x);
    if(root->key<x)
        search(root->right,x);
}
//建立也很简单就是insert
//略

~~~

#### AVL树

~~~C++
struct node{
    int val;
    node *left,*right;
}
//获取树高
int getHeight(node* root){
    if(root==NULL) return 0;
    return max(getHeight(root->left),getHeight(root->right))+1;
}
//左旋（可以画个图 理解一下）注意是右子树的右子树超了
void L(node* &root){//有点不熟练 记得传引用
    node* tmp=root->right;
    root->right=tmp->left;
    tmp->left=root;
    root=tmp;
}
//右旋 这是左子树的左子树超了
void R(node* &root){
    node* tmp=root->left;
    root->left=tmp->right;
    tmp->right=root;
    root=tmp;
}
int GetBalance(node* root){
    return getHeight(root->left)-getHeight(root->right);
}
void insert(node* &root,int val){
    if(root==NULL){
        root=new node;
        root->val=val;
        root->left=NULL;
        root->right=NULL;
        return;
    }
    if(root->val<val){
        insert(root->right,val);//传引用就不用写返回值,这里是插到了右子树
        if(GetBalance(root)==-2){//插入到右子树只能是会是负值2
            if(GetBalance(root->right)==-1) L(root);
            else{R(root->right);L(root);}
        }
    }else if(root->val>val){
        insert(root->left,val);
        if(GetBalance(root)==2){
            if(GetBalance(root->left)==1) R(root);
            else{L(root->left);R(root);}
        }
    }
}
//建树

~~~

#### 堆

```C++
//优先队列会自动是实现下面看看就好
const int maxn=100;
int heap[maxn],n=10;
void downAdjust(int low,int high){
    int faPos=low,childID=2*low;
    while(childID<=high){
        if(childID+1<=high&&heap[childID+1]>heap[childID])
            childID++;
        if(heap[childID]>heap[faPos])
            swap(heap[childID],heap[faPos]);
        faPos=childID;
        childID=faPos*2;
    }
}
void createHeap(){
    for(int i=n/2;i>=1;i--)
        downAdjust(i,n);
}
void deleteHeapTop(){
    heap[1]=Heap[n--];
    downAdjust(1,n);
}
void upAdjust(int low,int high){
    int childID=high;faPos=High/2;
    while(faPos>=1){
        if(heap[faPos]<heap[childID])
            swap(hep[faPos],heap[childID]);
        childID=faPos;
        faPos=childID/2;
        else break;//后面已经有序 没有必要进行了
    }
}
void HeapSort(){
    createHeap();
    for(int i=n;i>1;i--){
        swap(heap[1],heap[i]);
        downAdjust(1,i-1);
    }
}
```

#### 哈夫曼树

```C++
//着重掌握思想
//不用考虑用什么数据结构来存放多个树 只要从优先队列里面拿出两个再塞回去就好了
while(q.size()>1){//保证有两个
    int x=q.top();
    q.pop();
    int y=q.top();
    q.pop();
    q.push(x+y);
    ans+=x+y;
}
/*哈夫曼编码*/
//
```



### 普通树

​	分析树类的题目，写递归算法时，要注意代码和**当前层**的关系，尤其到了递归终点时要判断自己要的数据是否准备好，还是**差一个当前层键值**没有录入。

~~~C++
struct node{
    int weight;
    vector<int> childAddr;
};
void bfs(int root){//层序遍历
    queue<int> q;
    int layerEnd=root;
    int layer=0;
    q.push(root);
    while(!q.empty()){
        int frontAddr=q.front();
        q.pop();
        if(tree[frontAddr].childAddr.empty()) layerLeaves[layer]++;
        for(int i=0;i<(int)tree[frontAddr].childAddr.size();i++){
            q.push(tree[frontAddr].childAddr[i]);
        }
        if(frontAddr==layerEnd){
            if(layerEnd!=root)printf(" %d",layerLeaves[layer]);
            else printf("%d",layerLeaves[layer]);
            if(!q.empty()) layerEnd=q.back();//这个q.empty()使用队列或堆栈的值前必须判空
            layer++;
        }
    }
}
void dfs(int index, int depth) {//对层用的dfs a1004 把depth去掉就是个dfs模板
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
/*维护一个公共量 可以记录树的路径 这个公共量可以设为全局变量 遍历时传下标即可*/
/*==改成>=有if else要判断四个情况是否都是自己想要的*/
void dfs(int index, int nodeNum, int sum){//a1053的值得二刷暴露很多问题
    if(sum<target&&tree[index].childAddr.empty()) return;//严谨
    if(sum>target) return;
    if(sum==target){
        if(tree[index].childAddr.empty()){
            path[nodeNum]=tree[index].weight; 
            for(int i=0;i<=nodeNum;i++)
                printf("%d%c",path[i],i==nodeNum?'\n':' ');
        }
        else return;
    }
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        path[nodeNum]=tree[index].weight;
	 dfs(tree[index].childAddr[i],nodeNum+1,sum+tree[tree[index].childAddr[i]].weight);
    }
} 
~~~

### 并查集

- 对待father数组要把他当成无路径压缩的树 不容易出错

~~~C++
//初始化
for(int i=0;i<n;i++){
    father[i]=i;
}
//查找
int findFather(int key){
    int fa=key;
    while(fa!=father[fa]) fa=father[fa];
    int upfa=key;
    while(upfa!=fa){//这个while不熟练
        upfa=father[fa];
        father[key]=fa;
        key=upfa;
    }
    return fa;
}
//合并
void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb) father[fa]=b;//这里是fa而不是a要最终结果
}//要固定某种值作为根节点 可以利用合并时的代码来实现 如比较大小 小者为根 还可以实现交集就并集的效果
~~~



## 图

### 图的存储以及遍历

~~~C++
/*1、存储方式*/
//邻接矩阵，占用内存。
//就是二维数组
//邻接表
//用vector实现
struct node{
    int vertex;
    int weight;
};
vector<node> Adj[N];
const int MAXV=1000;//邻接矩阵不要超过这个值64MB 这个值超过8000就GG
const int INF=1000000000;
/**********************************图的遍历**********************************/
//邻接矩阵
//一般不超过1000
int n,G[MAXV][MAXV];
bool vis[MAXV]={false};
void DFS(int u,int depth){//这是顶点的DFS
    vis[u]=true;
    for(int v=0;v<n;v++){
        if(vis[v]==false&&G[u][v]!=INF){
            DFS(v,depth+1);
        }
    }
}
void DFSTravel(){
    for(int u=0;u<n;u++){//访问所有的连通分量
        if(vis[u]==false){
            DFS(u,1);
        }
    }
}
//邻接表
//访问Adj[0]实际上是访问边而不是访问节点；
//visit表示节点被访问过而不是边
//邻接表不适用于需要访问节点的所有指向自己的边和指向其他节点的边，如需要统计直接相连的所有边的权值
//而邻接表的优点是节省空间，只存储实际存在的边。其缺点是关注顶点的度时，就可能需要遍历一个链表。还有一个缺点是，对于无向图，如果需要删除一条边，就需要在两个链表上查找并删除。
vector<int> Adj[MAXV];
int n;//n为顶点数
bool vis[MAXV]={false};
void DFS(int u,int depth){
    vis[u]=true;
    for(int v=0;v<Adj[u].size();v++){
        if(vis[v]==false)
            DFS(v,depth+1)
    }
}
void DFSTravel(){
    for(int u=0;u<n；u++){
        if(vis[u]==false){
            DFS(u,1);
        }
    }
}

/*BFS*/
int n,G[MAXV][MAXV];
bool inq[MAXV]={false};//代表曾经在队列的和dfs不一样要注意
void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(inq[v]==false&&G[u][v]!=INF){
                q.push(v);
                inq[v]=true;
            }
        }
    }
}
void BFSTravel(){
    for(int u=0;u<n;u++){
        if(inq[u]==false){
            BFS[u];
        }
    }
}
//邻接表版
vector<int> Adj[MAXV];
int n;
bool inq[MAXV]={false};
void BFS(int u){
    queue<int> q;
    q,push(u);
    inq[u]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v=Adj[u][i];
            if(inq[v]==false){
                q.push(v);
                inq[v]=true;
            }
        }        
    }
}
void BFSTravel(){
    for(int u=0;u<n;u++){
        if(inq[u]==false){
            BFS(u);
        }
    }
}

struct node{
    int v;
    int layer;
};
vector<node> Adj[N];
void BFS(int s){
    queue<node> q;
    Node start;
    start.v=s;
    start.layer=0;
    q.push(start);
    inq[start.v]=true;
    while(!q.empty()){
        Node topNode=q.front();
        q.pop();
        int u=topNode.v;
        for(int i=0;i<Adj[u].size();i++){
            Node next=Adj[u][i];
            next.layer=topNode.layer+1;
            if(inq[next.v]==false){
                q.push(next);
                inq[next.v]=true;
            }
        }
    }
}
//拓展BFS 不用node的layer用王道书的levelEnd做也可以
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
        if(frontElment==levelEnd){//重点代码：什么时候更新以及怎么更新
            level++;
            if(!q.empty())levelEnd=q.back();//又忘记加上了
        }
    }
}
~~~

### Dijkstra算法

~~~C++
//伪代码
Dijkstra(G,dist[],s){
    初始化;
    for(循环n次){
        u=dist[]中未被加入集合s中的最小的顶点;
        标记u被访问过;
        for(;u的邻结点v;){
            if(v不在集合中&&v优化过后的值比当前的更小){
                dist[v]=优化后的值;
            }
        }
    }
}
const int MAXV=1000;
const int INF=0x3fffffff;
int path[MAXV];
//邻接矩阵
int n,G[MAXV][MAXV];
int dist[MAXV];
bool isVisited[MAXV]={false};
void Dijkstra(int s){
    fill(dist,dist+MAXV,INF);
    for(int i=0;i<n;i++) path[i]=i;
    dist[s]=0;
    int i=0
    for(;i<n;i++){
        int minWeight=INF;
        int u=-1;
        for(v=1;v<=n;v++){//在所有顶点中遍历
            if(isVisited[v]==false&&dist[v]<minWeight)
                //如果这个顶点未被访问且 距离小于当前最小的顶点
                minWeight=G[u][v];
             	u=v;
        }
        if(u==-1) return;//找不到说明不连通 dist只有集合内和集合的邻结点被初始化过
        isVisited[u]=true;
        for(int v=1;v<=n;v++){
            if(isVisited[v]==false&&G[u][v]!=0&&(G[u][v]+dist[u]<dist[v])){
                //如果该边存在,未被访问过(减少了判断 被访问过说明在集合内 在集合内说明dist已经被优化成最短的了),而且 距离更小
                dist[v]=G[u][v]+dist[u];//用这条边去优化路径
                path[v]=u;
            }
        }
    }
    if(i<n-1){
        printf("不连通你\n");
    }
}
//邻接矩阵
const int MAXV=10010,INF=0x3fffffff;
vector<vector<int>> Adj[MAXV];//可以用resize
vector<int> dist[MAXV];
bool isVisited[MAXV]={false};
void Dijkstra(int s){
    fill(dist,dist+MAXV,INF);
    dist[s]=0;
    isVisited[s]=true;
    int i=0;
    for(;i<n;i++){
        int u=-1,minWeight=INF;
        for(int v=1;v<=n;v++){//可以n 不要用MAXV
            if(isVisited[v]==false&&dist[v]<minWeight){
                minWeight=dist[v];
                u=v;
            }
        }
        if(u=-1) return;
        isVisited[u]=true;
        for(int j=0;j<Adj[u].size();j++){//注意Adj要resize成n+1 不行 resize成n+1也不行
            //会造成访问越界 因为这个点的邻结点不是连续的存放在Adj的后面
            int v=Adj[u][j].vertex;
            if(isVisited[v]==false&&(dist[u]+Adj[u][j].weight<dist[v]))
                dist[v]=dist[u]+Adj[u][j].weight;//这个不能用i因为上面重复了
           		path[v]=u;
        }
    }
}
//顺序输出源点到目标节点的路径
void DFS(int vertex,int source){
    if(vertex==source) {
        printf("%d\n",source);
        return ;
    }
    DFS(path[vertex],source);
    printf("%d\n",vertex);
}
//题型
//要求除了最短外还有条第二标尺（优先级没有最短高） 来求出最优路径
//此时一般有多条最短路径
//不要求输出路径且仅仅要求输出最后的结果（比如最短路径长最小花费值）
//只要新加一条数组处理边权相等时的情况 以及在更新dist时顺便把改数据也更新了
//1、新增了一种边权要求改边权最小
if(isVisited[v]==false&&(dist[u]+Adj[u][j].weight<dist[v])){
    dist[v]=dist[u]+Adj[u][j].weight;//这个不能用i因为上面重复了
	path[v]=u;
    cost[v]=cost[u]+Adj[u][j].cost;
}else if(dist[u]+Adj[u][j].weight=dist[v]&&(cost[u]+Adj[u][j].cost<cost[v])){
    cost[v]=cost[u]+Adj[u][j].cost;
}
//2、新增了权
if(isVisited[v]==false&&(dist[u]+Adj[u][j].weight<dist[v])){
    dist[v]=dist[u]+Adj[u][j].weight;//这个不能用i因为上面重复了
	path[v]=u;
    w[v]=w[u]+weight[v];
}else if(dist[u]+Adj[u][j].weight=dist[v]&&(w[u]+weight[v]<w[v])){
    w[v]=w[u]+weight[v];
}
//3、求条数
//感觉有点毛病 能求出有两条 这个num记录的是有多少个条路径是相等的 但是如果说有n条相等的路径 其最短路径绝对不止n条
if(isVisited[v]==false&&(dist[u]+Adj[u][j].weight<dist[v])){
    dist[v]=dist[u]+Adj[u][j].weight;//这个不能用i因为上面重复了
	path[v]=u;
    num[v]=num[u];
}else if(dist[u]+Adj[u][j].weight=dist[v]){
    num[v]+=num[u];
}
~~~





------



# 常用模板

## 1.进制转换

```C++
//P进制转换为十进制
int P2dec(int x,int p)
{
    int product=1,sum=0;
    while(x>0)
    {
        sum+=(x%10)*product;
        x/=10;
        product*=p; 
    }
    return sum;
}
//十进制转换为p进制
int dec2P(int x,int p)
{
    int z[40];
    //等于0 另外处理
    for(i=0;x/p!=0;i++)
    {
        z[i]=x%p;
        x/=p;
    }
    //逆序输出 可用堆栈实现
}
```

## 2.素数表的编程实现

```c++
vector<int> prime(500000, 1);  
for(int i = 2; i * i < 500000; i++)
        for(int j = 2; j * i < 500000; j++)
            prime[j * i] = 0;
```



## 3.最大公约数和最小公倍数

```c++
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
/* a*b可能会有溢出问题！*/
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
```





------

------

# STL知识补充

## vector(可变长数组)

- sort可用
- 可以用**== >=  <=**进行比较（字典序）

~~~c++
vector<int> couple(100000,-1);//这样可以初始化vector为-1
vector<int> GoodsList(amount);//这个才是vector预分配空间
vector<int> guest[guestNum];//错误声明方法这样生成的数组是vector<int>类型的不能直接赋值
vector<int> guest(guestNum);//正确声明长度为guestNum 首地址为guest 数组
v.push_back(node{s, score, -1, -1, 0});//如果vector是结构体可以这么写 但是必须是同一类型
//vector可以用来做hash！
/*二维可边长数组*/
vector<node> map[100];
//声明一个二维可边长数组，第二维是100个，第一维度的长度可以任意指定。注意map[0].vertex这个写法是不对的
//因为 map[0] 代表一个类型为node可变长数组，本身没有vertex这个属性。map[0][0].vertex;
/*********分割线*****************/
//vector的访问方式有哪两种？
#include<vector>
vector<int> vi;
vi.pushback();
vi.popback();
vi.size();
vi.resize();//重新分配空间
vi.clear();
vi.insert(?,?);
vi.erase(?,?)//单个元素写法 区间的写法	
~~~

## set(集合)

~~~c++
set<int>::iterator sit=Singles.begin();
printf("%d",*sit);//set的访问方式
multiset<int> st;//只排序不去重
/*********分割线*****************/
//set的访问方式？
#include<set>
set<int>  st;
st.insert(?);
st.find();//返回值是什么？
st.erase(?,?);//单个元素的两种方法 删除区间的一种方法
st.size();
st.clear();

~~~

## string

- sort可用
- string要先resize()不然不能用？

~~~c++
#include<string>//string忽略空格//string可以用下标访问吗？
using namespace std;
string str1,str2[n];//n为变量 这种写法是允许的
str1+=str2;
str2-=str1;//没有这种写法
str=str+'5'+'2'+'f';//在末尾追加52f 不能用+=
scanf("%s", &a[0]);//这样可以使用scanf了 不要用这个!!!用cout不然会和其他的容器出问题
//或者先分配空间！！！！！
ans[i].name.c_str()//c_str()这样就可以用printf了
/*********分割线*****************/
string str="asdfdfwq",str2;
zeroPos=3;
str2=str.substr(0,zeroPos);
cout<<str2<<endl;//输出？                                                          asd
/*********分割线*****************/
//如何删除一个元素与一排元素？
//如何插入多个元素？
//string的访问方式有哪两种？
//默写：
string str;
str.insert(?,?);
str.erase(?,?);//删除一个元素的两个写法 删除区间的两种写法
str.substr(?,?);
string::npos
str.find(?);
str.replace(?,?,?)//两种写法
/*********分割线*****************/    
getline(cin, str);//获得一行数据 使用之前要用 getchar();把\n吃掉！！！
~~~

## map(映射)

~~~c++
map<string, int> mp;
~~~

- **int会被初始化为0！！**
- map的会以键**从小到大**排序
- unodered_map只映射**不排序**（#include <unordered_map>）**C++11**
- **vector**可以用来做hash！快很多
- count(elem) 返回指定元素出现的次数
- lower_bound() 返回键值>=给定元素的第一个位置
- upper_bound() 返回键值>给定元素的第一个位置

~~~C++
//map访问方式有哪两种？

/*********分割线*****************/  
#include<map>
using namespace std;
map<char,int> mp;
map<char,int>::iterator it=mp.begin();
it.first=?;
it.second=?;
mp.find(?);
//mp.find(str)!=mp.end() 可以帮助我们判断str有没有出现过
mp.erase(?);//删除单个元素的两种方法？删除区间元素的一个方法
mp.size();
mp.clear();
/*********分割线*****************/
map<int,vector<int> > unCompatible;
unCompatible[gsA].push_back(gsB);//unCompatible[gsA]代表vector已经是vector类了！
~~~

- //逆序输出map
  for(map<int,int>::**reverse_iterator** it=**mp.rbegin()**;it!=**mp.rend()**;it++)
          cout<<it->first<<" "<<it->second<<endl;

## queue（队列）

~~~C++
#include<queue>
using namespace std;
queue<int> q;
q.push(i);
q.pop();//取出但不返回值
q.front();
q.back();//返回值但不取出
q.empty();//使用pop和front之前必先使用empty判断是否为空
q.size();
//用BFS算法时如果需要的是修改元素而不是访问元素，最好存储编号（如数组的下标）。
~~~

### priority_queue(优先队列)

~~~C++
#include<queue>
using namespace std;
priority_queue<int> q;//没有front back
q.size();
q.top();//返回值但不取出
q.push();
q.pop();//取出但不返回值
q.empty();//无论是优先队列还是
priority_queue<int,vector<int>,less<int> >q;//less<int> 从顶向下变小如果是greater<int> 从顶向下变大 默认是大堆顶
/************结构体的优先队列**************/
struct fruit{
        string name;
        int price;
        friend bool operator < (fruit f1,fruit f2){
            return f1.price<f2.price;
        };
    }f1,f2,f3;
//.....
priority_queue<fruit> fq;
f1.name="桃子";
f1.price=3;
f2.name="梨子";
f2.price=4;
f3.name="苹果";
f3.price=1;
fq.push(f1);
fq.push(f2);
fq.push(f3);
fq.top();//输出梨子 4；因为默认为less所以top是最大的，而struct里面定义价格小的比较小所以价格最大即优先级最大的
~~~

### deque(双端队列)

~~~C++
#include <deque>
a.push_front(0);//在头部加入数据0
a.push_back(11);//在尾部加入数据11
a.pop_front();//在头部删除数据
a.pop_back();//在尾部删除数据
a.resize(num);//重新指定队列的长度
a.size() //返回容器中实际数据个数
a.max_size() //返回容器中最大数据的数量
~~~



## stack(堆栈)

~~~C++
#include<stack>
using namespace std;
stack<int> st;
st.push();
st.pop();
st.top();
st.empty();
st.size();
~~~

## pair(对)

~~~C++
/*
相当于结构体
struct pair{
typename first;
typename second;
}
*/
#include<utility>//添加map会自动添加utility
using namespace std;
pair<string,int> p;
pair<string,int> p1("haha",5);//初始化方法一
p=make_pair("haha",5);//初始化方法二
cout<< p.first << " " << p.second <<endl;//访问方式
/* pair可以比较大小，但是先比较first才比较second*/
//pair可以让map用insert函数而不是单单只能用迭代器和下标来访问
mp.insert(make_pair("hahaa",5));
mp.insert(pair<string,int>("haha",10));//类型名直接加小括号
~~~

## #include Algorithm

~~~C++
max(x,y);min(x,y);abs(x);//操作对象都是整数abs如果想用浮点数要用math.h下的fabs()
swap(x,y);
reverse(it,it2);//左闭右开的将区间的迭代器进行反转，数组可用vector可用string可用
next_permutation(a,a+3);//给出按字典序的下一个全排列如 123 132 213 231....最后会输出false
//a是数组整型指针
fill(a,a+5,3);//对指针范围内（左闭右开），进行赋值
lower_bound(first,last,val);
upper_bound(fitst,last,val);//在有序！！数组或者容器中查找第一个值大/小于等于val的元素的指针/迭代器
//如果想要获得下标可以用指针减去，头指针就是下标了

~~~

~~~C++
*max_element(v.begin(), v.end());
*min_element(arr, arr + 4);//对vector或数组使用，可以写cmp函数 返回迭代器/指针 所以要加上*

1. 第三个参数cmp可写可不写， max_element() 和 min_element() 默认是从小到大排列，然后 max_element() 输出最后一个值， min_element() 输出第一个值，但是如果自定义的 cmp 函数写的是从大到小排列，那么会导致 max_element() 和 min_element() 的两个结果是对调的

~~~



### sort函数

```c++
void sort(数组首地址,数组尾地址+1,cmp函数)//不能用>= <=
bool cmp(结构体a,结构体b){return a>b;}//按照从大到小排序，不写cmp就是从小到大
//sort数组地址（或者说迭代器加上*）是什么类型 cmp的输入参数就是什么类型
//比较的话是数字元素之间进行比较
int root[10010];
sort(root.begin(),root.end(),cmp)//cmp return的应该是a>b就好了而不是root[a]>root[b]
    //cmp传入的是整个数组的值 而不是下标！！！！！！
```

- sort函数实现排名（PAT A1025）
- **vector**、**string**也可以用此排序

## #include cctype

~~~C++
isdigit();//判断一个字符（char）的是否是数字
~~~

## #include numeric 

- 头文件不写也没关系？
  主要是用来累加容器里面的值，比如int、string之类，可以少写一个for循环
  比如直接统计 vector<int> v 里面所有元素的和：（第三个参数的0表示sum的初始值为0）
- 比如直接将 vector<string> v 里面所有元素一个个累加到string str中：（第三个元素表示str的初始值为空字符串）

~~~C++
int sum = accumulate(v.begin(), v.end(), 0);

string str = accumulate(v.begin(), v.end()," ");//以这个字符串开始
~~~

## #include cstdio

~~~C++
string str;
cin>>str;
sscanf(str.c_str(), "%d:%d:%d", &a, &b, &c);//将str转换为数字
cout<<a<<' '<<b<<' '<<c<<endl;
~~~

- sprintf与printf函数的区别：二者功能相似，但是sprintf函数打印到字符串中，而printf函数打印输出到屏幕上。**sprintf函数在我们完成其他数据类型转换成字符串类型的操作中应用广泛。**
- sprintf不能用string类，有需求还是用**to_string();**(include string)

## #include iomanip

~~~C++
setprecision(n);//保留n位有效数字 会四舍五入 运行后对余下所有的cout进行输出控制
double s=20.7843000;
cout<<setprecision(6)<<s<<endl; //输出20.7843。
//小数部分末尾为0时，是输不出来的！如
cout<<setprecision(8)<<s<<endl; //输出20.7843。
~~~

## #include cmath

~~~C++
log(b);//计算以十位底的对数 要计算其他底的可用换底公式 如：
log(8)/log(2));
exp(1);//计算自然常数e的n次方 此处为1次方
~~~



# 编程语言知识补充

## 语法

### new

~~~C++
typename* p=new typename;
int* p=new int;//申请一个int型变量的空间
int* p=new int[1000]//申请1000个int型变量的空间
~~~

- 在函数中使用new或者malloc，返回时这块空间**不会被释放,**而是保留在堆中，直到有delete或者free;

### node* 还是node *？

使用node **a*；作为声明类型语句更好，因为node*不是一个类型名

### \可以用于续行

- 只有0可以用 ={0};赋值

### for循环补充

~~~C++
#include<iostream>
using namespace std;
int main(){
    int a=0;
    for(int i=0;i<3&&i;i++) a++;
    cout<<a<<endl;//a是0！！第一次判断出错就会直接退出
}
~~~



## 函数类

### memset函数

```c++
//按字节赋值只能是0或者-1不会出错
memset(数组名,值,sizeof(数组格式));
//如果想赋值其他值使用fill
fill(first,last,val);
//first为容器的首迭代器，last为容器的末迭代器，val为将要替换的值。
```

### find函数

~~~c++
#include<algorithm>
待查值的地址=find(数组的起始地址,数组的终止地址+1,待查找的值);
~~~

### stoi函数

~~~c++
#include<math.h>//用到了pow
float stoi(string str)//将字符串转换为数字
{
    int ret=0,p=1;
    int zeroPos=str.find('.');

    if(zeroPos==string::npos)
    {
        for(int i=str.size()-1;i>=0;i--,p*=10)
            ret+=(str[i]-'0')*p;
        return (float)ret;
    }
    else
    {
        int leftNum=0,rightNum=0;
        string left,right;
        left=str.substr(0,zeroPos);
        right=str.substr(zeroPos+1,str.size()-zeroPos-1);

        for(int i=left.size()-1;i>=0;i--,p*=10)
            leftNum+=(left[i]-'0')*p;
        for(int i=right.size()-1,p=1;i>=0;i--,p*=10)
            rightNum+=(right[i]-'0')*p;
        return (float)leftNum+(float)rightNum/pow(10,right.size());
    }
}
//sscanf函数也可以做到
~~~

### 

### tolower和toupper函数

~~~c++
#include <cctype>
//大小写转换 针对单个字符而言！
 for(int i=0;i<str.size();i++)
        str[i]=tolower(str[i]);
~~~

------



## 非函数类

### 各种类型的最大值

**unsigned int** 32 位4294967296 **十位**  int*int 中int最好不超过**50000**！int+int中int不要超过**1,000,000,000**一个亿

**long** 和**int** 在64位机下的长度是一样的

**long long**是64位的 18446744073709551616无符号十进制下是 **20位**

**float**比特数为32，有效数字为6-7，数值范围为 -3.4E+38 和 3.4E+38

最大值可以通过cfloat 文件中取到**DBL_MAX**。

用**0x3fffffffH**来表示**inf**

### II的优先级小于&&

### 输出格式控制

```c++
//按4位输出不够补0
printf("%04d",a);
//保留小数点后两位
printf(".2f",a);
//在while循环下实现 保证第一个不打出*后面的都打出了*号
if(state) printf("*");
printf("%d", i);
state = true;

//简洁写法
printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
```

### 四舍五入

- 浮点数保留小数点后的数据，有时会自动四舍五入，有时不会自动四舍五入。题目没说就别写float的四舍五入

  **如果把一个浮点数赋给一个整数变量后，一定不会四舍五入。**

```c++
//对float
#include<math.h>
round(double x);
//形成整数小数部分四舍五入舍去
(int)(a*10+0.5)/10
//保留小数点后2位
(a*100+0.5)/100
```

### 结构体的构造函数编程

```c++
struct StudentList{
    long long num;
    char name[10];
    StudentList(int _num,char *_name){
        num=_num;
        name=_name;
    }
}
```

### 用c++求x的y次方的方法：

~~~c++
//方法一
#include <math.h>
pow(x, y);
//方法二：
#include <math.hpp	>
Power(x, y);
~~~

### 浮点数比较大小

- eps最好取1e-8

### 以某数字a(如2)为起点 以b(如3)为周期实现循环输出1、 2....b

~~~c++
(i-2+2*3)%3
(i-a+b*a)%b//适用于b比a大的情况！
 if (uid>=s && (uid-s)%n==0)
~~~

- const和&(传引用)可以加快程序运行速度

- 用后置++最后的值会变成这个数组的size，使用时注意判断用的是size-1，还是size（a1086）

# 经典算法的实现

## 素数——埃氏筛法

```c++
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}
```

## BFS

~~~C++
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        取出首元素top;
        访问队首元素top;
        将队首元素出队;
        将top的下一层节点中未曾入队的节点全部入队，并设置为已入队;
    }
}
~~~



# 常见错误

## 语法错误

- 闰年的规律是四年一闰百年不闰四百年再闰 闰年二月份有29天 平年是28天

  ```c++
   return ((year%4==0)&&(year%100!=0))||(year%400==0)
  ```

- ~~~C++
  scanf("%lld")//这么写codeblocks会报警但是没有问题
  ~~~

- a/b取得是商！a%b取得是余数 常常因为要取前面的数（商）写成 a%b

-  ~~~c++
   A.insert(i,'0');//这么写是错误的，必须用双引号
  A[0]!="0"//这么写不行 比较的时候必须用单引号
  ~~~

- int IsExist[100010]=**{0}**;忘记初始化

- vector<int>  a**[b]**;不能使用中括号！！要使用小括号来预分配空间

- "Yes"No"**大小写**不注意！这种情况下也会报错**答案错误**而不是格式错误。也会有**答案正确**，因为可能你Yes写对了 答案有全是Yes的

- 结构体要写在main外面

- 由于是**英文题**对输出格式控制不敏感，如没注意要输出5位（a1032）

- 由于是**英文题目**忽略的对**排序的要求**

- 对下标从1开始但却仍在用<=（不自觉的用）

- 题目不会傻到给你一个数据直接输出就好了

- vector分配空间后，没有使用全部大小却使用size

- 无符号-1 变成int类的最大值

~~~C++
for(int i=0;i<(int)delans.size()-1;i++)//最好这么写，但是要注意size太大的话（超过int的一半）会出问题
            printf("%05d %d %05d\n",delans[i].addr,delans[i].key,delans[i+1].addr);
        printf("%05d %d -1\n",delans[delans.size()-1].addr,delans[delans.size()-1].key);
~~~

- if else分支流程不清楚导致 **答案错误** （pat1053）

- 混淆层与值的对应关系 a1053树的遍历

- 遍历树时把一个层的特征变量+=了 导致该变量成为一个局部的量被其他兄弟结点共享。a1053的sum

- 答案错误 if else出现漏洞(难以察觉的逻辑错误)

- 答案错误、运行时错误：写错符号i写错成j

- 使用队列或堆栈的值前**不判空**a1004

- 答案没说四舍五入你却四舍五入了a1079

- insertnode没写返回值返回给上一级和根节点（a1115）

- C/C++中，全局变量只能声明、初始化，而不能赋值

  也就是说，下面这样是不被允许的：

  ~~~C++
  #include <cstdio>
  using namespace std;
  int a;
  a = 2;
  int main() {
      
      return 0;
  }
  ~~~
  
- **codeblocks很傻X %lf用不了注意！判断有没有出数据可以看数据是否被排序了**

- **没有填上while循环内变量的终止条件！！**导致了**答案错误**a1098

- 因为常量值设置的太小导致**段错误**和**答案错误** a1021

## 拼写错误集合

- 指针却使用了.(a1115)
- 没有写括号
- i写成j
- **left写成right！！！对称的东西用了一下复制结果该改变的没有变全** 犯错次数2
- +=写成=
- ConcernedCities[i]写成了i

## 思路错误题目集合

- a1090.Highest Price in Supply Chain (25)-PAT甲级真题（DFS）
- b1098狼人杀-简单版(20分) 
- 缺什么条件补什么条件；
- 1043 Is It a Binary Search Tree (25 分)
- a1107.Social Clusters (30)-PAT甲级真题（并查集） **二刷**

~~~C++
1.路径压缩可能不完全需要能用findfather就用findfather
2.root的位置确定的有问题 等价条件的判断
~~~










































