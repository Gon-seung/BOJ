#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		data[n - 1 - i] = input;
	}

	vector<int> max1(n);
	vector<int> max2(n);
	max1[0] = data[0];
	max2[0] = 0;
	if (n > 1) {
		max2[1] = data[0] + data[1];
		max1[1] = 0;

		for (int i = 2; i < n; i++) {
			if (max1[i - 2] < max2[i - 2]) { max1[i] = max2[i - 2] + data[i]; }
			else { max1[i] = max1[i - 2] + data[i]; }

			max2[i] = max1[i - 1] + data[i];
		}
	}

	if (n == 1) { cout << max1[0]; }
	else {
		int answer = max1[n - 1];
		if (max1[n - 2] > answer) { answer = max1[n - 2]; }
		if (max2[n - 2] > answer) { answer = max2[n - 2]; }
		if (max2[n - 1] > answer) { answer = max2[n - 1]; }
		cout << answer;
	}
	return 0;
}