#include<iostream>
#include<string>
using namespace std;
int d, n, j;
string appearanceSeq(int n) {
	if (n == 1)return to_string(d);
	else {
		string ans, last;
		last = appearanceSeq(n - 1);
		for (int i = 0; i < (int)last.size(); i = j) {
			for (j = i; j < (int)last.size() && last[j] == last[i]; j++);
			ans += last[i] + to_string(j - i);
		}
		return ans;
	}
}
int main() {
	cin >> d >> n;
	cout << appearanceSeq(n);
	return 0;
}
