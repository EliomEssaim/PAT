#include<iostream>
#include<string>
using namespace std;
string result;
int main(){
    int quote,head=0;
    for(int i=0;i<10;i++){
        cin>>quote;//lianghzong 方案 因为不知道输入可以自然有序
        if(head==0&&quote!=0&&i!=0)head=i;
        while(quote>0){
            result+=to_string(i);
            quote--;
        }
    }
    if(head==0){cout<<0<<endl;return 0;}
    for(int i=0;i<(int)result.size();i++){
        if(result[i]==(head+'0')){
            result[i]=result[0];
            result[0]=head+'0';
        }
    }
    cout<<result<<endl;
    return 0;
}
