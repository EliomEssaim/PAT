#include<iostream>
#include<string>
using namespace std;
int a,b,sum,left_value,d;
string result;
int main(){
    cin>>a>>b>>d;
    sum=a+b;left_value=sum;
    while(left_value>0){
        result.insert(0,to_string(left_value%d));
        left_value/=d;
    }
    cout<<result<<endl;
    return 0;
}
