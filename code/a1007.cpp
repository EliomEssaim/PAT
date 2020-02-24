#include<iostream>
#include<vector>
using namespace std;
vector<int> input;
int start=0,eend=start,maxSum=-1000000000,tmpSum=0;
int main(){
    int n;
    cin>>n;input.resize(n);
    int Smax=0,Emax=n-1;
    for(auto &val:input)cin>>val;
    for(;start<n;start=eend){
        tmpSum=input[start];
        for(eend=start+1;tmpSum>=0&&eend<n;eend++){
            tmpSum+=eend==start?input[start]:input[eend];
            if(tmpSum>maxSum){
                maxSum=tmpSum;
                Smax=start;Emax=eend;
            }
        }
        tmpSum=0;
    }
    if(maxSum<0)maxSum=0;
    cout<<maxSum<<" "<<input[Smax]<<" "<<input[Emax];
    return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;
vector<int> input;
int start=0,eend=start,maxSum=-1000000000,tmpSum=0,Smax,Emax;
int main(){
    int n;
    cin>>n;input.resize(n);
    for(auto &val:input)cin>>val;
    for(;start<n;start=eend){
        tmpSum=0;
        for(eend=start;tmpSum>=0&&eend<n;eend++){
            tmpSum+=eend==start?input[start]:input[eend];
            if(tmpSum>maxSum){
                maxSum=tmpSum;
                Smax=start;Emax=eend;
            }
        }
    }
    cout<<maxSum<<" "<<input[Smax]<<" "<<input[Emax];
    return 0;
}

*/
