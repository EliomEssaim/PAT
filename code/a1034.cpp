#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#define MAXN 2010
using namespace std;
int G[MAXN][MAXN] = { 0 }; int n, k, numPerson = 0, cntClusters = 0;
int TotalTalkTime = 0, headID, headTalkTime = -1;
bool visit[MAXN] = { false };
bool EdgeVisit[MAXN][MAXN] = { false };
map<string, int> str2int;
map<int, string> int2str;
struct node {
	string head; int clusterNum;
	node(string _head, int _clusterNum) {
		head = _head; clusterNum = _clusterNum;
	}
};
vector<node> ans;
int getID(string s) {
	if (str2int.find(s) == str2int.end()) {
		str2int[s] = numPerson;
		int2str[numPerson] = s;
		numPerson++;
		int2str[numPerson] = s;
		return numPerson - 1;
	}
	else {
		return str2int[s];
	}
}
string getName(int ID) {
	return int2str[ID];
}
void DFS(int vertex) {
	int TalkTimeWithOthers = 0;
//	if (visit[vertex] == false) {递归冗余代码类：
		visit[vertex] = true;//因为要计算cntclusters
		cntClusters++;//怕重复所以又判断了一下 实际上没必要
//	}//递归的进入条件就是未被访问
	for (int i = 0; i < MAXN; i++) {
		if (G[vertex][i] != 0 && visit[i] == false)
			DFS(i);//顶点未被访问就DFS
		if (G[vertex][i] != 0) {
			if (EdgeVisit[vertex][i] == false) {
				EdgeVisit[vertex][i] = true;
				TotalTalkTime += G[vertex][i];
			}
			TalkTimeWithOthers += G[vertex][i];
		}
		if (G[i][vertex] != 0) {
			if (EdgeVisit[i][vertex] == false) {
				EdgeVisit[i][vertex] = true;
				TotalTalkTime += G[i][vertex];
			}
			TalkTimeWithOthers += G[i][vertex];
		}
		//TotalTalkTime += TalkTimeWithOthers;这句不该加
		//DFS中变量的累加问题
	}//totaltalktime应该是被定义为所有的边权之和，talktimewithothers应该是totaltalktime的子集，所以这里要加上去
	//totaltalktime是未被访问edge的累加，而talktimewithothers没有这个限制 所以+=后会造成重复
	//全局量和局部量的相加要考虑重合问题
	//变量是个瓶子 值是里面的水搞清楚有没有重复装水
	if (TalkTimeWithOthers > headTalkTime) {
		headTalkTime = TalkTimeWithOthers;
		headID = vertex;
	}
}
void DFSTravel() {
	for (int i = 0; i < MAXN; i++) {
		if (visit[i] == false) {
			DFS(i);
			if (TotalTalkTime > k && cntClusters>2)
				ans.push_back(node(getName(headID), cntClusters));
			headTalkTime = -1;
			TotalTalkTime = 0;
			cntClusters = 0;
		}
	}
}
bool cmp(node a, node b) {
	return a.head < b.head;
}
int main() {
	scanf("%d%d", &n, &k);
	string strA, strB; int weight;
	strA.resize(3); strB.resize(3);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", &strA[0], &strB[0], &weight);
		G[getID(strA)][getID(strB)] = weight;
	}
	DFSTravel();
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end(),cmp);
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%s %d\n", ans[i].head.c_str(), ans[i].clusterNum);
	}
	return 0;
}
//柳神的优秀思想：（数组的正确使用方法）
//我们需要的是每个clusters的head的ID，为了实现这个目的我们需要统计、
//TalkTimeWithOthers而这个不一定在DFS里面做
//由于所需要的参量有每个顶点的所有临边权和
//因为对于输入格式而言 输入的就是两个顶点之间的权和情况
//只要累加个个顶点的通话权和就可以很方便的计算出TalkTimeWithOthers

//map的奇妙使用方法：
//ans只要求键值是string和int类型
//map会把键值从小到大安排好
//所以使用map代替node作为ans的类型会使得
//我们不需要排序就可以得到结果
//记得不要用printf用cout！！不然用%s会得到乱码

//做个参考;
//晴神和柳神为了统计每个cluster的TotalTalkTime
//在访问了边之后就把他清0，免去了设置visitedEdge的麻烦
//如果不想设置visit而且在后续的工作中不用用到这个节点可以
//想办法让这个变量失效 不进入if语句内

//做个参考：
//柳神在统计数据时（如TotalTalkTime—）时把这玩意当成一个
//输入参数传入引用
//实际上就是利用输入参数来实现传输返回值
//这样可以不用设置全局变量
//也不需要在出来连通分量后对全局变量进行清0
//只需要给个变量让他传入即可
