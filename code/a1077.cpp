#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string tmpGet,suffix;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        getline(cin,tmpGet);
        reverse(tmpGet.begin(),tmpGet.end());
        if(i==0){
            suffix=tmpGet;
        }else{
            int lenSuffix=suffix.length();
            int lenTmpGet=tmpGet.length();
            int minlen=min(lenSuffix,lenTmpGet);
            for(int i=0;i<minlen;i++){
                if(suffix[i]!=tmpGet[i]){
                    suffix=suffix.substr(0,i);
                    break;
                }
            }
        }
    }
    reverse(suffix.begin(),suffix.end());
    if(suffix.length()) cout<<suffix<<endl;
    else cout<<"nai"<<endl;
    return 0;
}
//�벻����ôȡС��׺
//�������
//��ת�ȽϺ���Ч����ȡ�ַ���
//substring���÷�Ҫ�μ�
