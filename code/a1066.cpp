#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
    int val;
    node *left,*right;
};
int getHeight(node* root){
    if(root==NULL) return 0;
    return max(getHeight(root->left),getHeight(root->right))+1;
}
int GetBalance(node* root){
    return getHeight(root->left)-getHeight(root->right);
}
void L(node* &root){
    node* tmp=root->right;
    root->right=tmp->left;
    tmp->left=root;
    root=tmp;
}
void R(node* &root){
    node* tmp=root->left;
    root->left=tmp->right;
    tmp->right=root;
    root=tmp;
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
            if(GetBalance(root->right)==-1)
                L(root);
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
int main(){
    int n,key;
    node *tree=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(tree,key);
    }
    printf("%d",tree->val);
    return 0;
}
