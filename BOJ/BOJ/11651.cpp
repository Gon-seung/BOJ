#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int > b) {
	if (a.second != b.second) { return a.second < b.second; }
	else { return a.first < b.first; }
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<pair<int, int>> data(N);
	for (int i = 0; i < N; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		data[i] = { x,y };
	}
	sort(data.begin(), data.end(), Compare);
	for (int i = 0; i < N; i++) {
		cout << data[i].first << " " << data[i].second << "\n";
	}

	return 0;
}