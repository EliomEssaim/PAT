#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int addr,key,next;
}Node[100010];
bool isExist[10010]={false};
int main()
{
    int firstNode,N;
    scanf("%d%d",&firstNode,&N);
    int pos;
    while(N--)
    {
        scanf("%d",&pos);scanf("%d%d",&Node[pos].key,&Node[pos].next);
        Node[pos].addr=pos;
    }
    vector<node> ans,delans;
    for(int i=firstNode;i!=-1;i=Node[i].next){
            if(isExist[abs(Node[i].key)]==false){
                    isExist[abs(Node[i].key)]=true;
                    ans.push_back(Node[i]);
                }
            else delans.push_back(Node[i]);
        }
    for(int i=0;(unsigned)i<ans.size()-1;i++)
        printf("%05d %d %05d\n",ans[i].addr,ans[i].key,ans[i+1].addr);
    printf("%05d %d -1\n",ans[ans.size()-1].addr,ans[ans.size()-1].key);
    if(delans.size()){
        for(int i=0;(unsigned)i<delans.size()-1;i++)
            printf("%05d %d %05d\n",delans[i].addr,delans[i].key,delans[i+1].addr);
        printf("%05d %d -1\n",delans[delans.size()-1].addr,delans[delans.size()-1].key);
    }
    return 0;
}
//没有想到没要要删除的输出的情况
