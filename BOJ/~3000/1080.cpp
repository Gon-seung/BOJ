#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<bool>> matrixa(n, vector<bool>(m, false));
	vector<vector<bool>> matrixb(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		char input[51];
		cin >> input;
		for (int j = 0; j < m; j++) {
			matrixa[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		char input[51];
		cin >> input;
		for (int j = 0; j < m; j++) {
			matrixb[i][j] = input[j] - '0';
		}
	}
	int answer = 0;
	for (int i = 0; i + 2 < n; i++) {
		for (int j = 0; j + 2 < m; j++) {
			if (matrixa[i][j] != matrixb[i][j]) {
				answer += 1;
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						matrixa[i + a][j + b] = !matrixa[i + a][j + b];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrixa[i][j] != matrixb[i][j]) {
				answer = -1;
				break;
			}
		}
		if (answer == -1) { break; }
	}
	cout << answer;

	return 0;
}