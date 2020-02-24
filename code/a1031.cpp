#include<iostream>
#include<vector>
#include<string>
using namespace std;
int col,row,cntFill=0,i=0,j=0;
string str;
int main(){
    cin>>str;
    for(row=1,col=(int)str.size()+2-2*row;row<=((int)str.size()-1)/2;row++){
        col=(int)str.size()+2-2*row;
        if(row>col)break;
    }
    row--;col=(int)str.size()+2-2*row;
    vector<vector<char>> display(row,vector<char>(col,' '));
    while(j<row)display[j++][i]=str[cntFill++];j--;i++;
    while(i<col)display[j][i++]=str[cntFill++];i--;j--;
    while(j>=0)display[j--][i]=str[cntFill++];
    for(int a=0;a<row;a++){
        for(int b=0;b<col;b++)
            printf("%c",display[a][b]);
        printf("\n");
    }
    return 0;
}
