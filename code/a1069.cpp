#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a,b,sum;
string astr,bstr;
int main(){
    cin>>sum;
    do{
        astr=to_string(sum);
        while(astr.size()<4)astr.insert(0,"0");
        sort(astr.begin(),astr.end());
        bstr=astr;
        reverse(bstr.begin(),bstr.end());
        a=stoi(astr);b=stoi(bstr);
        sum=b-a;
        printf("%04d - %04d = %04d\n",b,a,sum);
    }while(sum!=6174&&sum!=0);
    return 0;
}
