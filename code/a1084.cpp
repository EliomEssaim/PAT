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
//��һ��Ҫunordermap ������Ҳ���������� unordermap����ʹ��
// ���ַ�����find��һ����
//�����Ҫ���ʽ��������������
