#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> pre,post;bool isMirror=false;
void PostOrder(int start,int eend){
    if(start>eend) return ;
    int root=start,leftEnd=eend,RightStart=start+1;
    if(!isMirror){
        while(leftEnd>=root+1&&pre[root]<=pre[leftEnd])leftEnd--;//等号处理左子树空的情况
        while(RightStart<=eend&&pre[root]>pre[RightStart]) RightStart++;
    }
    else{//修改耗时
        while(leftEnd>=root+1&&pre[root]>pre[leftEnd])leftEnd--;//等号处理左子树空的情况
        while(RightStart<=eend&&pre[root]<=pre[RightStart]) RightStart++;
    }
    if(RightStart-leftEnd!=1) return;//耗时部分临界点的处理
    PostOrder(root+1,leftEnd);
    PostOrder(RightStart,eend);
    post.push_back(pre[root]);
}
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    pre.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    PostOrder(0,n-1);
    if((int)post.size()<n){
        isMirror=true;
        post.clear();//忘了清理；
        PostOrder(0,n-1);
    }
    if((int)post.size()<n) printf("NO\n");
    else {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%d%c",post[i],i==n-1?'\n':' ');
    }
    return 0;
}
//要给定搜索序列的开始和结束为位置，给出正常的终止条件给出异常的判断
//柳神的思路：给出了一个重要的二叉树思想，递归的处理序列，在什么位置处理就是什么位置的遍历十分简洁高效
