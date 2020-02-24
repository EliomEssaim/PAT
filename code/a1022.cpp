#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,vector<int>> title,author,keywords,publisher,year;
vector<map<string,vector<int>>> searchNum={title,author,keywords,publisher,year};
int main(){
    int n,id,m,order;
    scanf("%d",&n);
    string str;
    for(int i=0;i<n;i++){
        scanf("%d",&id);
        while(getchar()!='\n');
        for(int j=0;j<5;j++){
            getline(cin,str);
            if(j!=2)searchNum[j][str].push_back(id);
            else{
                 str+=" ";
                for(int i=0,last=0;i<(int)str.size();i++)
                if(str[i]==' '){
                    searchNum[j][str.substr(last,i-last)].push_back(id);
                    last=i+1;
                }
            }
        }
    }
    for(auto &kinds:searchNum)
        for(auto &mapUnit:kinds)
            sort(mapUnit.second.begin(),mapUnit.second.end());
    scanf("%d",&m);
    while(getchar()!='\n');
    for(int i=0;i<m;i++){
        getline(cin,str);
        printf("%s\n",str.c_str());
        order=str[0]-'0';
        order--;
        str=str.substr(3);
        if(searchNum[order].count(str)!=0)
            for(auto &unit:searchNum[order][str])
                printf("%07d\n",unit);
        else printf("Not Found\n");
    }
    return 0;
}
