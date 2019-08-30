#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> initSequ, test;
int main() {
	int n;
	scanf("%d", &n);
	initSequ.resize(n); test.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &initSequ[i]);
	for (int i = 0; i < n; i++) scanf("%d", &test[i]);
	int hook = n - 1;
	while (test[hook] == initSequ[hook] && hook >= 0) hook--;//边界
	hook += 1;
	vector<int> tmp = initSequ;
	sort(tmp.begin(), tmp.begin() + hook);
	int k = 0;
	for (; k < hook; k++) if (tmp[k] != test[k]) break;
	if (k == hook) {
		cout << "Insertion Sort" << endl;
		sort(tmp.begin(), tmp.begin() + hook + 1);
		for (int i = 0; i < n; i++) printf("%d%s", tmp[i], i == n - 1 ? "\n" : " ");
	}
	else {
		cout << "Merge Sort" << endl;
		tmp = initSequ; bool cor = false;
		int mergeSize = 2;
		while (1) {
			for (int i = 0; i < n; i++) {
				if (mergeSize >= n) {
					sort(tmp.begin(), tmp.end());
					goto print;
				}
				int pre = i * mergeSize, next = mergeSize - 1 + i * mergeSize;
				if (next < n) sort(tmp.begin() + pre, tmp.begin() + next+1);
				else break;
			}
			if (cor == true) break;
			if (test == tmp) cor = true;
			mergeSize *= 2;
		}
	print:
		for (int i = 0; i < n; i++) printf("%d%s", tmp[i], i == n - 1 ? "\n" : " ");
	}

	return 0;
}
//mergede的错误理解
