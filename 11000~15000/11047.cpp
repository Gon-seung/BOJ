#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> price(n);
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	int answer = 0;
	int pos = n - 1;
	while (k > 0) {
		answer += k / price[pos];
		k %= price[pos];
		pos -= 1;
	}
	cout << answer;

	return 0;
}

