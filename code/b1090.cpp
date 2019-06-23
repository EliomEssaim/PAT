#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n,m;
    map<int,vector<int> > unCompatible;
    scanf("%d%d",&n,&m);
    int gsA,gsB;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&gsA,&gsB);
        unCompatible[gsA].push_back(gsB);//unCompatible[gsA]代表vector
        unCompatible[gsB].push_back(gsA);
    }
    int amount,goods;
    for(int i=0;i<m;i++)
    {
        bool flag=true;
        scanf("%d",&amount);
        int IsExist[100010]={0};//忘记初始化
        vector<int> GoodsList(amount);//这个才是vector预分配空间
        for(int i=0;i<amount;i++)
        {
            scanf("%d",&goods);
            IsExist[goods]=1;
            GoodsList[i]=goods;
        }
        for(int i=0;flag&&(i<amount);i++)
            for(int j=0;j<unCompatible[GoodsList[i]].size();j++)
                if(IsExist[unCompatible[GoodsList[i]][j]])
                    {
                        flag=false;
                        break;
                    }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}
//map<int,vector<int>> m;实现不兼容的集合列表每个key
//代表一个货物，其vec里面的都是他的不兼容货物
//这个列表是有重复的
//map用来快速映射一个集合 遇到同一个key可以很方便的映射过去
