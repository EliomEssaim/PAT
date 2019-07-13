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
	if (fa > fb) father[fa] = fb;//�úڰ壡��
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
		//�����data������id�������������±�Ϊ�����������һ��
		if (Data[i].fid != -1) {
			Union(Data[i].id, Data[i].fid);
			if (visit[Data[i].fid] == false){
				Data[i].members++; visit[Data[i].fid] = true;
			};
			//���ظ����㣡��û���뵽
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

//�������������⣺
/*
1.���ʵ�ּ��ϵı�ʾ���Լ�������н����ļ��Ϻϲ���
��������ü��Ϻ�������Ϣ�����ҹ���
ʹ�ò��鼯������ʵ�ֽ�����ϲ��Ҹ�Ψһ
˼·���Ⱥϲ�һ������ Ȼ���ж���������Ƿ��г�Ա������
���ж���û�и����ٺϲ����������Ĵ����ˣ�
����Ϊfather�����ǵ�һ��������ʲô���������Ե���father�������ȥ ͬһ���ϣ�
���ϵ�һ���֣�д��flag�� ���������Ǹ����Ϻϲ�

*/
/*
������ָ��
*/
