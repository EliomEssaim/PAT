#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> input;
int main(){
    int n,sum=0;cin>>n;
    input.resize(n);
    for(int i=0;i<n;i++)cin>>input[i];
    for(int i=0;i<n;i++){
        int k=i+1;if(k==n) k=0;
        for(int j=1;j<n;j++,k++){
            if(k==n) k=0;
            sum+=input[i]*10+input[k];
        }
    }
    cout<<sum;AaAa
    return 0;
}
