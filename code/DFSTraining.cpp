#include<iostream>
#include<vector>
#define maxn 50
using namespace std;
int n,x,k,maxSumSqen=-1,A[maxn];
vector<int> ans,temp;

void DFS(int index,int nowK,int sum,int sumSqu)
{
    if(nowK==k&&sum==x)
    {
        if(sumSqu>maxSumSqen){
            maxSumSqen=sumSqu;
            ans=temp;
        }
        return ;
    }
    if(index==n||nowK>k||sum>x) return;
    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);
}
int main()
{

    return 0;
}
