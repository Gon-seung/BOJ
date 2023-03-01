#include <iostream> 
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) { return a.first > b.first; }
	else { return a.second > b.second; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> data(n);
	for (int i = 0; i < n; i++) {
		int dead, cup;
		cin >> dead >> cup;
		data[i] = { dead,cup };
	}
	sort(data.begin(), data.end(), Compare);

	multiset<int> candi;
	int pos = n;
	int deadpos = 0;
	int answer = 0;
	while (pos > 0) {
		while (deadpos < n && data[deadpos].first >= pos) {
			candi.insert(data[deadpos].second);
			deadpos += 1;
		}
		if (!candi.empty()) { answer += *(--candi.end()); candi.erase(--candi.end()); }
		pos -= 1;
	}
	cout << answer;
	return 0;
}