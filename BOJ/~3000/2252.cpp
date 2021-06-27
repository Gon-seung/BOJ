#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxv = 200000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> data(n);
	vector<vector<int>> root(n);
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		data[y - 1] += 1;
		root[x - 1].push_back(y - 1);
	}

	vector<int> check;
	for (int i = 0; i < n; i++) {
		if (data[i] == 0) {
			check.push_back(i);
		}
	}
	vector<int> answer;
	while (check.size() > 0) {
		int pos = check.back();
		answer.push_back(pos);
		check.pop_back();
		for (int i = 0; i < root[pos].size(); i++) {
			int del_pos = root[pos][i];
			data[del_pos] -= 1;
			if (data[del_pos] == 0) { check.push_back(del_pos); }
		}
	}
	for (int i = 0; i < n; i++) {
		cout << answer[i] + 1 << " ";
	}
	return 0;
}

