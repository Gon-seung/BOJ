#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<int> max;
	vector<int> new_max;

	int input = 0;
	cin >> input;
	max = { input };

	for (int i = 1; i < n; i++) {
		new_max.clear();
		for (int j = 0; j <= i; j++) {
			cin >> input;
			if (j == i) { new_max.push_back(max[j - 1] + input); }
			else if (j == 0) { new_max.push_back(max[0] + input); }
			else if (max[j - 1] > max[j]) { new_max.push_back(max[j - 1] + input); }
			else { new_max.push_back(max[j] + input); }
		}
		max = new_max;
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (max[i] > answer) { answer = max[i]; }
	}
	cout << answer << endl;
	return 0;
}