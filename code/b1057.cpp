#include<iostream>
#include<string>
using namespace std;
int main(){
    char ch;
    int sum=0,oneCnt=0,zeroCnt=0;
    while((ch=cin.get())!='\n'){
        if(isalpha(ch)){
            ch=tolower(ch);
            sum+=ch-'a'+1;
        }
    }
    for(;sum!=0;sum/=2)sum%2==1?oneCnt++:zeroCnt++;
    cout<<zeroCnt<<" "<<oneCnt<<endl;
    return 0;
}
