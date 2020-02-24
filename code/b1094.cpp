#include<iostream>
#include<string>
using namespace std;
bool fail=false;
int l,k,num;
int main(){
    string str;
    scanf("%d%d\n",&l,&k);
    getline(cin,str);
    for(int i=0;i+k<=(int)str.size();i++){
        num=stoi(str.substr(i,k));
        fail=false;
        for(int j=2;j*j<num&&!fail;j++)
            if(num%j==0)fail=true;
        if(fail)continue;
        printf("%d",num);
        return 0;
    }
    printf("404");
    return 0;
}
