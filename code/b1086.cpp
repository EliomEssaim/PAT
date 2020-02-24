#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    string str=to_string(a*b);
    reverse(str.begin(),str.end());
    cout<<stoi(str)<<endl;
    return 0;
}
