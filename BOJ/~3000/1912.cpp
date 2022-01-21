#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<int> sum_data;
	vector<int> data(n);

	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		data[i] = input;
	}

	int answer = data[0];
	int sum = data[0];
	for (int i = 1; i < n; i++) {
		sum = max(sum + data[i], data[i]);
		answer = max(answer, sum);
	}
	cout << answer;
	return 0;
}