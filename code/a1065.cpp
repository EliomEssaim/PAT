#include<iostream>
#include<string>
using namespace std;
string base="10000000000000000000";
string add(string a,string b){
    string sum;
    while(a.size()<b.size())a.insert(0,"0");
    while(b.size()<a.size())b.insert(0,"0");
    int carryBit=0;
    for(int i=a.size()-1;i>=0;i--){
        sum.insert(0,to_string((carryBit+a[i]-'0'+b[i]-'0')%10));
        carryBit=(carryBit+a[i]-'0'+b[i]-'0')/10;
    }
    if(carryBit==1)sum.insert(0,"1");
    while(sum.size()<base.size())sum.insert(0,"0");
    return sum;
}
string toPostive(string a){
    string sum;
    if(a[0]!='-')return add(a,base);
    else{
        a=a.substr(1);
        while(a.size()<base.size())a.insert(0,"0");
        int borrowBit=0,tmp;
        for(int i=a.size()-1;i>=0;i--){
            tmp=base[i]-a[i]-borrowBit;
            borrowBit=tmp<0?1:0;
            if(tmp<0)tmp+=10;
            sum.insert(0,to_string(tmp));
        }
    }
    while(sum.size()<base.size())sum.insert(0,"0");
    return sum;
}
int main(){
    string a,b,c;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        a=toPostive(a);b=toPostive(b);c=toPostive(c);
        printf("Case #%d: %s\n",i,add(a,b)>c?"true":"false");
    }
    return 0;
}
