#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
    string name,id;
};
int maxScore=-1,maxId,minScore=101,minId;
int main(){
    int n,tmpScore;
    cin>>n;
    vector<node> List(n);
    for(int i=0;i<n;i++){
        cin>>List[i].name>>List[i].id>>tmpScore;
        if(tmpScore>maxScore){maxScore=tmpScore;maxId=i;}
        if(tmpScore<minScore){minScore=tmpScore;minId=i;}
    }
    cout<<List[maxId].name<<" "<<List[maxId].id<<endl;
    cout<<List[minId].name<<" "<<List[minId].id<<endl;
    return 0;
}
