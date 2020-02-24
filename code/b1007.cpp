#include<iostream>
#include<vector>
using namespace std;
vector<bool> isPrime(100001);
vector<int>primeList;
int main(){
    fill(isPrime.begin(),isPrime.end(),true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<100001;i++)
        for(int j=i*2;j<100001;j+=i)
            isPrime[j]=false;
    int range,cnt=0;
    cin>>range;
    for(int i=5;i<=range;i++)
        if(isPrime[i-2]&&isPrime[i])cnt++;
    cout<<cnt;
    return 0;
}
