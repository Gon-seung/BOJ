#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += (n - i) * data[i];
	}

	cout << answer;

	return 0;
}

