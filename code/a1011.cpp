#include<iostream>
#include<vector>
using namespace std;
int indexEachLine[3];
double lineMax[3],maxNum=-1.0,tmp;
char int2char[3]={'W','T','L'};
int main(){
    for(int i=0;i<3;i++){
        maxNum=-1.0;
        for(int j=0;j<3;j++){
            cin>>tmp;
            if(tmp>maxNum){
                maxNum=tmp;
                indexEachLine[i]=j;
            }
        }
        lineMax[i]=maxNum;
    }
    for(int i=0;i<3;i++)
        cout<<int2char[indexEachLine[i]]<<" ";
    printf("%.2f",(lineMax[0]*lineMax[1]*lineMax[2]*0.65-1)*2);
    return 0;
}
