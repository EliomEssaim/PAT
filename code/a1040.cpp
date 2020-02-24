#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
int maxSym=1,high=0,tmpSym=0,low=0;
int main(){
    getline(cin,str);
    for(int i=1;i<(int)str.size();i++){
        if(str[i]==str[i-1]){
            high=i;low=i-1;
            tmpSym=0;
            while(low>=0&&high<(int)str.size()&&str[low]==str[high]){
                low--;high++;
                tmpSym++;
            }
            tmpSym*=2;
        }
        if(tmpSym>maxSym)maxSym=tmpSym;
        if(i+1<(int)str.size()&&str[i-1]==str[i+1]){
            low=i-1;high=i+1;
            tmpSym=0;
            while(low>=0&&high<(int)str.size()&&str[low]==str[high]){
                low--;high++;
                tmpSym++;
            }
            tmpSym=tmpSym*2+1;
        }
        if(tmpSym>maxSym)maxSym=tmpSym;
    }
    cout<<maxSym;
    return 0;
}
