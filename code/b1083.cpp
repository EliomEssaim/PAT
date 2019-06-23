#include<iostream>
#include<cstdio>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    map<int,int> mp;
    scanf("%d",&n);
    int tmp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        mp[(int)abs(i-tmp)]++;
    }
    map<int,int>::reverse_iterator it=mp.rbegin();
    for(;it!=mp.rend();it++)
        if(it->second>=2)
            cout<<it->first<<" "<<it->second<<endl;

    return 0;
}
//ÖØ¸´ÒªÇóit->second >=2
