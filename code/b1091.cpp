#include<iostream>
using namespace std;
int main(){
    int m,input,ans,lenth=1,n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>input;
        for(lenth=10;input/lenth!=0;lenth*=10);
        for(n=0;n<10;n++){
            ans=input*n*input;
            if(ans%lenth==input){
                cout<<n<<" "<<ans<<endl;
                break;
            }
        }
        if(n==10)cout<<"No"<<endl;
    }
    return 0;
}
