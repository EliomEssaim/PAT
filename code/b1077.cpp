#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> studentJudge;
int G1,G2,n,m,tmpScore;
float sum,aver,finScore;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        sum=0.0;
        studentJudge.clear();
        for(int j=0;j<n;j++){
            j==0?cin>>G1:cin>>tmpScore;
            if(j!=0&&tmpScore>=0&&tmpScore<=m)studentJudge.push_back(tmpScore);
        }
        sort(studentJudge.begin(),studentJudge.end());
        for(int j=1;j<(int)studentJudge.size()-1;j++)
            sum+=studentJudge[j];
        aver=sum/((int)studentJudge.size()-2);
        finScore=(aver+G1)/2.0+0.5;
        cout<<(int)finScore<<endl;
    }
    return 0;
}
