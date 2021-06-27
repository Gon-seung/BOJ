#include <iostream>
#include <vector>
#include <map>
using namespace std;

int root[201][201];

int find(int x, vector<int>& data) {
	while (data[x] != x) {
		int temp = x;
		x = data[x];
		data[temp] = data[x];
	}
	return x;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		data[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			root[i][j] = input;
			if (input == 1) { data[find(j, data)] = find(i, data); }
		}
	}

	bool checkno = false;
	if (m > 0) {
		int input;
		cin >> input;
		int check = find(input - 1, data);
		for (int i = 0; i < m - 1; i++) {
			cin >> input;
			if (check != find(input - 1, data)) {
				cout << "NO";
				checkno = true;
				break;
			}
		}
	}
	if (!checkno) { cout << "YES"; }
	return 0;
}

