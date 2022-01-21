#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<char>> data(N, vector<char>(M, 0));
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {

			data[i][j] = input[j];
		}
	}
	int countw = 0;
	int countb = 0;
	int max = 1 << 30;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			countw = 0;
			countb = 0;
			for (int k = 0; k < 64; k++) {
				if ((k / 8 + k % 8) % 2 == 0 && data[i + k / 8][j + k % 8] == 'W') { countw += 1; }
				else if ((k / 8 + k % 8) % 2 == 1 && data[i + k / 8][j + k % 8] == 'B') { countw += 1; }
				else if ((k / 8 + k % 8) % 2 == 0 && data[i + k / 8][j + k % 8] == 'B') { countb += 1; }
				else if ((k / 8 + k % 8) % 2 == 1 && data[i + k / 8][j + k % 8] == 'W') { countb += 1; }
			}
			if (max > countw) { max = countw; }
			if (max > countb) { max = countb; }
		}
	}
	cout << max;
	return 0;
}