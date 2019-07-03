#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define flg_pre 1
#define flg_post 1
struct node{
    int weight;
    vector<int> childAddr;
};
vector<node> tree;
vector<int> path;//可以用吗
bool cmp(int a,int b){//child是什么类型这里就写什么类型
    return tree[a].weight>tree[b].weight;
}
int target;
void dfs(int index, int nodeNum, int sum){//传path效率低下不如传下标
    /***/
    //if(sum<target&&tree[index].childAddr.empty()) return;//也可什么都不做
    if(sum>target) return;//这里逻辑不清楚犯了错误下面的if不能写sum>=target 大于target后如果child.empty还是会进入函数这就不符合要求
    if(sum==target){
        if(tree[index].childAddr.empty()){
            path[nodeNum]=tree[index].weight;//如何快速分析出这里要写这一行 分析当前层和值的位置关系
            for(int i=0;i<=nodeNum;i++)
                printf("%d%c",path[i],i==nodeNum?'\n':' ');
        }
        else return;
    }
/**/
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        path[nodeNum]=tree[index].weight;//如何分析较快?写在这里也可以达到先传入权值的目的 写在/**/会导致最后一个无法输出 写在也行/***/但是不符合 dfs习惯
        dfs(tree[index].childAddr[i],nodeNum+1,sum+tree[tree[index].childAddr[i]].weight);//这里错误，类型不熟，child是地址
    }//写sum+=的话会导致值的累加（因为在for循环里面所以会随着for的进行而累加 而path本身不是+=进行for循环时= 原来的值不变（因为是本结点的）（也是我们的目的）
}//直接传递sum+...更好
int main()
{
    int n,m,node,childSize;
    scanf("%d%d%d",&n,&m,&target);
    tree.resize(n);
    path.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&tree[i].weight);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&node,&childSize);
        tree[node].childAddr.resize(childSize);
        for(int j=0;j<childSize;j++)
            scanf("%d",&tree[node].childAddr[j]);
        sort(tree[node].childAddr.begin(),tree[node].childAddr.end(),cmp);
    }
    dfs(0, 0, tree[0].weight);//由于写在位置/***/这里必须先给个初始值tree[0].weigh
    return 0;
}
//非递增排序的做法？在前面排序直接输出 和 先收集数据在输出 这题值得二刷
//如何记录路径
