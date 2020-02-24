#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isInsertSort=false,loopEnd=true;
int index=0;//maxUnConsistantValueIndex
vector<int> originNums,afterSortNums;
int main(){
    int n;
    cin>>n;
    originNums.resize(n);afterSortNums.resize(n);
    for(int i=0;i<n;i++)cin>>originNums[i];
    for(int i=0;i<n;i++)cin>>afterSortNums[i];
    for(index=1;index<n&&afterSortNums[index-1]<=afterSortNums[index];index++);
    vector<int> tmpSeq=originNums;int j=index;
    while(originNums[j]==afterSortNums[j]&&j<n)j++;
    if(j==n)isInsertSort=true;
    if(isInsertSort){
        cout<<"Insertion Sort"<<endl;
        sort(tmpSeq.begin(),tmpSeq.begin()+index+1);
    }else{
        cout<<"Merge Sort"<<endl;
        tmpSeq=originNums;int mergeSortUnit=2;
        while(loopEnd){
            if(tmpSeq==afterSortNums) loopEnd=false;
            if(afterSortNums==originNums) mergeSortUnit*=2;
            for(int i=0;i*mergeSortUnit<n;i++)
                if((i+1)*mergeSortUnit<n)sort(tmpSeq.begin()+i*mergeSortUnit,tmpSeq.begin()+(i+1)*mergeSortUnit);
                else {sort(tmpSeq.begin()+i*mergeSortUnit,tmpSeq.begin()+n);break;}
            mergeSortUnit*=2;
        }
    }
    cout<<tmpSeq[0];
    for(int i=1;i<n;i++)cout<<" "<<tmpSeq[i];
    return 0;
}
