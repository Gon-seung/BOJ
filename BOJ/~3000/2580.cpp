#include <iostream>
#include <vector>
using namespace std;

int sodu[9][9];
vector<vector<bool>> row(9, vector<bool>(10, false));
vector<vector<bool>> col(9, vector<bool>(10, false));
vector<vector<bool>> mix(9, vector<bool>(10, false));

bool Check(int& n) {

	int x = n / 9, y = n % 9;
	int input = sodu[x][y];
	if (row[x][input]) { return false; }
	if (col[y][input]) { return false; }
	if (mix[(x / 3) * 3 + y / 3][input]) { return false; }
	return true;
}

bool Start(int& n) {

	int pos = sodu[n / 9][n % 9];
	row[n / 9][pos] = false;
	col[n % 9][pos] = false;
	mix[((n / 9) / 3) * 3 + (n % 9) / 3][pos] = false;
	for (int i = pos + 1; i <= 9; i++) {
		sodu[n / 9][n % 9] = i;
		if (Check(n)) {
			int input = i;
			row[n / 9][input] = true;
			col[n % 9][input] = true;
			mix[((n / 9) / 3) * 3 + (n % 9) / 3][input] = true;
			return true;
		}
		//cout << n << endl;
	}
	sodu[n / 9][n % 9] = 0;
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> pos;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int input;
			cin >> input;
			sodu[i][j] = input;
			if (input == 0) { pos.push_back(i * 9 + j); }
			else {
				row[i][input] = true;
				col[j][input] = true;
				mix[(i / 3) * 3 + j / 3][input] = true;
			}
		}
	}
	int n = 0;
	while (n < pos.size()) {
		if (Start(pos[n])) {
			n += 1;
		}
		else { n -= 1; }
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sodu[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

