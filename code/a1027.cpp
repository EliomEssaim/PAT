#include<iostream>
#include<string>
using namespace std;
string color[3],ans;
int num[3];
string marsNum[13]={"0","1","2","3","4","5","6","7","8","9","A","B","C"};
int main(){
    cin>>num[0]>>num[1]>>num[2];
    ans+="#";
    for(int i=0;i<3;i++){
        string tmp;
        do{
            tmp.insert(0,marsNum[num[i]%13]);
            num[i]/=13;
        }while(num[i]!=0);
        while(tmp.size()<2)tmp.insert(0,"0");
        ans+=tmp;
    }
    cout<<ans;
    return 0;
}
