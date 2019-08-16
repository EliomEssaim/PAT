#include<iostream>
#include<vector>
#include<algorithm>
#define displayFlag 0
#define judgeFlag 1
using namespace std;
struct node {
	int rank, id, total = 0, passnum = 0;
	vector<int> score; bool isshown = false;
};

bool cmp(node a, node b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.passnum != b.passnum) return a.passnum > b.passnum;
	else return a.id < b.id;
}
int main() {
	int id, num, score, n, k, m;;
	vector<node> v; vector<int> full;
	scanf("%d%d%d", &n, &k, &m);
	full.resize(k + 1);
	v.resize(n + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &full[i]);
	}
	for (int i = 0; i <= n; i++) {
		v[i].score.resize(k + 1, -1);
		v[i].id = i;
	}
#if judgeFlag
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &id, &num, &score);
		v[id].id = id;
		if (score != -1) {
			v[id].isshown = true;
			if (v[id].score[num] < score) {
				v[id].score[num] = score;
			}
		}
		else if (v[id].score[num] == -1) v[id].score[num] = -2;
	}
#endif
#if !judgeFlag
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &id, &num, &score);
		v[id].id = id;
		v[id].score[num] = max(v[id].score[num], score);
		if (score != -1)
			v[id].isshown = true;
		else if (v[id].score[num] == -1)
			v[id].score[num] = -2;
	}
#endif
	for (int i = 0; i <= n; i++) {

		for (int j = 1; j <= k; j++)
			if (v[i].score[j] != -1 && v[i].score[j] != -2) {
				v[i].total += v[i].score[j];
				if (v[i].score[j] == full[j])v[i].passnum++;
			}
	}
	sort(v.begin() + 1, v.end(), cmp);
	v[1].rank = 1;
	for (int i = 2; i <= n; i++) {//wrong
		if (v[i].total == v[i - 1].total)
			v[i].rank = v[i - 1].rank;
		else v[i].rank = i;
	}
#if displayFlag
	for (int i = 1; i < = n; i++) {//wrong
		if (v[i].isshown == true) {
			printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
			for (int j = 1; j <= 4; j++) {
				if (v[i].score[j] != -1 && v[i].score[j] != -2)
					printf(" %d", v[i].score[j]);
				else if (v[i].score[j] == -1)
					printf(" -");
				else
					printf(" 0");
			}
			printf("\n");
		}
	}
#endif // displayFlag
#if !displayFlag
	for (int i = 1; i <= n; i++) {
		if (v[i].isshown == true) {
			printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
			for (int j = 1; j <= k; j++) {
				if (v[i].score[j] != -1 && v[i].score[j] != -2)
					printf(" %d", v[i].score[j]);
				else if (v[i].score[j] == -1)
					printf(" -");
				else
					printf(" 0");
			}
			printf("\n");
		}
	}
#endif
	return 0;
}
//segmentFault


#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k, m;
const int maxn = 100010;
struct node {
	int rank_, id, totalScore = 0, pefectSolvedProblems = 0;
}submit[maxn];
vector<int> score[maxn];
vector<int> FullScore;
bool cmp(node a, node b) {
	if (a.totalScore != b.totalScore) return a.totalScore > b.totalScore;
	else if (a.pefectSolvedProblems != b.pefectSolvedProblems) return a.pefectSolvedProblems > b.pefectSolvedProblems;
	else return a.id < b.id;
}
int main() {
	int tmpid, proId, tmpScore;
	scanf("%d%d%d", &n, &k, &m);
	FullScore.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &FullScore[i]);
	}
	for (int i = 0; i < maxn; i++) {
		score[i].resize(k + 1);
		submit[i].id = i;
	}
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < k + 1; j++)
			score[i][j] = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &tmpid, &proId, &tmpScore);
		submit[tmpid].id = tmpid;
		if (tmpScore != -1 && score[tmpid][proId] < tmpScore) {
			score[tmpid][proId] = tmpScore;
			submit[tmpid].totalScore = 0;
			submit[tmpid].pefectSolvedProblems = 0;
			for (int j = 1; j <= k; j++) {//wrong
				if (score[tmpid][j] != -1) {
					submit[tmpid].totalScore += score[tmpid][j];//wrong
					if (score[tmpid][j] == FullScore[j])
						submit[tmpid].pefectSolvedProblems++;
				}
			}
		}
		else if (tmpScore == -1) score[tmpid][proId] = 0;
	}
	sort(submit, submit + maxn, cmp);
	submit[0].rank_ = 1;
	for (int i = 1; i <= k; i++) {//wrong
		if (submit[i].totalScore == submit[i - 1].totalScore)
			submit[i].rank_ = submit[i - 1].rank_;
		else submit[i].rank_ = i + 1;
	}
	for (int i = 0; i < m; i++) {//wrong
		if (submit[i].totalScore == 0)
			break;
		printf("%d %05d %d", submit[i].rank_, submit[i].id, submit[i].totalScore);
		for (int j = 1; j <= 4; j++) {
			if (score[submit[i].id][j] != -1) printf(" %d", score[submit[i].id][j]);
			else printf(" -");
		}
		printf("\n");
	}
	return 0;
}
#endif
