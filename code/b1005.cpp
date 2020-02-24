#include<iostream>
#include<vector>
using namespace std;
vector<bool> isExist(1000),isCover(1000);
bool firstOut=true;
int main(){
    int n,addr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>addr;
        isExist[addr]=true;
        if(!isCover[addr])addr=addr%2==0?addr/2:(addr*3+1)/2;//实现除了本身，余下的值都cover，而且遇到一个cover值可以直接跳过
        while(!isCover[addr]&&addr!=1){//这里可能出现多次的addr*3+1导致溢出
            isCover[addr]=true;//如果判断条件本身是随循环迭代的 那么必需在变化前写上，判断条件的变化。否则循环会直接判断迭
            addr=addr%2==0?addr/2:(addr*3+1)/2;
        }
    }
    for(int i=100;i>0;i--)
        if(isExist[i]&&!isCover[i]){
            if(!firstOut)cout<<" ";
            cout<<i;firstOut=false;
        }
    return 0;
}
