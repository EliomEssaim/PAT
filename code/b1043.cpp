#include<iostream>
#include<vector>
using namespace std;
vector<int> patest(6);
int main(){
    char tmp;
    while(scanf("%c",&tmp)!=EOF){
        if(tmp=='P')patest[0]++;
        if(tmp=='A')patest[1]++;
        if(tmp=='T')patest[2]++;
        if(tmp=='e')patest[3]++;
        if(tmp=='s')patest[4]++;
        if(tmp=='t')patest[5]++;
    }
    while(patest[0]!=0||patest[1]!=0||patest[2]!=0||patest[3]!=0||patest[4]!=0||patest[5]!=0){
        if(patest[0]!=0){cout<<"P";patest[0]--;}
        if(patest[1]!=0){cout<<"A";patest[1]--;}
        if(patest[2]!=0){cout<<"T";patest[2]--;}
        if(patest[3]!=0){cout<<"e";patest[3]--;}
        if(patest[4]!=0){cout<<"s";patest[4]--;}
        if(patest[5]!=0){cout<<"t";patest[5]--;}
    }


    return 0;
}
