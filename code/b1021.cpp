#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> cnt;
string in;
int main(){
    cin>>in;
    for(int i=0;i<(int)in.size();i++){
        cnt[in[i]]++;
    }
    for(auto it=cnt.begin();it!=cnt.end();it++ ){
        printf("%c:%d\n",it->first,it->second);
    }
    return 0;
}
