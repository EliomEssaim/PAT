#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> input;
int main(){
    int n;cin>>n;
    input.resize(n);
    for(int i=0;i<n;i++)cin>>input[i];
    sort(input.begin(),input.end());
    double rope=input[0];
    for(int i=1;i<n;i++){
        if(input[i]>rope)rope=(input[i]+rope)/2;
        else break;
    }
    cout<<(int)rope<<endl;
    return 0;
}
