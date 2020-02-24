#include<iostream>
#include<iomanip>
using namespace std;
double sum=0,tmp;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        sum+=(i+1)*(n-i)*tmp;
    }
    printf("%.2f",sum);
    return 0;
}
