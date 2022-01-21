#include <iostream>
#include <vector>
using namespace std;

int map[100][100];
int n = 0;
void Start() {
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 << 29 || (i == j)) { map[i][j] = 0; }
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int m = 0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 1 << 29;
		}
	}

	for (int i = 0; i < m; i++) {
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		map[x - 1][y - 1] = map[x - 1][y - 1] > z ? z : map[x - 1][y - 1];

	}

	Start();

	return 0;
}

