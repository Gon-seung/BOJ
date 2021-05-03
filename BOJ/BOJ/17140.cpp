#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) { return a.second < b.second; }
	else { return a.first < b.first; }
}
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//rck
	int r = 0, c = 0, k = 0;
	cin >> r >> c >> k;
	vector<int> in(100);
	int len_r = 3, len_c = 3;
	vector<vector<int>> data(100, in);
	int input;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input;
			data[i][j] = input;
		}
	}

	int time = 0;
	while (data[r - 1][c - 1] != k && time <= 100) {
		time += 1;
		vector<vector<int>> new_data(100, in);
		if (len_r >= len_c) {
			len_c = 0;
			for (int i = 0; i < 100; i++) {

				vector<int> num(101);
				for (int j = 0; j < 100; j++) {
					num[data[i][j]] += 1;
				}
				vector<pair<int, int>> num_sort;
				for (int j = 1; j <= 100; j++) {
					if (num[j] != 0) { num_sort.push_back({ j,num[j] }); }
				}
				sort(num_sort.begin(), num_sort.end(), Compare);
				for (int j = 0; j < num_sort.size(); j++) {
					if (j < 50) {
						new_data[i][2 * j] = num_sort[j].first;
						new_data[i][2 * j + 1] = num_sort[j].second;
					}
					else { break; }
				}
				if (num_sort.size() * 2 > len_c) { len_c = num_sort.size() * 2; }
				if (len_c > 100) { len_c = 100; }
			}
			data = new_data;

		}
		else {
			len_r = 0;
			for (int i = 0; i < 100; i++) {
				vector<int> num(101);
				for (int j = 0; j < 100; j++) {
					num[data[j][i]] += 1;
				}
				vector<pair<int, int>> num_sort;
				for (int j = 1; j <= 100; j++) {
					if (num[j] != 0) { num_sort.push_back({ j,num[j] }); }
				}
				sort(num_sort.begin(), num_sort.end(), Compare);
				for (int j = 0; j < num_sort.size(); j++) {
					if (j < 50) {
						new_data[2 * j][i] = num_sort[j].first;
						new_data[2 * j + 1][i] = num_sort[j].second;
					}
					else { break; }
				}
				if (num_sort.size() * 2 > len_r) { len_r = num_sort.size() * 2; }
				if (len_r > 100) { len_r = 100; }
			}
			data = new_data;
		}
	}
	if (time > 100) { time = -1; }
	cout << time;
	//max 100
	//for
	//

	return 0;
}
