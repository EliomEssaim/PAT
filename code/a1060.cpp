#include<iostream>
#include<cstdio>
#include<string>
#include <math.h>
#include<set>
#define eps 1e-8
using namespace std;
int delZeros(string &A)//ɾ��ǰ׺0ͬʱ��֤����ɾ��
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
void generateNewStr(string &A,int N)//���ʵ����ЧλΪN��ζ�A���� ʹ֮��ѧ������������0.�������
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
        if(A[0]=='0') tmp=0;//������С�����0
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
            if(i==A.size()-2) return 0;//���д�С�����0
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
//û�п��ǵ�ΪС������� һ��ʼ����ķ���ͷֲ�ȫ
//û�п��ǵ�ǰ׺Ϊ0�����
//0.����ת���ɷ�0.����
//���Ի��˺ܾ� ˼·�϶����� �ߵ��Ա���˼·Ч��̫��
//string�಻��Ϥ�������� ��ȡ��ΪN�ַ���ʱ �������Ҫ���һ��
//generateNewStr��һ��
