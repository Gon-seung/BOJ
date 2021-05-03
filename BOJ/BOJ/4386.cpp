#include <iostream> 
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool Compare(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b) {
	return a.second < b.second;
}

int Find(vector<int>& uni, int x) {
	while (uni[x] != x) {
		int tmp = uni[x];
		uni[x] = uni[tmp];
		x = tmp;
	}
	return x;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int e = 0;
	cin >> e;
	vector<int> uni(e, 0);
	vector<vector<double>> line;
	for (int i = 0; i < e; i++) {
		double a = 0, b = 0;
		cin >> a >> b;
		line.push_back({ a,b });
	}
	vector<pair<pair<int, int>, double>> data;
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < i; j++) {
			double dis = sqrt((line[i][0] - line[j][0]) * (line[i][0] - line[j][0]) + (line[i][1] - line[j][1]) * (line[i][1] - line[j][1]));
			data.push_back({ {i,j}, dis });
		}
	}
	for (int i = 0; i < e; i++) {
		uni[i] = i;
	}
	sort(data.begin(), data.end(), Compare);

	int pos = 0;
	double answer = 0.0;
	while (pos < data.size()) {
		pair<int, int> pivot = data[pos].first;
		if (Find(uni, pivot.first) != Find(uni, pivot.second)) {
			answer += data[pos].second;
			uni[Find(uni, pivot.second)] = Find(uni, pivot.first);
		}

		pos += 1;
	}
	cout << answer << "\n";
	return 0;
}