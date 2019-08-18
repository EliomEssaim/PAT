#include<iostream>
#include<vector>
using namespace std;
int Msize,n;const int primeNumEdge=10010;
vector<int> hashTable;
void insert(int key){
    int index=key,step=0;
    for(;step<Msize;step++){
        index=(key+step*step)%Msize;
        if(hashTable[index]==0){
            hashTable[index]=1;
            cout<<index;return;
        }
    }
    cout<<"-";
}
int main(){
    vector<bool> isPrime(primeNumEdge,true);//只能赋值0
    for(int i=2;i<primeNumEdge;i++){
        for(int j=2;j*i<primeNumEdge;j++)
            isPrime[i*j]=false;//实现方式 有瑕疵
    }
    isPrime[1]=false;isPrime[0]=false;
    scanf("%d%d",&Msize,&n);
    while(!isPrime[Msize]) Msize++;
    hashTable.resize(Msize,0);
    int key;
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        if(i!=0) cout<<" ";
        insert(key);
    }
    return 0;
}










#if 0
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int primeNumEdge=10010;
vector<int> hashTable;map<int,int> mp;
vector<bool> isPrime(primeNumEdge,true);//只能赋值0
vector<int> postiveInterger;
int main(){
    for(int i=2;i<primeNumEdge;i++){
        for(int j=2;j*i<primeNumEdge;j++)
            isPrime[i*j]=false;//实现方式 有瑕疵
    }
    int Msize,n;
    scanf("%d%d",&Msize,&n);
    while(!isPrime[Msize]) Msize++;
    hashTable.resize(Msize);postiveInterger.resize(Msize);
    for(int i=0;i<Msize;i++)
        hashTable[i]=-1;
    int value;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        postiveInterger[i]=value;
        int leftValue=value%Msize;
        if(hashTable[leftValue]==-1){
            hashTable[leftValue]=value;
            mp[value]=leftValue;
        }else{
             int k=1,testPos;
            while(1){
                testPos=(leftValue+k*k)%Msize;
                if(hashTable[testPos]==-1)
                    break;
                testPos=(leftValue-k*k+k*k*Msize)%Msize;
                if(hashTable[testPos]==-1)
                    break;
                k++;
            }
            hashTable[testPos]=value;
            mp[value]=testPos;
        }
    }
    for(int i=0;i<n;i++){
        auto it=mp.find(postiveInterger[i]);//map判断找不到
        if(it!=mp.end()){
            printf("%d",mp[postiveInterger[i]]);
        }else{
            printf("-");
        }
        if(i!=n-1) printf(" ");
        else printf("\n");
    }

    return 0;
}
#endif // 0
//质数表生成不够熟练
/*
for(int i=2;i<limit;i++){
    for(int j=2;i*j<limit;j++)
        isPrime[i*j]=false;
}
*/
//审题positive正数 non-negative非负
//题目有点毛病出的平方探测法和教材不一样
