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
		int input;
		cin >> input;
		data[i] = input;
	}
	vector<vector<int>> case1;
	for (int i = 0; i < data.size(); i++) {

		vector<vector<int>> case2;
		for (int j = 0; j < case1.size(); j++) {
			vector<int> new_case;
			new_case = case1[j];
			if (new_case[new_case.size() - 1] < data[i]) { new_case.push_back(data[i]); case2.push_back(new_case); }

		}
		case2.push_back({ data[i] });

		int max = 0, pos = 0;
		for (int j = 0; j < case2.size(); j++) {
			if (case2[j].size() > max) { pos = j; max = case2[j].size(); }
		}
		case1.push_back(case2[pos]);

	}

	int answer = 0;
	for (int i = 0; i < case1.size(); i++) {
		if (case1[i].size() > answer) { answer = case1[i].size(); }
	}

	cout << answer;
	return 0;
}