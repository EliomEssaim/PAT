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
        unCompatible[gsA].push_back(gsB);//unCompatible[gsA]����vector
        unCompatible[gsB].push_back(gsA);
    }
    int amount,goods;
    for(int i=0;i<m;i++)
    {
        bool flag=true;
        scanf("%d",&amount);
        int IsExist[100010]={0};//���ǳ�ʼ��
        vector<int> GoodsList(amount);//�������vectorԤ����ռ�
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
//map<int,vector<int>> m;ʵ�ֲ����ݵļ����б�ÿ��key
//����һ�������vec����Ķ������Ĳ����ݻ���
//����б������ظ���
//map��������ӳ��һ������ ����ͬһ��key���Ժܷ����ӳ���ȥ
