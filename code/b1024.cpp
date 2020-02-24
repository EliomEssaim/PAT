#include<iostream>
#include<string>
using namespace std;
bool conponent_flag=true,dot_useless=false;
string results;
int E_pos,conponents,dot_pos;
int main(){
    string ori_str;
    cin>>ori_str;
    E_pos=ori_str.find('E');
    if(ori_str[0]=='-') cout<<"-";
    if(ori_str[E_pos+1]=='-') conponent_flag=false;
    results=ori_str.substr(1,E_pos-1);
    conponents=stoi(ori_str.substr(E_pos+2,(int)ori_str.size()-E_pos-2));
    dot_pos=results.find('.');
    if(conponents==0){
        cout<<results;
        return 0;
    }
    if(conponent_flag){
        int conponents_left=conponents;
        int ori_result_lenth=results.size();
        while(conponents_left>0){
            results+="0";
            conponents_left--;
        }
        conponents_left=conponents;
        results.insert(dot_pos+conponents_left,".");
        results.erase(dot_pos,1);
        if(ori_result_lenth-2>conponents)
            results=results.substr(0,ori_result_lenth);
        else{
            dot_pos=results.find('.');
            results.erase(dot_pos,1);
            results=results.substr(0,1+conponents);
        }

    }else{
        results.erase(dot_pos,1);
        int conponents_left=conponents;
        while(conponents_left>0){
            results.insert(0,"0");
            conponents_left--;
        }
        results.insert(1,".");
    }
    cout<<results;
    return 0;
}



