#include<iostream>
#include<cstdio>
#include<string>
#include <math.h>
#include<set>
#define eps 1e-8
using namespace std;
int delZeros(string &A)//删除前缀0同时保证不会删完
{
    int cnt=0;
    while(A[0]=='0')
    {
        if(A.size()==1) break;
        if(A.size()>=2&&A[1]=='.') break;
        A.erase(0,1);
        cnt++;
    }
    return cnt;
}
void generateNewStr(string &A,int N)//如何实现有效位为N如何对A操作 使之科学计数（不考虑0.的情况）
{
    if(A.size()>=N)
            A=A.substr(0,N);
    else{
            for(int i=A.size();i<N;i++)
                A.insert(i,"0");
        }
        A.insert(0,"0.");
    return;
}
int converStr(string &A,int N)
{
    delZeros(A);
    int dotPos=A.find(".");
    if(dotPos==string::npos)
    {
        delZeros(A);
        int tmp=A.size();
        if(A[0]=='0') tmp=0;//特判无小数点的0
        dotPos=N;
        generateNewStr(A,N);
        return tmp;
    }
    else
    {
        delZeros(A);
        if(A[0]!='0')
        {
            A.erase(dotPos,1);
            generateNewStr(A,N);
            return dotPos;
        }
       else
        {
            delZeros(A);
            int cnt=0;
            dotPos=A.find(".");
            A.erase(dotPos,1);
            cnt=delZeros(A);
            generateNewStr(A,N);
            int i;
            for(i=2;i<A.size()-2;i++)
                if(A[i]!='0') break;
            if(i==A.size()-2) return 0;//特判带小数点的0
            return -cnt+1;
        }
    }

}

int main()
{
    string A,B;
    int N;
    scanf("%d",&N);
    cin>>A>>B;

    int kA=converStr(A,N);
    int kB=converStr(B,N);
    if(A!=B) {
        printf("NO ");
        cout<<A<<"*10^"<<kA<<" ";
        cout<<B<<"*10^"<<kB<<endl;
    }
    else {printf("YES ");cout<<A<<"*10^"<<kA<<endl;}
    return 0;
}
//没有考虑到为小数的情况 一开始输入的分类就分不全
//没有考虑到前缀为0的情况
//0.可以转换成非0.处理
//调试花了很久 思路断断续续 边调试边想思路效率太低
//string类不熟悉函数功能 截取长为N字符串时 输入参数要想好一会
//generateNewStr看一下
