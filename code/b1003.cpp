#include<iostream>
#include<string>
using namespace std;
string input;
int posP,posT;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        int cntP=0,cntT=0;
        for(int i=0;i<(int)input.size();i++){
            if(input[i]=='P') {cntP++;posP=i;continue;}
            if(input[i]=='A') continue;
            if(input[i]=='T') {cntT++;posT=i;continue;}
            goto no;
        }
        if(cntP==1&&cntT==1&&(posT-posP)>1&&((posT-posP-1)*posP==((int)input.size()-posT-1))){
            cout<<"YES"<<endl;continue;
        }
no:     cout<<"NO"<<endl;
    }
    return 0;
}
