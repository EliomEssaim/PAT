#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> input;
int main(){
    long long n,p;
    cin>>n>>p;
    input.resize(n+1);
    for(int i=0;i<n;i++)cin>>input[i];
    input[n]=1000000000000000000;
    sort(input.begin(),input.end());
    long long rightIndex=1,minIndex=0,maxLength=0;
    long long maxValue;
    while(minIndex<n){
        maxValue=input[minIndex]*p;
        while(rightIndex<=n&&input[rightIndex]<=maxValue)rightIndex++;
        if(maxLength<rightIndex-minIndex) maxLength=rightIndex-minIndex;
        minIndex++;
    }
    cout<<maxLength;
    return 0;
}
