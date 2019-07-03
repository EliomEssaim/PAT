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
vector<int> path;//��������
bool cmp(int a,int b){//child��ʲô���������дʲô����
    return tree[a].weight>tree[b].weight;
}
int target;
void dfs(int index, int nodeNum, int sum){//��pathЧ�ʵ��²��紫�±�
    /***/
    //if(sum<target&&tree[index].childAddr.empty()) return;//Ҳ��ʲô������
    if(sum>target) return;//�����߼���������˴��������if����дsum>=target ����target�����child.empty���ǻ���뺯����Ͳ�����Ҫ��
    if(sum==target){
        if(tree[index].childAddr.empty()){
            path[nodeNum]=tree[index].weight;//��ο��ٷ���������Ҫд��һ�� ������ǰ���ֵ��λ�ù�ϵ
            for(int i=0;i<=nodeNum;i++)
                printf("%d%c",path[i],i==nodeNum?'\n':' ');
        }
        else return;
    }
/**/
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        path[nodeNum]=tree[index].weight;//��η����Ͽ�?д������Ҳ���Դﵽ�ȴ���Ȩֵ��Ŀ�� д��/**/�ᵼ�����һ���޷���� д��Ҳ��/***/���ǲ����� dfsϰ��
        dfs(tree[index].childAddr[i],nodeNum+1,sum+tree[tree[index].childAddr[i]].weight);//����������Ͳ��죬child�ǵ�ַ
    }//дsum+=�Ļ��ᵼ��ֵ���ۼӣ���Ϊ��forѭ���������Ի�����for�Ľ��ж��ۼ� ��path������+=����forѭ��ʱ= ԭ����ֵ���䣨��Ϊ�Ǳ����ģ���Ҳ�����ǵ�Ŀ�ģ�
}//ֱ�Ӵ���sum+...����
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
    dfs(0, 0, tree[0].weight);//����д��λ��/***/��������ȸ�����ʼֵtree[0].weigh
    return 0;
}
//�ǵ����������������ǰ������ֱ����� �� ���ռ���������� ����ֵ�ö�ˢ
//��μ�¼·��
