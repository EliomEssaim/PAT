#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b) { return a > b; }
int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) father[faA] = faB;
}
int main() {
	int n, k, t, cnt = 0;
	int course[1001] = { 0 };
	scanf("%d", &n);
	father.resize(n + 1);
	isRoot.resize(n + 1);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			if (course[t] == 0)
				course[t] = i;
			Union(i, findFather(course[t]));
		}
	}
	for (int i = 1; i <= n; i++)
		isRoot[findFather(i)]++;
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0) cnt++;
	}
	printf("%d\n", cnt);
	sort(isRoot.begin(), isRoot.end(), cmp1);
	for (int i = 0; i < cnt; i++) {
		printf("%d", isRoot[i]);
		if (i != cnt - 1) printf(" ");
	}
	return 0;
}
/*
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 - 1 0 2 300
3721 - 1 - 1 1 2333 2 150
9012 - 1 - 1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 - 1 3721 3 6661 6662 6663 1 100
*/