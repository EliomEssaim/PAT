#include<iostream>
#include<iomanip>
using namespace std;
int m,n,a,b,replaceValue,tmpDegree;
int main(){
    scanf("%d%d%d%d%d",&m,&n,&a,&b,&replaceValue);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&tmpDegree);
            if(tmpDegree>=a&&tmpDegree<=b)tmpDegree=replaceValue;
            if(j!=0)printf(" ");
            printf("%03d",tmpDegree);
        }
        printf("\n");
    }
    return 0;
}
