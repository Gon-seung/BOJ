#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t = 0;
	cin >> t;
	vector<int> input(t);
	int max = 0;
	for (int i = 0; i < t; i++) {
		cin >> input[i];
		max = max < input[i] ? input[i] : max;
	}
	vector<int> answer(max + 1);
	answer[1] = 1;
	answer[2] = 2;
	answer[3] = 4;
	for (int i = 4; i <= max; i++) {
		answer[i] = answer[i - 1] + answer[i - 2] + answer[i - 3];
	}
	for (int i = 0; i < t; i++) {
		cout << answer[input[i]] << "\n";
	}

	return 0;
}

