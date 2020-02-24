#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> char2int;
string n1,n2;
int minRadix=-1,minNum=-1;
long long tag,aradix,numN1=0L,numN2=0L,ans;
long long convert(const string &num,long long &radix){
    long long sum=0L,factor=1L;
    for(int i=num.size()-1;i>=0;i--,factor*=radix)
        sum+=char2int[num[i]]*factor;
    return sum;
}
long long findRadix(const string &num,long long low,long long high){
    high=max(low,high);
    while(low<=high){
        long long mid=(low+high)/2;
        numN2=convert(num,mid);
        if(numN2>numN1||numN2<0)high=mid-1;
        else if(numN2<numN1)low=mid+1;
        else return mid;
    }
    return -1;
}
int main(){
    for(int i=0;i<10;i++) char2int[i+'0']=i;
    for(int i=10;i<36;i++)char2int[i-10+'a']=i;
    cin>>n1>>n2>>tag>>aradix;
    if(tag==2)swap(n1,n2);
    numN1=convert(n1,aradix);
    for(auto &val:n2)
        if(char2int[val]>minNum)minNum=char2int[val];
    minRadix=minNum+1;
    ans=findRadix(n2,minRadix,numN1);
    if(ans!=-1L)cout<<ans;
    else cout<<"Impossible"<<endl;
    return 0;
}
