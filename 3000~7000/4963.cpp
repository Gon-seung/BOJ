#include <iostream>
#include <vector>
using namespace std;

int map[50][50];

int w = 0, h = 0;

bool Check(int x, int y) {
	if (x < w && x >= 0 && y < h && y >= 0 && map[x][y] == 1) { return true; }
	return false;
}

void Expand(int x, int y) {
	map[x][y] = 0;
	if (Check(x + 1, y)) { Expand(x + 1, y); }
	if (Check(x - 1, y)) { Expand(x - 1, y); }
	if (Check(x, y + 1)) { Expand(x, y + 1); }
	if (Check(x, y - 1)) { Expand(x, y - 1); }
	if (Check(x - 1, y - 1)) { Expand(x - 1, y - 1); }
	if (Check(x + 1, y - 1)) { Expand(x + 1, y - 1); }
	if (Check(x - 1, y + 1)) { Expand(x - 1, y + 1); }
	if (Check(x + 1, y + 1)) { Expand(x + 1, y + 1); }

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> h >> w;
	while (w != 0 && h != 0) {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> map[i][j];
			}
		}
		int count = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				//cout << map[i][j];
				if (map[i][j] == 1) {
					count += 1;
					Expand(i, j);
				}
			}
		}
		cout << count << "\n";
		cin >> h >> w;
	}




	return 0;
}

