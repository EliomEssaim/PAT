#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> pre,post;bool isMirror=false;
void PostOrder(int start,int eend){
    if(start>eend) return ;
    int root=start,leftEnd=eend,RightStart=start+1;
    if(!isMirror){
        while(leftEnd>=root+1&&pre[root]<=pre[leftEnd])leftEnd--;//�ȺŴ����������յ����
        while(RightStart<=eend&&pre[root]>pre[RightStart]) RightStart++;
    }
    else{//�޸ĺ�ʱ
        while(leftEnd>=root+1&&pre[root]>pre[leftEnd])leftEnd--;//�ȺŴ����������յ����
        while(RightStart<=eend&&pre[root]<=pre[RightStart]) RightStart++;
    }
    if(RightStart-leftEnd!=1) return;//��ʱ�����ٽ��Ĵ���
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
        post.clear();//��������
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
//Ҫ�����������еĿ�ʼ�ͽ���Ϊλ�ã�������������ֹ���������쳣���ж�
//�����˼·��������һ����Ҫ�Ķ�����˼�룬�ݹ�Ĵ������У���ʲôλ�ô������ʲôλ�õı���ʮ�ּ���Ч
