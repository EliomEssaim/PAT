#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> couple(100000,-1);
int main()
{
    int CoupleNums;
    scanf("%d",&CoupleNums);
    int man,woman;
    for(int i=0;i<CoupleNums;i++)
    {
        scanf("%d%d",&man,&woman);
        couple[man]=woman;
        couple[woman]=man;
    }
    int guestNum;
    scanf("%d",&guestNum);
    vector<int> guest(guestNum);
    set<int> Singles;
    for(int i=0;i<guestNum;i++)
    {
        scanf("%d",&guest[i]);
    }
    vector<int>::iterator it;
    bool flag=true;
    for(int i=0;i<guestNum;i++)
    {
        if(couple[guest[i]]!=-1)
        {
            it=find(guest.begin(),guest.end(),couple[guest[i]]);
            if(it!=guest.end()) flag=false;
        }
        if(flag==true) Singles.insert(guest[i]);
        else flag=true;
    }
    printf("%d\n",Singles.size());
    for(set<int>::iterator sit=Singles.begin();sit!=Singles.end();sit++)
    {
        if(sit!=Singles.begin()) printf(" ");
        printf("%05d",*sit);
    }
    return 0;
}
//如何实现成队？用什么样的数据结构
//看题目！（一定要看）隐含的条件输出格式要控制 不然会错
