#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> facePart(3);
int main() {
	string tmp, ans; int leftIndex, rightIndex;
	for (int i = 0; i < 3; i++) {
		getline(cin, tmp);
		for (leftIndex = 0; leftIndex < (int)tmp.size(); leftIndex++) {
			if (tmp[leftIndex] == '[') {
				for (rightIndex = leftIndex + 1; tmp[rightIndex] != ']'; rightIndex++);
				facePart[i].push_back(tmp.substr(leftIndex + 1, rightIndex - leftIndex - 1));
			}
		}
	}
	int k, a, b, c, d, e; cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d >> e;
		a--; b--; c--; d--; e--;
		if (a < (int)facePart[0].size() && b < (int)facePart[1].size() && c < (int)facePart[2].size() && d < (int)facePart[1].size() && e < (int)facePart[0].size() \
			&&a >= 0 && b >= 0 && c >= 0 && e >= 0 && d >= 0)
			cout << facePart[0][a] << "(" << facePart[1][b] << facePart[2][c] << facePart[1][d] << ")" << facePart[0][e] << endl;
		else cout << "Are you kidding me? @\\/@" << endl;
	}
	return 0;
}
