#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int prime[10010]={0};
bool isprime[10010]={true};
int main()
{
    int i,j,cnt=2;;
    prime[1]=2;
    for(i=2;i<10000;i++)
    {
        if(isprime[i])
        {
            for(j=i;j<10000;j+=i)
                isprime[j]=false;
        }
        if(isprime[i]) prime[cnt++]=i;
    }
    for(i=1;i<cnt;i++)
        printf("%d\n",prime[i]);
    return 0;
}
