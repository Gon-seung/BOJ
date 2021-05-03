#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<vector<int>> count(N + 1);
	vector<pair<int, int>> line;
	for (int i = 0; i < N - 1; i++) {
		int u = 0, v = 0;
		cin >> u >> v;
		count[u].push_back(v);
		count[v].push_back(u);
		line.push_back({ u,v });
	}
	long long d_g = 0;
	for (int i = 0; i < line.size(); i++) {
		int x = count[line[i].first].size() - 1;
		int y = count[line[i].second].size() - 1;
		d_g += (long long)x * y;
	}
	for (int i = 1; i <= N; i++) {
		if (count[i].size() >= 3) {
			int x = count[i].size();

			d_g -= (long long)x * (x - 1) * (x - 2) / 2;
			//cout << d_g;
		}
	}
	//cout << d_g;
	if (d_g > 0) { cout << "D"; }
	else if (d_g == 0) { cout << "DUDUDUNGA"; }
	else { cout << "G"; }
	return 0;
}

