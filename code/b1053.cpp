#include<iostream>
#include<iomanip>
using namespace std;
int possibleFreeCnt=0,freeCnt=0,d;
double e,input;
int main(){
    int n,k,tmpFreeCnt;cin>>n>>e>>d;
    for(int i=0;i<n;i++){
        cin>>k;tmpFreeCnt=0;
        for(int j=0;j<k;j++){
            cin>>input;
            if(input<e)tmpFreeCnt++;
        }
        if(tmpFreeCnt>k/2&&k>d)freeCnt++;
        else if(tmpFreeCnt>k/2) possibleFreeCnt++;
    }
    cout<<setprecision(1)<<fixed<<100.0*possibleFreeCnt/n<<"% ";
    cout<<setprecision(1)<<fixed<<100.0*freeCnt/n<<"%";
    return 0;
}
