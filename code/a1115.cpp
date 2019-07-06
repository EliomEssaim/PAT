#include<iostream>
#include<vector>
using namespace std;
struct node{
    int key;
    node* lchild;
    node* rchild;
};
node* tree=NULL;
vector<int> depth;//记得先resize
node* InsertNode(node* index,int value){
    if(index==NULL){
        node* newNode=new node;
        newNode->lchild=NULL;//静态写法？
        newNode->rchild=NULL;//指针却使用了.
        newNode->key=value;
        return newNode;
    }
    if(index->key>=value)
        index->lchild=InsertNode(index->lchild,value);
    if(index->key<value)
        index->rchild=InsertNode(index->rchild,value);
    return index;//代码不能实现建树因为虽然有返回值但是没有node去接收
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
        tree=InsertNode(tree,tmp);//没有写tree=
    }
    dfs(tree,0);
    int a,b=0;
    while(b!=n&&depth[b]!=0) b++;//括号没写
    b=b-1;//自己吧自己逻辑搞混了这里b应该减一 找到的是最后层的后一个
    a=b-1;
    printf("%d + %d = %d",depth[b],depth[a],depth[a]+depth[b]);

    return 0;

}
