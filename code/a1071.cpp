#include<iostream>
#include<string>
#include<map>
using namespace std;
string str,word,maxWord;
map<string,int> wordCnt;
int i=0,j=0,maxCnt=-1;
int main(){
    getline(cin,str);
    for(int i=0;i<(int)str.size();i++)
        str[i]=tolower(str[i]);
    for(;i<(int)str.size();i=j){
        while(!isalnum(str[i])&&i<(int)str.size())i++;
        for(j=i;isalnum(str[j])&&j<(int)str.size();j++);
        word=str.substr(i,j-i);
        if(!word.empty())wordCnt[word]++;
        if(wordCnt[word]>maxCnt){
            maxCnt=wordCnt[word];
            maxWord=word;
        }
    }
    cout<<maxWord<<" "<<maxCnt;
    return 0;
}
