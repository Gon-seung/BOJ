#include <iostream>
#include <vector>
using namespace std;

bool Check(int x, int y, int size, vector<vector<int>>& data) {
	int color = data[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (data[i][j] != color) { return false; }
		}
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int white = 0;
	int blue = 0;
	vector<vector<int>> data(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	vector<pair<int, int>> pos;
	vector<pair<int, int>> newpos;
	pos = { { 0,0 } };
	while (pos.size() > 0) {
		newpos.clear();
		for (int i = 0; i < pos.size(); i++) {
			int x = pos[i].first;
			int y = pos[i].second;
			if (Check(x, y, n, data)) {
				data[x][y] ? blue += 1 : white += 1;
			}
			else {
				newpos.push_back({ x,y });
				newpos.push_back({ x + n / 2,y });
				newpos.push_back({ x,y + n / 2 });
				newpos.push_back({ x + n / 2,y + n / 2 });
			}
		}
		n /= 2;
		pos = newpos;
	}
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}

