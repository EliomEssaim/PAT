#include<iostream>
#include<string>
using namespace std;
int level,nodes,max_lenth,lenth;
char symbol;
int main(){
    while(1){
        cin>>nodes>>symbol;
        int t_sum=1,t_sum_next=t_sum;
        level=2;int lenth_next=1;
        while(t_sum_next<=nodes){
            t_sum=t_sum_next;lenth=lenth_next;
            lenth_next=2*level-1;
            t_sum_next+=lenth_next*2;
            level++;
            }
        max_lenth=lenth;
        int space;
        for(space=0;lenth>=1;lenth-=2,space++){
            for(int i=0;i<space;i++) cout<<" ";
            for(int i=0;i<lenth;i++) cout<<symbol;
            cout<<endl;
        }
        for(space-=2,lenth+=4;lenth<=max_lenth;lenth+=2,space--){//这里出现了偏差
            for(int i=0;i<space;i++) cout<<" ";
            for(int i=0;i<lenth;i++) cout<<symbol;
            cout<<endl;
        }
        cout<<nodes-t_sum<<endl;
    }
    return 0;
}
