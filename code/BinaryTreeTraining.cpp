#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#define typename int
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* root=NULL;
node* newNode(int v){
    node* tmp=new node;
    tmp->data=v;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    return tmp;
}
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
void insertNode(node* &root,int data){
    if(root==NULL){
        root=newNode(data);
        return;
    }
    return ;
}
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
int pre[10]={0};
int in[10]={0};
node* create(int preL,int preR,int inL,int inR){
    int k;
    node* root=new node;
    if(inL>inR)
        return NULL;
    root->data=pre[preL];
    for(int i=inL;i<=inR;i++){
        if(in[i]==pre[preL]) k=i;
    }
    root->lchild=create(preL+1,preL+1+k-inL-1,inL,k-1);//¾«»ª
    root->rchild=create(preL+k-inL+1,preR,k+1,inR);
    return root;
}
int main()
{

    return 0;
}
