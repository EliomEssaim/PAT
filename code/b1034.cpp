#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
long long gcd(long long a,long long b)
{
    return a%b==0?b:gcd(b,a%b);
}
void func(long long a,long long b)
{
    if(b==0) {printf("Inf");return;}
    if(a==0) {printf("0");return;}
    bool flag=false;
    if((a>0&&b<0)||(a<0&&b>0)) {printf("(-");flag=true;}
    a=abs(a);b=abs(b);

    long long k=a/b;
    if(k!=0) {printf("%lld",k);a=a%b;}

    int gcd_ab=gcd(a,b);
    a/=gcd_ab;b/=gcd_ab;

    if(b!=1&&k!=0) printf(" %lld/%lld",a,b);
    else if(b!=1)printf("%lld/%lld",a,b);

    if(flag) printf(")");
    return;
}
int main()
{
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    func(a1,b1);printf(" + ");func(a2,b2);printf(" = ");func(a1*b2+a2*b1,b1*b2);printf("\n");
    func(a1,b1);printf(" - ");func(a2,b2);printf(" = ");func(a1*b2-a2*b1,b1*b2);printf("\n");
    func(a1,b1);printf(" * ");func(a2,b2);printf(" = ");func(a1*a2,b1*b2);printf("\n");
    func(a1,b1);printf(" / ");func(a2,b2);printf(" = ");func(a1*b2,b1*a2);printf("\n");
    return 0;
}
