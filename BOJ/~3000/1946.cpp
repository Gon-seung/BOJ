#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t = 0;
	cin >> t;
	while (t > 0) {
		t -= 1;
		int n = 0;
		cin >> n;
		vector<pair<int, int>> grade(n);
		for (int i = 0; i < n; i++) {
			int first, second;
			cin >> first >> second;
			grade[i] = { first,second };
		}
		sort(grade.begin(), grade.end(), Compare);
		int min = grade[0].second;
		int answer = 1;
		for (int i = 1; i < n; i++) {
			if (grade[i].second < min) { min = grade[i].second; answer += 1; }
		}
		cout << answer << "\n";
	}

	return 0;
}