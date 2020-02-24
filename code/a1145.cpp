#include<iostream>
#include<vector>
using namespace std;
int MSize,n,m,key,pos,j;
vector<int> hashTable;
bool isPrime(int a){
    for(int i=2;i*i<=a;i++)
        if(a%i==0)return false;
    return true;
}
int main(){
    cin>>MSize>>n>>m;
    while(!isPrime(MSize))MSize++;
    hashTable.resize(MSize);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        for(j=0;j<MSize;j++){
            pos=(key+j*j)%MSize;
            if(hashTable[pos]==0)break;
        }
        if(j==MSize)printf("%d cannot be inserted.\n",key);
        else hashTable[pos]=key;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        scanf("%d",&key);
        for(j=0;j<=MSize;j++){
            pos=(key+j*j)%MSize;
            ans++;
            if(hashTable[pos]==key||hashTable[pos]==0)break;
        }
    }
    printf("%.1f",(float)ans/m);
    return 0;
}
