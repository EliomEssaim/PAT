#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int gcd(int a,int b){
   return a%b==0?b:gcd(b,a%b);
}
int n,k;
vector<int> digits;
int main(){
    cin>>n>>k;
    digits.resize(k);
    int leftValue=n;
    for(int i=0;i<k;i++){
        if((leftValue-9)>=0){
            digits[i]=9;
            leftValue-=9;
        }else{
            digits[i]=leftValue%10;
            leftValue=0;
        }
    }
    vector<vector<int>> nextNums;
    int less9=0,cntDiff=0;
    while(digits[less9]==9)less9++;
    int left=less9-1,right=less9+1;
    if(left>=0)||less9==k{
        nextNums.push_back(digits);
        if(digits[left]-1>digits[less9])
    }
    return 0;
}

/**/
