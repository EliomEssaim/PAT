#include<iostream>
#include<vector>
using namespace std;
int fullScore[110] = { 0 }, answerNums[110] = { 0 }, maxWrongCnt = 0;
int main() {
	int n, m, chooseNums, tmpFullScore, tmpAnsNums;
	char tmpAns;
	cin >> n >> m;
	vector<vector<bool>> answer(m);
	vector<vector<int>> qWrongCnt(m);
	for (int i = 0; i < m; i++) {
		cin >> tmpFullScore >> chooseNums >> tmpAnsNums;
		fullScore[i] = tmpFullScore;
		answerNums[i] = tmpAnsNums;
		answer[i].resize(chooseNums);
		qWrongCnt[i].resize(chooseNums);
		for (int j = 0; j < tmpAnsNums; j++) {
			cin >> tmpAns;
			answer[i][tmpAns - 'a'] = true;
		}
	}
	float stuScore = 0.0;
	int rightCnt = 0, wrongCnt = 0;
	for (int i = 0; i < n; i++) {
		stuScore = 0.0;
		vector<vector<bool>> choosed(m);
		for (int j = 0; j < m; j++) {
			while (getchar() != '(');
			choosed[j].resize(qWrongCnt[j].size());
			cin >> chooseNums;
			wrongCnt = 0, rightCnt = 0;
			for (int k = 0; k < chooseNums; k++) {
				cin >> tmpAns;
				choosed[j][tmpAns - 'a'] = true;
			}
			for (int k = 0; k < (int)choosed[j].size(); k++)
				if (choosed[j][k] ^ answer[j][k]) {
					if(answer[j][k]==0)wrongCnt++;
					qWrongCnt[j][k]++;
					if (qWrongCnt[j][k] > maxWrongCnt) maxWrongCnt = qWrongCnt[j][k];
				}
				else if (answer[j][k] == 1)rightCnt++;
			if (wrongCnt == 0 && rightCnt == answerNums[j]) stuScore += fullScore[j];
			else if (wrongCnt == 0 && rightCnt < answerNums[j])  stuScore += (float)fullScore[j] / 2.0;
			while (getchar() != ')');
		}
		printf("%.1f\n", stuScore);
	}
	if (maxWrongCnt == 0) { cout << "Too simple" << endl; return 0; }
	for (int i = 0; i < m; i++)
		for (int j = 0; j < (int)qWrongCnt[i].size(); j++)
			if (qWrongCnt[i][j] == maxWrongCnt) {
				cout << maxWrongCnt << " " << i + 1 << "-" << (char)(j + 'a') << endl;
			}
	return 0;
}
