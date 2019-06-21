#include<cstdio>
#include<set>
using namespace std;
int main()
{
    int m;
    scanf("%d",&m);
    set<int> s;
    for(int i=1;i<=m;i++)
        s.insert(i/2+i/3+i/5);
    printf("%d",s.size());
    return 0;
}
