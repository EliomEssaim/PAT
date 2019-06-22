#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
map<string,int> st2int;
map<char,int> NumSt2num;
int main()
{
    string strLow[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string strHigh[13]={"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    for(int i=0;i<13;i++) st2int[strLow[i]]=i;
    for(int i=0;i<13;i++) st2int[strHigh[i]]=i*13;
    for(int i=0;i<10;i++) NumSt2num[(char)('0'+i)]=i;
    int n;
    string Language;
    scanf("%d",&n);
     getchar();
    int dec=0;
    while(n--)
    {
        dec=0;
        getline(cin,Language);
        if(Language[0]>='0'&&Language[0]<='9')
        {
            for(int i=0,p=1;i<Language.size();i++,p*=10)
                dec+=NumSt2num[Language[Language.size()-1-i]]*p;
            if(dec<13) cout<<strLow[dec%13]<<endl;
            else
            {
                cout<<strHigh[(dec/13)%13];
                if(strLow[dec%13]!="tret")cout<<" "<<strLow[dec%13]<<endl;
                else cout<<endl;
            }
        }
        else
        {
            int length=Language.size();
            if(length<4)
                cout<<st2int[Language]<<endl;
            else
            {
                string font=Language.substr(0,3);
                string latter=Language.substr(4,3);
                dec+=st2int[latter];
                dec+=st2int[font];
                cout<<dec<<endl;
            }

        }

    }

    return 0;
}
/*
1.提供几个特殊的测试点
tret tret
39
26
0
tret
对应的输出应该为
0
maa
hel
tret
0
火星人的0就是0
30后边的0他们不表示
*/
