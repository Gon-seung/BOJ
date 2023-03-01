#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int answer = 0;
	int K = 0;
	int n = 0;
	cin >> n;
	cin >> K;
	vector<vector<int>> data(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		data[i][0] = input1;
		data[i][1] = input2;
	}

	vector<int> maxvalue(K + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = K - data[i][0]; j >= 0; j--) {
			maxvalue[j + data[i][0]] = max(maxvalue[j] + data[i][1], maxvalue[j + data[i][0]]);
		}
	}
	for (int i = 0; i < K + 1; i++) {
		if (maxvalue[i] > answer) { answer = maxvalue[i]; }
	}
	cout << answer;
	return 0;
}