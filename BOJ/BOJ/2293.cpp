#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> answer(k + 1);
	for (int i = 0; i < n; i++) {

		int input = 0;
		cin >> input;
		if (input <= k) { answer[input] += 1; }
		for (int j = k; j > 0; j--) {
			for (int q = input; j + q <= k; q += input) {
				answer[j + q] += answer[j];
			}
		}
		/*for (int j = 0; j <= k; j++) {
			cout << answer[j] << " ";
		}
		cout << endl;*/
	}

	cout << answer[k];
	return 0;
}