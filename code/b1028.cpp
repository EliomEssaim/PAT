#include<iostream>
#include<string>
using namespace std;
string oldest_name,youngest_name;
int oldest_days=1000000000,young_days=-1;
int validDataNumber=0;
int main(){
    int n;cin>>n;
    string nameTmp;
    int yearTmp,monthTmp,daysTmp,tranTmp;
    int upLimit=2014*365+9*30+6;
    int downLimit=1814*365+9*30+6;
    for(int i=0;i<n;i++){
       cin>>nameTmp;
       scanf("%d/%d/%d",&yearTmp,&monthTmp,&daysTmp);
        tranTmp=yearTmp*365+monthTmp*30+daysTmp;
        if(tranTmp<=upLimit&&tranTmp>=downLimit){
            if(tranTmp<oldest_days){
                oldest_days=tranTmp;
                oldest_name=nameTmp;
            }
            if(tranTmp>young_days){
                young_days=tranTmp;
                youngest_name=nameTmp;
            }
            validDataNumber++;
        }
    }
    cout<<validDataNumber;
    if(validDataNumber!=0) cout<<oldest_name<<youngest_name;
    return 0;
}
