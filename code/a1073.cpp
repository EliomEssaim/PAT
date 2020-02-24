#include<iostream>
#include<string>
using namespace std;
string num,fraction,expon,virgin,ans;
int exponNum;
int main(){
    getline(cin,virgin);
    if(virgin[0]=='-')printf("-");
    virgin=virgin.substr(1);
    num=virgin.substr(0,1);
    fraction=virgin.substr(2,virgin.find("E")-2);
    expon=virgin.substr(virgin.find("E")+1);
    exponNum=stoi(expon);
    if(exponNum<0){
        ans=num+fraction;
        for(int i=abs(exponNum);i>0;i--)ans.insert(0,"0");
        ans.insert(1,".");
        cout<<ans;
        return 0;
    }else{
        printf("%s",num.c_str());
        int i=0;
        for(;i<exponNum&&i<(int)fraction.size();i++)
            printf("%c",fraction[i]);
        if(i==(int)fraction.size())
            for(;i<exponNum;i++)printf("0");
        else{
            printf(".");
            for(;i<(int)fraction.size();i++)printf("%c",fraction[i]);
        }
    }
    return 0;
}
