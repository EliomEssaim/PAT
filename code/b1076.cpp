#include<iostream>
#include<string>
using namespace std;
string tmp;
int main(){
    while(cin>>tmp)
        if(tmp.size()==3&&tmp[2]=='T')cout<<tmp[0]-'A'+1;
    return 0;
}
