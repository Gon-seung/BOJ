#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, l = 0;
	cin >> n >> l;
	vector<vector<int>> data(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int pos = 0;
		bool check = true;
		while (pos < n - 1 && check) {
			if (pos + l < n && (data[i][pos + l] - data[i][pos] == 1)) {
				int hei = data[i][pos];
				for (int k = pos; k < pos + l; k++) {
					if (data[i][k] != hei) { check = false; break; }
				}
				pos += l;
			}
			else if (data[i][pos + 1] == data[i][pos]) { pos += 1; }
			else if (pos + l < n && (data[i][pos + l] - data[i][pos] == -1)) {
				int hei = data[i][pos + 1];
				for (int k = pos + 1; k <= pos + l; k++) {
					if (data[i][k] != hei) { check = false; break; }
				}
				if (pos + 2 * l < n && data[i][pos + 2 * l] - data[i][pos + l] == 1) { check = false; }
				pos += l;
			}
			else { check = false; }
		}
		if (pos >= n - 1 && check) { answer += 1; }
	}
	for (int i = 0; i < n; i++) {
		int pos = 0;
		bool check = true;
		while (pos < n - 1 && check) {
			if (pos + l < n && (data[pos + l][i] - data[pos][i] == 1)) {
				int hei = data[pos][i];
				for (int k = pos; k < pos + l; k++) {
					if (data[k][i] != hei) { check = false; break; }
				}
				pos += l;
			}
			else if (data[pos + 1][i] == data[pos][i]) { pos += 1; }
			else if (pos + l < n && (data[pos + l][i] - data[pos][i] == -1)) {
				int hei = data[pos + 1][i];
				for (int k = pos + 1; k <= pos + l; k++) {
					if (data[k][i] != hei) { check = false; break; }
				}
				if (pos + 2 * l < n && data[pos + 2 * l][i] - data[pos + l][i] == 1) { check = false; }
				pos += l;
			}
			else { check = false; }
		}
		if (pos >= n - 1 && check) { answer += 1; }
	}
	cout << answer;
	return 0;
}

