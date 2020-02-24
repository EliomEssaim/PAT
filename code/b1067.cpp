#include<iostream>
#include<string>
using namespace std;
string input,answer;
int threshold,wrongCnt=0;
int main(){
    cin>>answer>>threshold;
    while(cin.get()!='\n');
    while(getline(cin,input)&&input!="#"){
        if(input==answer){cout<<"Welcome in"<<endl;return 0;}
        else{cout<<"Wrong password: "<<input<<endl;wrongCnt++;}
        if(wrongCnt>=threshold){cout<<"Account locked"<<endl;return 0;}
    }
    return 0;
}
