#include<iostream>
using namespace std;
int main(){
    int aScout,aGive,bScout,bGive,aDrink=0,bDrink=0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>aScout>>aGive>>bScout>>bGive;
        if(aGive!=bGive){
            if((aScout+bScout)==aGive)bDrink++;
            if((aScout+bScout)==bGive)aDrink++;
        }
    }
    cout<<aDrink<<" "<<bDrink<<endl;
    return 0;
}
