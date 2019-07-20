#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXV=1010;
vector<int> Adj[MAXV];int N,L,ansIndex=0;
vector<int> ans;
void BFS(int poster){
    bool OnceInQueue[MAXV]={false};
    queue<int> q;int level=0,levelEnd;
    q.push(poster);
    levelEnd=poster;
    OnceInQueue[poster]=true;
    while(!q.empty()){
        int frontElment=q.front();
        q.pop();
        for(int i=0;i<(int)Adj[frontElment].size()&&level<L;i++){
            if(OnceInQueue[Adj[frontElment][i]]==false){
                q.push(Adj[frontElment][i]);
                OnceInQueue[Adj[frontElment][i]]=true;
                ans[ansIndex]++;
            }
        }
        if(frontElment==levelEnd){
            level++;
            levelEnd=q.back();
        }
    }
}
int main(){
    int userListI,FollowedBy;
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;i++){
        scanf("%d",&userListI);
        for(int j=0;j<userListI;j++){
            scanf("%d",&FollowedBy);
            Adj[FollowedBy].push_back(i);
        }
    }
    int TestCasesNum;vector<int> TestCases;
    scanf("%d",&TestCasesNum);
    TestCases.resize(TestCasesNum);ans.resize(TestCasesNum);
    for(int i=0;i<TestCasesNum;i++){
        scanf("%d",&TestCases[i]);
        BFS(TestCases[i]);
        ansIndex++;
    }
    for(int i=0;i<(int)ans.size();i++)
    printf("%d\n",ans[i]);
    return 0;
}
//��һ��codeʧ��

//level���ж�ʧ��Ӧ����<
//level ���жϴ���ĺ�����¾����ͺ�������
//Ӧ���� < ʹ���ͺ�ֵ ����ִ���ͺ�+1�Ĳ���

//levelд����
//1��level���ǽ���һ��for�ͼ�һ�㣨�Ը��ڵ��������ģ�
//���Ƕ��ڷǸ��ڵ� ������������ ���ڵ���ж���ӽڵ�
//�ӽڵ����п��������ӽڵ㣬���ӽڵ����ʱ���ᵼ��level++
//��ʱ�Ѿ����뱾��
//2��BFS�ǲ������ ����for������һ��for������ӽڵ���������
//ĳ��������for��BFS whileѭ���е�forѭ������dfs
//����˵��for�ı���������DFS

//ȷ������ level �İ취
//1������levelend����levelendʱlevel++(��������
//2������node ����layer ����һ�ξͰ�layer+1
