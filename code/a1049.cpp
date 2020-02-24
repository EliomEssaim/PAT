#include<iostream>
#include<string>
#include<math.h>
using namespace std;
long long lenthCntOne[10]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
long long tenTimes[10]{0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
string str;
long long cntOne(string str){
    long long sum=0;
    if(str.size()==1)
        return str[0]-'0'>=1?1:0;
    long long aj=str[0]-'0';
    if(aj!=0){
        sum+=aj*lenthCntOne[str.size()-1];
        if(aj==1)sum+=stoi(str)%tenTimes[str.size()-1]+1;
        else sum+=tenTimes[str.size()-1];
    }
    sum+=cntOne(str.substr(1));
    return sum;
}
int main(){
    cin>>str;
    cout<<cntOne(str)<<endl;
    return 0;
}
