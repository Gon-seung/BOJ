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

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> uni(n, 0);
	vector<vector<int>> line;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		line.push_back({ a,b });
	}
	vector<pair<pair<int, int>, double>> data;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			long long xsub = ((long long)line[i][0] - line[j][0]) * ((long long)line[i][0] - line[j][0]);
			xsub += ((long long)line[i][1] - line[j][1]) * ((long long)line[i][1] - line[j][1]);
			double dis = sqrt(xsub);
			data.push_back({ {i,j}, dis });
		}
	}
	for (int i = 0; i < n; i++) {
		uni[i] = i;
	}
	sort(data.begin(), data.end(), Compare);

	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		if (a > b) { int tmp = b; b = a; a = tmp; }
		uni[Find(uni, b - 1)] = Find(uni, a - 1);
	}

	int pos = 0;
	double answer = 0.0;
	while (pos < data.size()) {
		pair<int, int> pivot = data[pos].first;
		if (Find(uni, pivot.first) != Find(uni, pivot.second)) {
			answer += data[pos].second;
			uni[Find(uni, pivot.first)] = Find(uni, pivot.second);
		}

		pos += 1;
	}
	printf("%.2lf", answer);
	return 0;
}