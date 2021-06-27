#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int dp[501][501];
int n;
int m;

bool Compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void makedp(vector<vector<int>>& data, int x, int y) {
	if (x == n - 1 && y == m - 1) { dp[x][y] = 1; return; }
	long long sum = 0;
	int pivot = data[x][y];
	if (x - 1 >= 0 && data[x - 1][y] < pivot) {
		sum += dp[x - 1][y];
	}
	if (y - 1 >= 0 && data[x][y - 1] < pivot) {
		sum += dp[x][y - 1];
	}
	if (x + 1 < n && data[x + 1][y] < pivot) {
		sum += dp[x + 1][y];
	}
	if (y + 1 < m && data[x][y + 1] < pivot) {
		sum += dp[x][y + 1];
	}
	dp[x][y] = sum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<vector<int>> data(n, vector<int>(m, 0));
	vector<vector<int>> sor;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input = 0;
			cin >> input;
			data[i][j] = input;
			sor.push_back({ input,i,j });
		}
	}
	sort(sor.begin(), sor.end(), Compare);
	for (int i = 0; i < sor.size(); i++) {
		makedp(data, sor[i][1], sor[i][2]);
	}
	cout << dp[0][0];

	return 0;
}