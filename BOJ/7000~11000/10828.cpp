#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string input;
	int n;
	cin >> n;
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> input;
			answer.push_back(input);
		}
		else if (input == "size") {
			cout << answer.size() << "\n";
		}
		else if (input == "empty") {
			cout << answer.empty() << "\n";
		}
		else if (answer.empty()) {
			cout << -1 << "\n";
		}
		else if (input == "pop") {
			cout << answer.back() << "\n";
			answer.pop_back();
		}
		else if (input == "top") {
			cout << answer.back() << "\n";
		}
	}
	return 0;
}

