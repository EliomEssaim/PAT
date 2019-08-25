#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
vector<string> List(101," ");
int main(){
    string a,b;
    int n,grade;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        scanf("%d",&grade);
        List[grade]=a+" "+b;
    }
    int start,end;bool flag=false;
    scanf("%d%d",&start,&end);
    for(int i=end;i>=start;i--)
    if(List[i]!=" "){
        cout<<List[i]<<endl;
        flag=true;
    }
    if(!flag) cout<<"NONE"<<endl;
    return 0;
}
