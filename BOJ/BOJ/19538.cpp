#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxv = 200000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<vector<int>> data(n);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		while (input != 0) {
			data[i].push_back(input - 1);
			cin >> input;
		}
	}
	int m = 0;
	cin >> m;
	vector<int> beli;
	vector<int> answer(n, -1);
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		beli.push_back(input - 1);
		answer[input - 1] = 0;
	}
	vector<int> new_beli;
	vector<int> num(n, 0);
	int time = 0;
	while (beli.size() > 0) {
		time += 1;
		for (int i = 0; i < beli.size(); i++) {
			int pos = beli[i];
			for (int j = 0; j < data[pos].size(); j++) {
				num[data[pos][j]] += 1;
				if (num[data[pos][j]] == (data[data[pos][j]].size() + 1) / 2 && answer[data[pos][j]] == -1) {
					new_beli.push_back(data[pos][j]);
					answer[data[pos][j]] = time;
				}
			}
		}
		beli = new_beli;
		new_beli.clear();
	}
	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}

