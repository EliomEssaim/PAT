#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct DATA {
	int id, fid, mid, estate, area, members = 0;
};
struct node {
	int id, TotalMembers;
	double avrEstate, avrArea;
	bool isExist = false;
}ans[10010];
int father[10010];
bool visit[10010] = { false };
int findFather(int x) {
	int fa = x;
	while (fa != father[fa]) fa = father[fa];
	int upfa = x;
	while (upfa != father[upfa]) {
		upfa = father[upfa];
		father[x] = fa;
		x = upfa;
	}
	return fa;
}
void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa > fb) father[fa] = fb;//敲黑板！！
	if (fa < fb) father[fb] = fa;
}
bool cmp(node a, node b) {
	return a.avrArea != b.avrArea ? a.avrArea > b.avrArea:a.id < b.id;
}
int main() {
	int n, k, childID;
	vector<DATA> Data;
	scanf("%d", &n);
	for (int i = 0; i < 10010; i++)
		father[i] = i;
	Data.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &Data[i].id, &Data[i].fid, &Data[i].mid, &k);
		if (visit[Data[i].id] == false){
			Data[i].members++; visit[Data[i].id] = true;
		};
		//柳神的data不是用id做索引而是以下标为索引！！体会一下
		if (Data[i].fid != -1) {
			Union(Data[i].id, Data[i].fid);
			if (visit[Data[i].fid] == false){
				Data[i].members++; visit[Data[i].fid] = true;
			};
			//会重复计算！！没有想到
		}
		if (Data[i].mid != -1) {
			Union(Data[i].id, Data[i].mid);
			if (visit[Data[i].mid] == false){
				Data[i].members++; visit[Data[i].mid] = true;
			};
		}
		for (int j = 0; j < k; j++) {
			scanf("%d", &childID);
			Union(Data[i].id, childID);
			if (visit[childID] == false){
				Data[i].members++; visit[childID] = true;
			};
		}
		scanf("%d%d", &Data[i].estate, &Data[i].area);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		ans[findFather(Data[i].id)].id = findFather(Data[i].id);
		ans[findFather(Data[i].id)].TotalMembers += Data[i].members;
		ans[findFather(Data[i].id)].avrArea += Data[i].area;
		ans[findFather(Data[i].id)].avrEstate += Data[i].estate;
		ans[findFather(Data[i].id)].isExist = true;
	}
	for (int i = 0; i < 10010; i++) {
		if (ans[i].isExist == true) {
			cnt++;
			ans[i].avrArea = (double)ans[i].avrArea / (double)ans[i].TotalMembers;
			ans[i].avrEstate = (double)ans[i].avrEstate / (double)ans[i].TotalMembers;
		}
	}
	sort(ans, ans + 10010, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].TotalMembers, \
			ans[i].avrEstate, ans[i].avrArea);
	return 0;
}

//我所遇到的问题：
/*
1.如何实现集合的表示？以及如何让有交集的集合合并？
还有如何让集合和其他信息房产挂钩？
使用并查集：难以实现交集则合并且根唯一
思路是先合并一组数据 然后判断这个家族是否有成员是其他
（判断有没有父亲再合并这个方法真的蠢爆了）
（因为father仅仅是第一个不具有什么特征，所以担心father会改来改去 同一集合）
集合的一部分（写个flag） 如果是则和那个集合合并

*/
/*
用数组分割功能
*/
