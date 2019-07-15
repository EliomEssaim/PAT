#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> initSeq,PartSeq;
void downAdjust(int low,int high){
    int faPos=low,childPos=2*low;
    while(childPos<=high){
        if(childPos+1<=high&&PartSeq[childPos+1]>PartSeq[childPos])
            childPos++;
        if(PartSeq[faPos]<PartSeq[childPos]){
            swap(PartSeq[faPos],PartSeq[childPos]);
            faPos=childPos;
            childPos=faPos*2;
        }
        else break;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    initSeq.resize(n+1);PartSeq.resize(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&initSeq[i]);
    for(int i=1;i<=n;i++) scanf("%d",&PartSeq[i]);
    int OrderedEnd=2;
    while(OrderedEnd<=n&&PartSeq[OrderedEnd]>=PartSeq[OrderedEnd-1]) OrderedEnd++;
    //这里没有填 OrderedEnd<=n
    int i=OrderedEnd;
    while(i<=n&&initSeq[i]==PartSeq[i]) {i++;}
    //没有填上i的终止边界
    if(i==n+1){
        printf("Insertion Sort\n");
        sort(PartSeq.begin()+1,PartSeq.begin()+OrderedEnd+1);
    }else{
        printf("Heap Sort\n");
        int unOrderPos=n;
        while(PartSeq[unOrderPos]>=PartSeq[1]) unOrderPos--;
        swap(PartSeq[1],PartSeq[unOrderPos]);//忘记写了 这里要交换下面要-1
        downAdjust(1,unOrderPos-1);
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",PartSeq[i],i==n?'\n':' ');
    return 0;
}
//如何鉴别插入排序
//如何寻找heap从哪里开始排序
