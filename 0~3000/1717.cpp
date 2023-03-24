#include <iostream>
#include <vector>
#include <map>
using namespace std;

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
	vector<int> data(n + 1);
	for (int i = 0; i <= n; i++) {
		data[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int ques = 0, x = 0, y = 0;
		cin >> ques >> x >> y;
		if (ques == 0) {
			data[find(y, data)] = find(x, data);
		}
		else {
			if (find(x, data) == find(y, data)) { cout << "YES\n"; }
			else { cout << "NO\n"; }
		}

	}

	return 0;
}

