#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main(){
    string a,b,ans;
    cin>>a>>b;
    auto it=a.find(b);
    if(it!=string::npos)
    cout<<a.substr(it,2);
    else
        cout<<"npos"<<endl;

    return 0;
}
//不一定要unordermap 不插入也可以做到啊 unordermap谨慎使用
// 找字符差异find是一把手
//结果不要求格式可以留到最后输出
