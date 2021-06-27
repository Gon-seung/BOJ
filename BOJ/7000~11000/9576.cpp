#include <iostream> 
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) { return a.first < b.first; }
	else { return a.second < b.second; }
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
		vector<pair<int, int>> data(m);
		for (int i = 0; i < m; i++) {
			int start, end;
			cin >> start >> end;
			data[i] = { start,end };
		}
		sort(data.begin(), data.end(), Compare);
		multiset<int> endpos;
		int pos = 0;
		int num = 1;
		int answer = 0;

		while (num <= n) {
			while (!endpos.empty() && *endpos.begin() < num) {
				endpos.erase(endpos.begin());
			}
			while (pos < m && data[pos].first <= num && data[pos].second >= num) {
				endpos.insert(data[pos].second);
				pos += 1;
			}
			if (!endpos.empty() && *endpos.begin() >= num) {
				answer += 1;
				endpos.erase(endpos.begin());
				num += 1;

			}
			else { num += 1; }

		}
		cout << answer << "\n";
	}

	return 0;
}