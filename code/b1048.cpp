#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string Astr,Bstr,ans;
vector<string> trans={"0","1","2","3","4","5","6","7","8","9","J","Q","K"};
int main(){
    stringstream s;
    cin>>Astr>>Bstr;int i,index;
    reverse(Astr.begin(),Astr.end());
    reverse(Bstr.begin(),Bstr.end());
    Astr.size()>Bstr.size()?Bstr.append(Astr.size()-Bstr.size(),'0'):Astr.append(Bstr.size()-Astr.size(),'0');
    for(i=0;i<(int)Bstr.size();i++){
        if((i+1)%2==1)index=(Astr[i]-'0'+Bstr[i]-'0')%13;
        else index=(Bstr[i]-Astr[i])>=0?(Bstr[i]-Astr[i]):(Bstr[i]-Astr[i]+10);
        ans+=trans[index];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
