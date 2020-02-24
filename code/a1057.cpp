#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxn = 100010;
stack<int> s;
vector<int> c(maxn, 0);
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
	int n, temp;
	string str;
	str.resize(12);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &str[0]);
		if (str[1] == 'u') {
			scanf("%d", &temp);
			s.push(temp);
			update(temp, 1);
		}else if (str[1] == 'o') {
			if (s.empty())
				printf("Invalid\n");
			else {
				printf("%d\n", s.top());
				s.pop();
				update(s.top(), -1);
			}
		}else {
			if (s.empty())
				printf("Invalid\n");
			else PeekMedian();
		}
	}
	return 0;
}
