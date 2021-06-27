#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> data(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		data[i] = { x,y };
	}
	vector<vector<int>> answer(n, vector<int>(n, 1 << 29));
	int len = 0;
	while (len < n) {
		int start = 0;
		while (len + start < n) {
			if (len == 0) { answer[start][start + len] = 0; }
			else if (len == 1) { answer[start][start + len] = data[start].first * data[start].second * data[start + len].second; }
			else {
				int pos = 0;
				while (pos < len) {
					int comp = answer[start][start + pos] + data[start].first * data[start + pos].second * data[start + len].second + answer[start + pos + 1][start + len];
					answer[start][start + len] = answer[start][start + len] < comp ? answer[start][start + len] : comp;
					pos += 1;
					//cout << start << " " << start + len << " " << answer[start][start+len] << " " << comp << endl;
				}
			}
			start += 1;
		}
		len += 1;
	}
	cout << answer[0][n - 1];

	return 0;
}

