#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, k, m;


bool Compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t > 0) {
		t -= 1;
		cin >> n;
		vector<pair<int, int>> data(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i].first;
			cin >> data[i].second;
		}
		sort(data.begin(), data.end(), Compare);

		vector<vector<double>> dis(n, vector<double>(n, 0));
		vector<vector<double>> dp(n, vector<double>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x_dis = data[i].first - data[j].first;
				int y_dis = data[i].second - data[j].second;
				dis[i][j] = sqrt(x_dis * x_dis + y_dis * y_dis);
				dp[i][j] = 123456789;
			}
		}
		dp[0][1] = dis[0][1];
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < i; j++) {
				dp[j][i + 1] = min(dp[j][i] + dis[i][i + 1], dp[j][i + 1]);
				dp[i][i + 1] = min(dp[j][i] + dis[j][i + 1], dp[i][i + 1]);
			}
		}
		double answer = 123456789;
		for (int i = 0; i < n; i++) {
			answer = min(answer, dp[i][n - 1] + dis[i][n - 1]);
		}
		cout << answer << "\n";

	}

	return 0;
}