#include<iostream>
#include<vector>
using namespace std;
vector<int> input;
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    m=m%n;input.resize(n);
    for(int i=0;i<n;i++) cin>>input[i];
    for(int i=0;i<n;i++) {
        if(i!=0)cout<<" ";
        cout<<input[(i-m+n)%n];
    }
    return 0;
}
