#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> cntChar(500);
int main(){
    int maxCnt=0,maxIndex=-1;
    string str;getline(cin,str);
    for(int i=0;i<(int)str.size();i++)cntChar[tolower(str[i])]++;
    for(int i=0;i<500;i++)
    if(cntChar[i]!=0&&isalpha((char)i)&&cntChar[i]>maxCnt){
        maxCnt=cntChar[i];maxIndex=i;
    }
    cout<<(char)maxIndex<<" "<<maxCnt<<endl;
    return 0;
}
