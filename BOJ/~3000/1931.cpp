#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) { return a.second < b.second; }
	else { return a.first < b.first; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> price(n);
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		price[i] = { x,y };
	}
	int answer = 0;
	int time = 0;
	sort(price.begin(), price.end(), Compare);
	int pos = 0;

	while (pos < n) {
		if (price[pos].first >= time) {
			answer += 1;
			time = price[pos].second;
		}
		pos += 1;
	}
	cout << answer;

	return 0;
}

