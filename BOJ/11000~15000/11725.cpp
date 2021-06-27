#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> answer(n, -1);
	answer[0] = 0;
	vector<vector<int>> data(n);
	while (n > 1) {
		n -= 1;
		int a = 0, b = 0;
		cin >> a >> b;
		a -= 1; b -= 1;
		data[a].push_back(b);
		data[b].push_back(a);
	}
	vector<int> pos = { 0 };
	while (pos.size() > 0) {
		vector<int> newpos;
		for (int i = 0; i < pos.size(); i++) {
			int cur = pos[i];
			for (int j = 0; j < data[cur].size(); j++) {
				int check = data[cur][j];
				if (answer[check] == -1) { newpos.push_back(check); answer[check] = cur; }
			}
		}
		pos = newpos;
	}
	for (int i = 1; i < answer.size(); i++) {
		cout << answer[i] + 1 << "\n";
	}

	return 0;
}