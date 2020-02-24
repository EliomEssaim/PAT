#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> input;bool firstOut=true;
int main(){
    int n;cin>>n;input.resize(n);
    for(int i=0;i<n;i++)cin>>input[i];
    sort(input.begin(),input.end());
    reverse(input.begin(),input.end());
    for(int i=n;i>=1;i--)
        if(input[i-1]>i){
            cout<<i;
            firstOut=false;
            break;
        }
    if(firstOut)cout<<0;
    return 0;
}
