#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int max = 20;
	vector<bool> answer(max + 1, false);

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string input;
		int input2;
		cin >> input;
		if (input == "add") {
			cin >> input2;
			answer[input2] = true;
		}
		else if (input == "remove") {
			cin >> input2;
			answer[input2] = false;
		}
		else if (input == "check") {
			cin >> input2;
			cout << answer[input2] << "\n";
		}
		else if (input == "toggle") {
			cin >> input2;
			answer[input2] = !answer[input2];
		}
		else if (input == "all") {
			for (int i = 1; i <= max; i++) {
				answer[i] = true;
			}
		}
		else if (input == "empty") {
			for (int i = 1; i <= max; i++) {
				answer[i] = false;
			}
		}
	}

	return 0;
}