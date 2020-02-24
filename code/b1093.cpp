#include<iostream>
using namespace std;
bool isOccur[300]={0};
int main(){
    char ch;
    while((ch=cin.get())!='\n')
        if(isOccur[ch]==0){
            isOccur[ch]=true;
            cout<<ch;
        }
    while((ch=cin.get())!='\n')
        if(isOccur[ch]==0){
            isOccur[ch]=true;
            cout<<ch;
        }
    return 0;
}
