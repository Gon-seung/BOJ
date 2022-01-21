#include <iostream>
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
		long long input = 0;
		cin >> input;
		data[i] = input;
	}
	vector<long long> max1(n);
	vector<long long> max2(n);
	max1[0] = data[0];
	max2[0] = 0;

	if (n > 1) { max1[1] = data[1]; max2[1] = data[0] + data[1]; }
	if (n > 2) { max1[2] = data[0] + data[2]; max2[2] = data[1] + data[2]; }
	for (int i = 3; i < n; i++) {
		max1[i] = max2[i - 2] + data[i];
		if (max1[i] < max1[i - 2] + data[i]) { max1[i] = max1[i - 2] + data[i]; }
		if (max1[i] < max2[i - 3] + data[i]) { max1[i] = max2[i - 3] + data[i]; }
		max2[i] = max1[i - 1] + data[i];
	}

	if (n == 1) { cout << max1[0]; }
	else {
		int answer = max1[n - 1];
		if (answer < max1[n - 2]) { answer = max1[n - 2]; }
		if (answer < max2[n - 1]) { answer = max2[n - 1]; }
		if (answer < max2[n - 2]) { answer = max2[n - 2]; }
		cout << answer;
	}
	return 0;
}