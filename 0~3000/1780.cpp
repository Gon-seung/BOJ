#include <iostream>
#include <vector>
using namespace std;

int countmi = 0;
int countze = 0;
int countpl = 0;

bool Check(int x, int y, int size, vector<vector<int>>& data) {
	int color = data[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (data[i][j] != color) { return false; }
		}
	}
	return true;
}

void Start(pair<int, int> pos, int size, vector<vector<int>>& data) {
	int x = pos.first;
	int y = pos.second;
	if (Check(x, y, size, data)) {
		if (data[x][y] == -1) { countmi += 1; }
		if (data[x][y] == 0) { countze += 1; }
		if (data[x][y] == 1) { countpl += 1; }
	}
	else {
		Start({ x,y }, size / 3, data);
		Start({ x,y + size / 3 }, size / 3, data);
		Start({ x,y + size * 2 / 3 }, size / 3, data);
		Start({ x + size / 3,y }, size / 3, data);
		Start({ x + size / 3,y + size / 3 }, size / 3, data);
		Start({ x + size / 3,y + size * 2 / 3 }, size / 3, data);
		Start({ x + size * 2 / 3,y }, size / 3, data);
		Start({ x + size * 2 / 3,y + size / 3 }, size / 3, data);
		Start({ x + size * 2 / 3,y + size * 2 / 3 }, size / 3, data);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> data(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	Start({ 0,0 }, n, data);
	cout << countmi << "\n";
	cout << countze << "\n";
	cout << countpl << "\n";
	return 0;
}

