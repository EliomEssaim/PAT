#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int m,n,l,t,ans=0;
bool visit[80][1300][130]={false};
bool slice[80][1300][130]={false};
int x[6]={1,0,0,-1,0,0};
int y[6]={0,1,0,0,-1,0};
int z[6]={0,0,1,0,0,-1};
struct node{
    int x,y,z;
};
bool judge(int x,int y,int z){
    if(x<0||x>=l||y<0||y>m||z<0||z>n) return false;
    if(visit[x][y][z]==true||slice[x][y][z]==false) {
        visit[x][y][z]=true;return false;//visit置位时间不对
    }else visit[x][y][z]=true;
    return true;
}
void bfs(int tx,int ty,int tz){
    queue<node> q;//保存一组数？结构体 数组
    q.push(node{tx,ty,tz});
    int cnt=1;
    visit[tx][ty][tz]=true;
    while(!q.empty()){
        node elmtFront=q.front();
        q.pop();
        int tmx,tmy,tmz;
        for(int i=0;i<6;i++){
            tmx=elmtFront.x+x[i];
            tmy=elmtFront.y+y[i];
            tmz=elmtFront.z+z[i];
            if(judge(tmx,tmy,tmz)){
                q.push(node{tmx,tmy,tmz});
                cnt++;
            }
        }
    }
    if(cnt>=t) ans+=cnt;
}
int main(){
    int tmp;
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int i=0;i<l;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++){
                scanf("%d",&tmp);
                if(tmp)slice[i][j][k]=true;
            }

    for(int i=0;i<l;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++)
                if(visit[i][j][k]==false&&slice[i][j][k]==true)
                    bfs(i,j,k);
    cout<<ans;
    return 0;
}
