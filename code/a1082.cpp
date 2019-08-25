#include<iostream>
#include<cmath>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[4] = { "Ge","Shi", "Bai","Qian"};
string unit[2]={ "Yi", "Wan"};
int J[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
int main(){
    int n;
    scanf("%d",&n);
    if(n==0) {
        cout<<"ling"<<endl;
        return 0;
    }
    if(n<0)cout<<"Fu ";
    n=abs(n);
    int printspace=0;
    bool zero=false;
    int curPos;
    for(int i=0;i<3;i++){
        for(int j=3;j>=0;j--){
            curPos=8-i*4+j;
            if(curPos>=9) continue;
            int cur=(n/J[curPos])%10;
            if(cur!=0){
                if(zero){
                    cout<<" "<<num[0];
                    zero=false;
                }
                printspace++==0?cout<<num[cur]:cout<<" "<<num[cur];
                if(curPos%4!=0) cout<<" "<<c[curPos%4];
            }else if(!zero&&curPos>=1&&j&&n/J[curPos-1]>=10) zero=true;//obsecure
        }
        if(i!=2&&n/J[curPos]>0) printspace++==0?cout<<unit[i]:cout<<" "<<unit[i];
    }
    return 0;
}
