#include<iostream>
#include<vector>
#include<algorithm>
#define codea 1
#define codeb 1
#define codec 1
#define codec1 0
using namespace std;
vector<int> father,course,isRoot;
#if codea
int findFather(int key){
    int fa=key;
    while(fa!=father[fa]) fa=father[fa];
    int upfa=key;
    while(upfa!=fa){
        upfa=father[fa];
        father[key]=fa;
        key=upfa;
    }
    return fa;
}
void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb) father[fa]=b;//这里是fa而不是a要最终结果
}
#endif // codea
#if !codea
int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}
#endif // codea

bool cmp1(int a,int b){
    return a>b;
}
int main(){
    #if codeb
    int n,k,t,cnt=0;
    scanf("%d",&n);
    father.resize(n+1);
    for(int i=0;i<=n;i++)
        father[i]=i;
    course.resize(1010);
    isRoot.resize(1010);
    fill(course.begin(),course.end(),0);
    for(int i=1;i<=n;i++){
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&t);
            if(course[t]==0){
                 course[t]=i;
//这里不该填用来确定root位置 因为第一个hobby可能是新的hobby但不一定是新的root
            }
            Union(i,findFather(course[t]));
        }
    }
    #endif // codec
    #if !codeb
    int n, k, t, cnt = 0;
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    #endif
    #if codec
    for(int i=1;i<=n;i++)
        findFather(i);
    for(int i=1;i<=n;i++){
        if(father[i]==i) cnt++;
        isRoot[father[i]]++;
//这里是findfather而不是father
//如果出现两个小组合成一个大组就会出现
//路径不完全压缩的情况！！！
    }
    printf("%d\n",cnt);
    sort(isRoot.begin(),isRoot.end(),cmp1);
    #endif // codec
    #if !codec
    for (int i = 1; i <= n; i++)
		isRoot[findFather(i)]++;
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0) cnt++;
	}
	printf("%d\n", cnt);
	sort(isRoot.begin(), isRoot.end(), cmp1);
    #endif
    #if codec1
    cnt--;
    for(int i=0;isRoot[i]!=0;i++){
        printf("%d",isRoot[i]);
        if(cnt--) printf(" ");
    }
    #endif // codec1


	#if !codec1
	for (int i = 0; i < cnt; i++) {
		printf("%d", isRoot[i]);
		if (i != cnt - 1) printf(" ");
	}
	#endif // codec1

    return 0;
}
