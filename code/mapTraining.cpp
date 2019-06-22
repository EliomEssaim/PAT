#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<string,int> mp;
    mp["hello"]=1;
    mp["world"]=2;
    mp["terrorist"]=3;
    cout<<mp["hello"]<<endl;
    map<string,int>::iterator it=mp.find("world");
    printf("%d",it->second);

    return 0;
}
