#include<iostream>
#include<string>
using namespace std;
int main(){
    string A,DA,B,DB;
    cin>>A>>DA>>B>>DB;
    auto tmp=A.begin();
    while(!A.empty()&&tmp!=A.end())//巡航导弹式去点 没有想到这里会出麻烦
        if(*tmp!=*DA.begin()){
            A.erase(tmp);
            tmp=A.begin();
        }else tmp++;
    tmp=B.begin();
    while(!B.empty()&&tmp!=B.end())
        if(*tmp!=*DB.begin()){
            B.erase(tmp);
            tmp=B.begin();
        }else tmp++;
    if(A.empty()) A="0";if(B.empty())B="0";
    printf("%d",stoi(A)+stoi(B));
    return 0;

}
/*



    string a;
    cin>>a;
    string b="j";
    auto tmp=a.begin();
    if(*tmp==*b.begin())
    cout<<*tmp<<endl;
*/
