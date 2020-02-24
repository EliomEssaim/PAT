#include<iostream>
using namespace std;
int main(){
    int T,k,n1,b,t,n2;
    cin>>T>>k;
    for(int i=0;i<k;i++){
        cin>>n1>>b>>t>>n2;
        if(t>T){
            printf("Not enough tokens.  Total = %d.\n",T);
            continue;
        }
        if((n1>n2&&b==0)||(n1<n2&&b==1)){
            T+=t;
            printf("Win %d!  Total = %d.\n",t,T);
        }else{
            T-=t;
            printf("Lose %d.  Total = %d.\n",t,T);
            if(T<=0){
                cout<<"Game Over."<<endl;
                return 0;
            }
        }
    }
    return 0;
}
