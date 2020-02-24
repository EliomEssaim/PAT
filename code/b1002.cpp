#include<iostream>
#include<string>
#include<vector>
using namespace std;
string result,initString;
vector<string> tran2pingyin={
    "ling","yi","er","san","si","wu","liu","qi","ba","jiu"
};
int main(){
    int numResult=0;
    cin>>initString;
    for(int i=0;i<(int)initString.size();i++) numResult+=initString[i]-'0';
    result=to_string(numResult);
    for(int i=0;i<(int)result.size()-1;i++) cout<<tran2pingyin[result[i]-'0']<<" ";
    cout<<tran2pingyin[result[(int)result.size()-1]-'0']<<endl;
    return 0;

}
