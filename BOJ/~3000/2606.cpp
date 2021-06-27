#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<bool>> data(n, vector<bool>(n, false));
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		data[x - 1][y - 1] = true;
		data[y - 1][x - 1] = true;
	}

	vector<bool> check(n, true);
	vector<int> answer(1, 0);
	check[0] = false;
	int pos = 0;

	do {
		for (int i = 0; i < n; i++) {
			if (data[answer[pos]][i] && check[i]) {
				check[i] = false;
				answer.push_back(i);
			}
		}
		pos += 1;
	} while (pos != answer.size());

	cout << answer.size() - 1;

	return 0;
}

