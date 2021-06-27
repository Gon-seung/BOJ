#include <iostream> 
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool Compare(vector<int> a, vector<int> b) {
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

	int v = 0, e = 0;
	cin >> v >> e;
	vector<int> uni(v, 0);
	vector<vector<int>> line;
	for (int i = 0; i < e; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		line.push_back({ a - 1,b - 1,c });
	}
	for (int i = 0; i < v; i++) {
		uni[i] = i;
	}
	sort(line.begin(), line.end(), Compare);

	int pos = 0;
	int answer = 0;
	while (pos < line.size()) {
		vector<int> pivot = line[pos];
		if (Find(uni, pivot[0]) != Find(uni, pivot[1])) {
			answer += pivot[2];
			uni[Find(uni, pivot[1])] = Find(uni, pivot[0]);
		}

		pos += 1;
	}
	cout << answer << "\n";
	return 0;
}