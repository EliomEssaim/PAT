#include<iostream>
#include<vector>
using namespace std;
vector<bool> isExist(1000),isCover(1000);
bool firstOut=true;
int main(){
    int n,addr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>addr;
        isExist[addr]=true;
        if(!isCover[addr])addr=addr%2==0?addr/2:(addr*3+1)/2;//ʵ�ֳ��˱������µ�ֵ��cover����������һ��coverֵ����ֱ������
        while(!isCover[addr]&&addr!=1){//������ܳ��ֶ�ε�addr*3+1�������
            isCover[addr]=true;//����ж�������������ѭ�������� ��ô�����ڱ仯ǰд�ϣ��ж������ı仯������ѭ����ֱ���жϵ�
            addr=addr%2==0?addr/2:(addr*3+1)/2;
        }
    }
    for(int i=100;i>0;i--)
        if(isExist[i]&&!isCover[i]){
            if(!firstOut)cout<<" ";
            cout<<i;firstOut=false;
        }
    return 0;
}
