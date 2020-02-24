#include<iostream>
#include<vector>
using namespace std;
int data[100010],Next[100010],dataTmp,nextTmp,addTmp;
vector<int> kArea,negArea,normalArea,answer;
int main(){
    int startAdd,n,k;
    cin>>startAdd>>n>>k;
    for(int i=0;i<n;i++){
        cin>>addTmp>>dataTmp>>nextTmp;
        data[addTmp]=dataTmp;
        Next[addTmp]=nextTmp;
    }
    addTmp=startAdd;
    while(addTmp!=-1){
        if(data[addTmp]<0)negArea.push_back(addTmp);
        else if(data[addTmp]<=k)kArea.push_back(addTmp);
        else normalArea.push_back(addTmp);
        addTmp=Next[addTmp];
    }
    answer.insert(answer.end(),negArea.begin(),negArea.end());
    answer.insert(answer.end(),kArea.begin(),kArea.end());
    answer.insert(answer.end(),normalArea.begin(),normalArea.end());
    for(int i=0;i<(int)answer.size()-1;i++)
        printf("%05d %d %05d\n",answer[i],data[answer[i]],answer[i+1]);
    printf("%05d %d -1\n",answer[(int)answer.size()-1],data[answer[(int)answer.size()-1]]);
    return 0;
}
