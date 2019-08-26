#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define Type long long
vector<Type> v;
int main() {
	int n;
	Type p;
	scanf("%d%lld", &n, &p);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	sort(v.begin(), v.end());
	int length = 0;
	for (int i = 0; i < n; i++) {
		if (n - i - 1 < length) break;
		auto pos = upper_bound(v.begin(), v.end(), p*v[i]);
		length = max((int)(pos - v.begin() - i), length);
	}
	cout << length << endl;
	return 0;
}
//if (pos != v.end())逻辑大失败 找不到说明都可以
//max里面要强制转换才能用
