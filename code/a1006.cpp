#include<string>
#include<iostream>
using namespace std;
string lockedOne,unLockedOne,eraliest="23:59:59",latest="00:00:00",id,signIn,signOut;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>id>>signIn>>signOut;
        if(signIn<eraliest){eraliest=signIn;unLockedOne=id;}
        if(signOut>latest){latest=signOut;lockedOne=id;}
    }
    cout<<unLockedOne<<" "<<lockedOne;
    return 0;
}
