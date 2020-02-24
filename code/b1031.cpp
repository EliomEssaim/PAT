#include<iostream>
#include<string>
using namespace std;
char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
int weigh[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
bool errorAppear=false;
int main(){
    int n;string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;int sum=0;
        for(int i=0;i<17;i++)sum+=(input[i]-'0')*weigh[i];
        if(M[sum%11]!=input[17]){
            errorAppear=true;
            cout<<input<<endl;
        }
    }
    if(!errorAppear)cout<<"All passed"<<endl;
    return 0;
}
