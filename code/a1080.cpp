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
	for (int i = 0; i < n; i++) {//�пİ�
		for (int j = 0; j < k; j++) {
			int target = appList[i].choice[j];
			int stu = appList[i].id;
			int size = university[target].enrollList.size();
			if (university[target].quota > 0) {
				university[target].enrollList.push_back(stu);
				university[target].lastRank = appList[i].rank;//i��������ʵ��rank
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
//������
//���ó��Զ�
//����Ҫ�Ŵ���...............
//fatal error
/****��i����rankʹ����****/
/*
���������˼·�������ʱ����ô�Ŵ�
��ĸ���۲죺ȷ�����ɶ��� �������û�и�ֵ��ȷ �ǲ����������
�����߼����󣺿����˵�˼·��д�Լ��Ĵ���
*/

/*��Ч���ֺ�˼��
��float�鷳ʱ�Ϳ���һ����û�е�Ч������ ������ƽ��
*/

/*
�����죺
������ģ�黯 ���� ��ô���˼· �������ݽṹ
������ĳ��ģ��ı�дʱ �����˼·�ٶ���
*/
