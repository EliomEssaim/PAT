#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define elementType long int
elementType gcd(elementType a,elementType b){
    return a%b==0?b:gcd(b,a%b);
}
elementType maxAmplify(elementType a,elementType b){
    return a/gcd(a,b)*b;//负数有效
}
int main(){
    int n;vector<elementType> num,den;
    scanf("%d",&n);
    num.resize(n);den.resize(n);
    getchar();
    for(int i=0;i<n;i++) {
        scanf("%lld/%lld",&num[i],&den[i]);
        int gc=gcd(num[i],den[i]);
        num[i]/=gc;den[i]/=gc;
    }
    int sumNum=num[0],sumDen=den[0];
    for(int i=1;i<n;i++){
        int maxAm=maxAmplify(sumDen,den[i]);
        int preAm=maxAm/sumDen,nextAm=maxAm/den[i];
        sumNum=sumNum*preAm+num[i]*nextAm;
        sumDen=maxAm;
        int gc=gcd(sumNum,sumDen);
        sumNum/=gc;sumDen/=gc;
    }
    int sumOfnum=sumNum,denMaxAm=sumDen;
    elementType intergePart=sumOfnum/denMaxAm;
    if(intergePart==0&&sumOfnum!=0)
        printf("%lld/%lld",sumOfnum,denMaxAm);
    else if(intergePart==0&&sumOfnum==0)
        printf("%d",0);
    else if(denMaxAm==1)
        printf("%lld",intergePart);
    else
        printf("%lld %lld/%lld",intergePart,sumOfnum%denMaxAm,denMaxAm);
    return 0;
}
//忽视warning lld codeblocks的lld很辣鸡
//小知识：
/*
分数相加的时候 两两相加的时候所用的位数最小
分数要考虑假分数 0 等特殊情况
输出考虑 0 无穷 纯整数 假分数 真分数
多组数相加的时候两两相加再化简
gcd对负数也有用
*/
//没有考虑最长的长度
//特殊情况 没有考虑为0 没有想到最防止过长的完美处理
/*
审题的时候考虑这些数字类的特殊情况
*/

