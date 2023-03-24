#include <iostream> 
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool Compare(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b) {
	return a.second < b.second;
}

bool Com1(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}
bool Com2(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}
bool Com3(vector<int> a, vector<int> b) {
	return a[2] < b[2];
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

	int n = 0;
	cin >> n;
	vector<int> uni(n, 0);
	vector<vector<int>> line;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		line.push_back({ a,b,c,i });
	}
	vector<pair<pair<int, int>, int>> data;

	sort(line.begin(), line.end(), Com1);
	for (int i = 0; i < n - 1; i++) {
		int dis = min(abs(line[i][0] - line[i + 1][0]), abs(line[i][1] - line[i + 1][1]));
		dis = min(dis, abs(line[i][2] - line[i + 1][2]));
		data.push_back({ {line[i][3],line[i + 1][3]}, dis });
	}
	sort(line.begin(), line.end(), Com2);
	for (int i = 0; i < n - 1; i++) {
		int dis = min(abs(line[i][0] - line[i + 1][0]), abs(line[i][1] - line[i + 1][1]));
		dis = min(dis, abs(line[i][2] - line[i + 1][2]));
		data.push_back({ {line[i][3],line[i + 1][3]}, dis });
	}
	sort(line.begin(), line.end(), Com3);
	for (int i = 0; i < n - 1; i++) {
		int dis = min(abs(line[i][0] - line[i + 1][0]), abs(line[i][1] - line[i + 1][1]));
		dis = min(dis, abs(line[i][2] - line[i + 1][2]));
		data.push_back({ {line[i][3],line[i + 1][3]}, dis });
	}


	for (int i = 0; i < n; i++) {
		uni[i] = i;
	}
	sort(data.begin(), data.end(), Compare);

	int pos = 0;
	int answer = 0;
	while (pos < data.size()) {
		pair<int, int> pivot = data[pos].first;
		if (Find(uni, pivot.first) != Find(uni, pivot.second)) {
			answer += data[pos].second;
			uni[Find(uni, pivot.first)] = Find(uni, pivot.second);
		}

		pos += 1;
	}
	printf("%d", answer);
	return 0;
}