#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Check(vector<vector<bool>>& data, int x, int y, int& size) {
	int n = data.size();
	if (x < 0 || x >= n || y < 0 || y >= n || data[x][y] == 0) { return; }
	else {
		data[x][y] = false;
		size += 1;
		Check(data, x - 1, y, size);
		Check(data, x + 1, y, size);
		Check(data, x, y - 1, size);
		Check(data, x, y + 1, size);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<vector<bool>> data(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		string x = "";
		cin >> x;
		for (int j = 0; j < n; j++) {
			data[i][j] = x[j] - '0';
		}
	}

	int answer = 0;
	int size = 0;
	vector<int> sizes;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (data[i][j]) { Check(data, i, j, size); answer += 1; sizes.push_back(size); size = 0; }
		}
	}
	cout << answer << "\n";
	sort(sizes.begin(), sizes.end());
	for (int i = 0; i < sizes.size(); i++) {
		cout << sizes[i] << "\n";
	}
	return 0;
}

