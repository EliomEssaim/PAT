#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int fullScore[200],rightChooseNum[200],wrongCnt[200];
vector<string> answer(200);
string tmpAns;
int main(){
    int n,m,chooseNum,maxWrongCnt=0;
    cin>>n>>m;
    char ch;
    for(int i=0;i<m;i++){
        tmpAns.clear();
        cin>>fullScore[i+1]>>chooseNum>>rightChooseNum[i+1];
        while((ch=cin.get())!='\n')tmpAns+=to_string(ch);
        answer[i+1]=tmpAns;
    }
    for(int i=0;i<n;i++){
        int studentScore=0;
        for(int j=1;j<=m;j++){
            while((ch=cin.get())!='(');
            tmpAns.clear();
            cin>>chooseNum;
            while((ch=cin.get())!=')')tmpAns+=to_string(ch);
            if(tmpAns!=answer[j])wrongCnt[j]++;
            else studentScore+=fullScore[j];
            if(maxWrongCnt<wrongCnt[j])maxWrongCnt=wrongCnt[j];
        }
        cout<<studentScore<<endl;
    }
    if(maxWrongCnt==0)cout<<"Too simple"<<endl;
    else{
        cout<<maxWrongCnt;
        for(int i=1;i<=m;i++)
            if(maxWrongCnt==wrongCnt[i])
            cout<<" "<<i;
    }
    return 0;
}
