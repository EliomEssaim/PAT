#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int add,value,next;
};
vector<node> List(100010);
vector<node> result_order;
int main(){
    int ori_add,n,rever_unit,lenth=0;
    cin>>ori_add>>n>>rever_unit;
    int t_add,t_value,t_next;
    for(int i=0;i<n;i++){
        cin>>t_add>>t_value>>t_next;
        List[t_add].add=t_add;
        List[t_add].value=t_value;
        List[t_add].next=t_next;
    }
    t_add=ori_add;t_next=-1;
    while(t_add!=-1){
        t_value=List[t_add].value;
        t_next=List[t_add].next;
        result_order.push_back(node{t_add,t_value,-1});
        t_add=t_next;
    }
    lenth=result_order.size();
    for(int i=rever_unit;i<=(int)result_order.size();i+=rever_unit)
        reverse(result_order.begin()+i-rever_unit,result_order.begin()+i);
    for(int i=0;i<lenth-1;i++)
            printf("%05d %d %05d\n",result_order[i].add,result_order[i].value,result_order[i+1].add);
    printf("%05d %d -1\n",result_order[lenth-1].add,result_order[lenth-1].value);
    return 0;
}
