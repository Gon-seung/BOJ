#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> answer;

	int input;
	cin >> input;
	answer.push_back(input);
	for (int i = 1; i < n; i++) {
		cin >> input;
		if (input > answer.back()) { answer.push_back(input); }
		else { answer[lower_bound(answer.begin(), answer.end(), input) - answer.begin()] = input; }

	}
	cout << answer.size();
	return 0;
}

