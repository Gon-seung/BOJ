#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<long long> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	vector<int> answer(n, 1 << 29);
	answer[0] = 0;
	for (int i = 1; i < n; i++) {
		answer[i] = i;
		for (int j = 0; j < i; j++) {
			if (data[i] % data[j] == 0 && answer[i] > answer[j] + i - j - 1) {
				answer[i] = answer[j] + i - j - 1;
			}
		}
	}
	int output = 1 << 29;
	for (int i = 0; i < n; i++) {
		//cout << answer[i] << endl;
		if (n - i - 1 + answer[i] < output) {
			output = n - i - 1 + answer[i];
		}
	}
	cout << output;
	return 0;
}