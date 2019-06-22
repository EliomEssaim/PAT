#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    cin>>str;
    cout<<str;
    for(int i=0;i<str.length();i++)
        printf("%c",str[i]);
    cout<<str<<endl;
    printf("%s",str.c_str());

    cout<<endl;
    str+="ok";

    cout<<str<<endl;
    for(string::iterator it=str.begin();it<str.end();it++)
    {
        printf("%c",*it);
    }
    string str2="xyzÕÙ»½";
    if(str>str2)
        cout<<str<<endl;
    else
        cout<<str2<<endl;
    cout<<str2.size()<<endl;
    str.insert(3,"¸ÊÁØÄï");
    cout<<str<<endl;
    str.erase(str.begin()+2);
    cout<<str<<endl;

    cout<<string::npos<<endl;
    cout<<sizeof(int)<<endl;
    str="all is over ok?";
    cout<<str<<endl;
    if(str.find("ok")!=string::npos)
        cout<<"ok"<<str.find("ok")<<endl;
    return 0;
}
