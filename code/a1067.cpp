#include<iostream>
#include<vector>
using namespace std;
vector<int> indexes;
int cntSwap=0;
int main(){
    int n,tmp;
    cin>>n;
    indexes.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        indexes[tmp]=i;
    }
    for(int i=0;i<n;i++){
        while(indexes[0]!=0){
            swap(indexes[0],indexes[indexes[0]]);
            cntSwap++;
        }
        if(indexes[i]!=i){
            swap(indexes[i],indexes[0]);
            cntSwap++;
        }
    }
    cout<<cntSwap;
    return 0;
}
