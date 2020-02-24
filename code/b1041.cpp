#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,string> cardNum,seat;
int main(){
    string seatTmp,idTmp,cardNumTmp;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>cardNumTmp>>idTmp>>seatTmp;
        cardNum[idTmp]=cardNumTmp;
        seat[idTmp]=seatTmp;
    }
    int k;cin>>k;
    for(int i=0;i<k;i++){
        cin>>idTmp;
        cout<<cardNum[idTmp]<<" "<<seat[idTmp]<<endl;
    }
    return 0;
}
