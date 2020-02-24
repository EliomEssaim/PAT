#include<iostream>
#include<iomanip>
using namespace std;
bool isUpdate[5]={0};int a[5];
bool firstOut=true;
int main(){
    int input,n,a4Cnt=0,fu=1;
    a[0]=0;a[1]=0;a[2]=0;a[3]=0;a[4]=-1;
    cin>>n;
    while(cin>>input){
        switch(input%5){
        case 0:
            if(input%2==0){
                a[0]+=input;
                isUpdate[0]=true;
            }
            break;
        case 1:
            a[1]+=fu*input;
            fu=-fu;
            isUpdate[1]=true;
            break;
        case 2:
            a[2]++;
            isUpdate[2]=true;
            break;
        case 3:
            a[3]+=input;a4Cnt++;
            isUpdate[3]=true;
            break;
        case 4:
            if(input>a[4])a[4]=input;
            isUpdate[4]=true;
            break;
        default:;
        }
    }
    for(int i=0;i<5;i++){
        if(!firstOut)cout<<" ";
        if(isUpdate[i]){
            if(i!=3)cout<<a[i];
            else cout<<setprecision(1)<<fixed<<(float)a[3]/(float)a4Cnt;
        }
        else cout<<"N";
        firstOut=false;
    }
}
