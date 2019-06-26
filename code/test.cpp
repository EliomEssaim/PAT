#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
        str[i]=tolower(str[i]);
    cout<<str<<endl;
    for(int i=0;i<str.size();i++)
        str[i]=toupper(str[i]);
    cout<<str<<endl;
    return 0;
}
