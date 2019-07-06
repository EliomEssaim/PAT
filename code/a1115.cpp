#include<iostream>
#include<vector>
using namespace std;
struct node{
    int key;
    node* lchild;
    node* rchild;
};
node* tree=NULL;
vector<int> depth;//�ǵ���resize
node* InsertNode(node* index,int value){
    if(index==NULL){
        node* newNode=new node;
        newNode->lchild=NULL;//��̬д����
        newNode->rchild=NULL;//ָ��ȴʹ����.
        newNode->key=value;
        return newNode;
    }
    if(index->key>=value)
        index->lchild=InsertNode(index->lchild,value);
    if(index->key<value)
        index->rchild=InsertNode(index->rchild,value);
    return index;//���벻��ʵ�ֽ�����Ϊ��Ȼ�з���ֵ����û��nodeȥ����
}
void dfs(node* index,int d){
    if(index==NULL)        return ;
    depth[d]++;
    dfs(index->lchild,d+1);
    dfs(index->rchild,d+1);
}
int main(){
    int n,tmp;
    scanf("%d",&n);
    depth.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        tree=InsertNode(tree,tmp);//û��дtree=
    }
    dfs(tree,0);
    int a,b=0;
    while(b!=n&&depth[b]!=0) b++;//����ûд
    b=b-1;//�Լ����Լ��߼����������bӦ�ü�һ �ҵ���������ĺ�һ��
    a=b-1;
    printf("%d + %d = %d",depth[b],depth[a],depth[a]+depth[b]);

    return 0;

}
