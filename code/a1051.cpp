#include<iostream>
#include<stack>
using namespace std;
int m,n,k,tmp,unit;
bool fake=false;
int main(){
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        stack<int> ss;
        ss.push(0);
        fake=false;
        unit=1;
        for(int j=1;j<=n;j++){
            scanf("%d",&tmp);
            if(fake)continue;
            if(tmp>ss.top()){
                while(ss.top()!=tmp&&unit<=n)
                    ss.push(unit++);
                if((int)ss.size()>m+1)fake=true;
                else ss.pop();
            }else{
                if(ss.top()==0||ss.top()!=tmp)fake=true;
                else ss.pop();
            }
        }
        printf("%s\n",fake?"NO":"YES");
    }
    return 0;
}
