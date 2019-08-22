#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct appliant {
	int id, Ge, Gi, rank;
	int score;
	vector<int> choice;
};
vector<appliant> appList;
struct school {
	int quota, lastRank;
	vector<int> enrollList;
};
vector<school> university;
int n, m, k;
bool cmp(appliant &a, appliant &b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.Ge > b.Ge;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	appList.resize(n);
	university.resize(m);
	for (int i = 0; i < n; i++) {
		appList[i].id = i; appList[i].choice.resize(k);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &university[i].quota);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &appList[i].Ge, &appList[i].Gi);
		appList[i].score = appList[i].Ge + appList[i].Gi;
		for (int j = 0; j < k; j++)
			scanf("%d", &appList[i].choice[j]);
	}
	sort(appList.begin(), appList.end(), cmp);
	for (int i = 0; i < n; i++) {
		appList[i].rank = i;
		if (i != 0) {
			int preScore = appList[i - 1].score;
			int nextScore = appList[i].score;
			if (preScore == nextScore && appList[i].Ge == appList[i - 1].Ge)
				appList[i].rank = appList[i - 1].rank;
		}
	}
	for (int i = 0; i < n; i++) {//有磕绊
		for (int j = 0; j < k; j++) {
			int target = appList[i].choice[j];
			int stu = appList[i].id;
			int size = university[target].enrollList.size();
			if (university[target].quota > 0) {
				university[target].enrollList.push_back(stu);
				university[target].lastRank = appList[i].rank;//i不代表真实的rank
				university[target].quota--;
				break;
			}
			else if (size != 0 && appList[i].rank == university[target].lastRank) {
				university[target].enrollList.push_back(stu);
				break;
			}//logical failure
		}
	}
	for (int i = 0; i < m; i++) {
		sort(university[i].enrollList.begin(), university[i].enrollList.end());
		for (int j = 0; j < (int)university[i].enrollList.size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", university[i].enrollList[j]);
		}
		printf("\n");
	}
	return 0;
}
//不够快
//不用除以二
//？又要排错了...............
//fatal error
/****把i当成rank使用了****/
/*
当与柳神的思路相差过大的时候怎么排错
字母级观察：确定怀疑对象 这个量有没有赋值正确 是不是这个量？
怀疑逻辑错误：看别人的思路改写自己的代码
*/

/*等效是种好思想
用float麻烦时就考虑一下有没有等效的做法 不用求平均
*/

/*
不够快：
将任务模块化 首先 想好大体思路 决定数据结构
到具体某个模块的编写时 先想好思路再动手
*/
