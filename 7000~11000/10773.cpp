#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int answer = 0;
	vector<int> data;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) { answer -= data.back(); data.pop_back(); }
		else {
			answer += input;
			data.push_back(input);
		}
	}
	cout << answer;
	return 0;
}

