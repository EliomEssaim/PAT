#include<iostream>
#include<string>
using namespace std;
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    bool second=false;
    for(int i=0;i<(int)str1.size()&&i<(int)str2.size();i++)
        if(!second&&str1[i]==str2[i]&&isupper(str1[i])&&str1[i]>='A'&&str1[i]<='G'){
            printf("%s ",week[str1[i]-'A'].c_str());
            second=true;
        }else if(second&&str1[i]==str2[i]&&(str1[i]>='A'&&str1[i]<='N'||isdigit(str1[i]))){
            printf("%02d:",isdigit(str1[i])?str1[i]-'0':str1[i]-'A'+10);
            break;
        }
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<(int)str1.size()&&i<(int)str2.size();i++)
        if(str1[i]==str2[i]&&isalpha(str1[i])){
            printf("%02d",i);
            break;
        }
    return 0;
}
