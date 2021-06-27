#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int dp[501][501];
int m;
int n;

void bfs(vector<vector<int>>& data, int x, int y) {
	data[x][y] = 0;
	if (x - 1 >= 0 && data[x - 1][y] == 1) {
		bfs(data, x - 1, y);
	}
	if (x + 1 < n && data[x + 1][y] == 1) {
		bfs(data, x + 1, y);
	}
	if (y - 1 >= 0 && data[x][y - 1] == 1) {
		bfs(data, x, y - 1);
	}
	if (y + 1 < m && data[x][y + 1] == 1) {
		bfs(data, x, y + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t = 0;
	cin >> t;
	while (t > 0) {
		t -= 1;
		int num = 0;
		int answer = 0;
		cin >> m >> n >> num;
		vector<vector<int>> data(n, vector<int>(m, 0));
		vector<vector<int>> posb;
		for (int i = 0; i < num; i++) {
			int a, b;
			cin >> b >> a;
			data[a][b] = 1;
			posb.push_back({ a,b });

		}
		for (int i = 0; i < num; i++) {
			int x = posb[i][0];
			int y = posb[i][1];
			if (data[x][y]) {
				answer += 1;
				bfs(data, x, y);
			}
		}
		cout << answer << "\n";

	}
	return 0;
}