#include<iostream>
using namespace std;
int main(){
    int pGalleon,pSickle,pKnut;
    int aGalleon,aSickle,aKnut;
    scanf("%d.%d.%d %d.%d.%d",&pGalleon,&pSickle,&pKnut,&aGalleon,&aSickle,&aKnut);
    long long actual=aKnut+aSickle*29+aGalleon*29*17;
    long long payShould=pKnut+pSickle*29+pGalleon*29*17;
    if(actual>=payShould)cout<<(actual-payShould)/29/17<<"."<<(actual-payShould)/29%17<<"."<<(actual-payShould)%29;
    else cout<<"-"<<(payShould-actual)/29/17<<"."<<(payShould-actual)/29%17<<"."<<(payShould-actual)%29;
    return 0;
}
