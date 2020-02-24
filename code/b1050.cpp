#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> input;
bool cmp(int a, int b) { return a > b;}
int main() {
	int n; cin >> n; input.resize(n);
	int row, col, tmp;
	for (int i = 1; i*i <= n; i++)
		if (n%i == 0) { col = i; row = n / i; }
	vector<vector<int>> display(row, vector<int>(col, -1));
	for (int i = 0; i < n; i++) { cin >> tmp; input[i] = tmp; }
	sort(input.begin(), input.end(), cmp);
	int fillCnt = 0, i = 0, j = 0;
	while (fillCnt < n) {
		while (fillCnt < n && j < col&& display[i][j] == -1)display[i][j++] = input[fillCnt++]; j--; i++;
		while (fillCnt < n && i < row&& display[i][j] == -1)display[i++][j] = input[fillCnt++]; i--; j--;
		while (fillCnt < n && j >= 0 && display[i][j] == -1)display[i][j--] = input[fillCnt++]; j++; i--;
		while (fillCnt < n && i >= 0 && display[i][j] == -1)display[i--][j] = input[fillCnt++]; i++; j++;
	}
	for (int a = 0; a < row; a++) {
		for (int b = 0; b < col; b++) {
			if (b != 0)cout << " ";
			cout << display[a][b];
		}
		cout << endl;
	}
	return 0;
}
