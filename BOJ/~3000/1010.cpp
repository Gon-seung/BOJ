#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int dp[31][31];

int find(int n, int m) {
	if (dp[n][m] != 0) { return dp[n][m]; }

	if (n == m) { dp[n][m] = 1; return 1; }
	if (n == 1) { dp[n][m] = m; return m; }
	if (n > m) { return 0; }

	int answer = 0;
	for (int i = 1; m - i >= n - 1; i++) {
		answer += find(n - 1, m - i);
	}
	dp[n][m] = answer;
	return answer;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t = 0;
	cin >> t;
	while (t > 0) {
		t -= 1;

		int n = 0, m = 0;
		cin >> n >> m;
		cout << find(n, m) << "\n";
	}
	return 0;
}