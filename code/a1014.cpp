#include<iostream>
#include<vector>
using namespace std;
struct node {
	int start, dur, End = -1, id;
};
vector<node> customList;
int totalClock = 60 * 8 + 0, cntEnter = 0, lineLimit;
bool outFlag = false;
int main() {
	int n, m, k, q, tmpID;
	cin >> n >> m >> k >> q;
	lineLimit = m * n;
	vector<vector<node>> windows(n, vector<node>(m));
	customList.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &customList[i].dur);
		customList[i].id = i;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (cntEnter <= lineLimit && cntEnter <= k)windows[j][i] = customList[1 + cntEnter++];
	for (int i = 0; i < n; i++)
		if (!windows[i].empty())windows[i][0].start = totalClock;
	for (; !outFlag&&totalClock<=24*60; totalClock++) {
		for (int i = 0; i < n; i++)
			if (!windows[i].empty() && (windows[i][0].start + windows[i][0].dur == totalClock)) {
				customList[windows[i][0].id].End = totalClock;
				windows[i].erase(windows[i].begin());
				if (!windows[i].empty())windows[i][0].start = totalClock;
				if (cntEnter < k)windows[i].push_back(customList[1 + cntEnter++]);
			}
		if (totalClock == 17 * 60 -1 )
			for (int i = 0; i < n; i++)
				if (!windows[i].empty()) {
					node tmpNode = windows[i][0];
					windows[i].erase(windows[i].begin(), windows[i].end());
					windows[i].push_back(tmpNode);
				}
		if (totalClock >= 17 * 60 ) {
			outFlag = true;
			for (int i = 0; i < n; i++)
				if (!windows[i].empty())outFlag = false;
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &tmpID);
		if (customList[tmpID].End > 0)printf("%02d:%02d\n", customList[tmpID].End / 60, customList[tmpID].End % 60);
		else printf("Sorry\n");
	}
	return 0;
}
