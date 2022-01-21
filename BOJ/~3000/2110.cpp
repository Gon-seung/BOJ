#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int c;
	cin >> n >> c;
	vector<long long> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	long long min = 1;
	sort(pos.begin(), pos.end());
	long long max = pos[n - 1] - pos[0];
	long long answer;
	while (max >= min) {
		long long guess = (min + max) / 2;
		auto curr = pos.begin();
		int count = 0;
		while (curr != pos.end() && count < c) {
			curr = lower_bound(pos.begin(), pos.end(), *curr + guess);
			count += 1;
		}
		if (count == c) { answer = guess; min = guess + 1; }
		else { max = guess - 1; }
	}
	cout << answer;
	return 0;
}

