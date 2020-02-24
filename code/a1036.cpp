#include<iostream>
#include<string>
using namespace std;
string FMaxRecord,MMinRecord;
int FMaxNum=-1,MMinNum=2000000000;
int main(){
    int n;
    cin>>n;
    string name,gender,ID,score;
    for(int i=0;i<n;i++){
        cin>>name>>gender>>ID>>score;
        if(gender=="F"&&stoi(score)>FMaxNum){
            FMaxRecord=name+" "+ID+"\n";
            FMaxNum=stoi(score);
        }
        if(gender=="M"&&stoi(score)<MMinNum){
            MMinRecord=name+" "+ID+"\n";
            MMinNum=stoi(score);
        }
    }
    if(FMaxRecord.empty())cout<<"Absent"<<endl;
    else cout<<FMaxRecord;
    if(MMinRecord.empty())cout<<"Absent"<<endl;
    else cout<<MMinRecord;
    if(FMaxRecord.empty()||MMinRecord.empty())
        cout<<"NA"<<endl;
    else cout<<FMaxNum-MMinNum<<endl;
    return 0;
}
