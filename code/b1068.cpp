#include<iostream>
#include<map>
using namespace std;
int picture[1000][1000];
bool unValidPos[1000][1000]={0};
map<int,int> mapp;
int m,n,TOL,last,tmp,cntValid=0,ansI=0,ansJ=0;
bool check(int &a,int &b){
    for(int i=-1;i<2;i+=2)
        for(int j=-1;j<2;j++)
            if(a+i>=0&&a+i<n&&b+j>=0&&b+j<m&&abs(picture[a][b]-picture[a+i][b+j])<=TOL)
                return false;
    return true;
}
int main(){
    scanf("%d%d%d",&m,&n,&TOL);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tmp);
            picture[i][j]=tmp;
            if(j==0)last=-400;
            if(abs(last-tmp)<=TOL&&!unValidPos[i][j]){
                unValidPos[i][j]=true;
                if(j-1>=0)unValidPos[i][j-1]=true;
            }
            last=tmp;mapp[tmp]++;
        }
    }
    for(int i=0;i<n&&cntValid<=2;i++){
        for(int j=0;j<m&&cntValid<=2;j++){
            if(mapp[picture[i][j]]==1&&!unValidPos[i][j]&&check(i,j)){
                ansI=i+1;ansJ=j+1;
                cntValid++;
            }
        }
    }
    if(cntValid==0)cout<<"Not Exist"<<endl;
    else if(cntValid>1)cout<<"Not Unique"<<endl;
    else  printf("(%d, %d): %d\n",ansJ,ansI,picture[ansI-1][ansJ-1]);

    return 0;
}
