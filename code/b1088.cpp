#include<iostream>
#include<iostream>
#include<vector>
using namespace std;
vector<string> str={" Cong"," Ping"," Gai"};
int cmp(double a,double b){
    if(a<b)return 0;
    else if(a==b)return 1;
    else return 2;
}
int main(){
    int a,b,x,y,my,jia,yi;
    double bing;
    cin>>my>>x>>y;
    for(a=9;a>=0;a--)
        for(b=9;b>=0;b--)
        if(a!=0||b!=0){
            jia=a*10+b;yi=b*10+a;
            bing=1.0*abs(jia-yi)/(float)x;
            if(yi==y*bing){
                cout<<jia;cout<<str[cmp(my,jia)];
                cout<<str[cmp(my,yi)]<<str  [cmp(my,bing)];
                return 0;
            }
        }
    cout<<"No Solution"<<endl;
    return 0;
}
