#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool Compare(vector<long long> a, vector<long long> b) {
	return a[1] < b[1];
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<long long>> city(n, vector<long long>(3, 0));
	vector<long long> up(n);
	vector<long long> down(n);
	map<long long, int> dup;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		city[i] = { i,y,0 };
	}
	for (int i = 0; i < m; i++) {
		long long u = 0, v = 0, e = 0;
		cin >> u >> v >> e;
		if (city[u - 1][1] < city[v - 1][1]) { up[u - 1] += e; down[v - 1] -= e; }
		else { up[v - 1] += e; down[u - 1] -= e; }
	}

	sort(city.begin(), city.end(), Compare);
	long long max = 0;
	long long sum = 0;
	int pos = 0;
	int hei = city[0][1];
	long long upsum = 0;
	long long downsum = 0;
	while (pos < n) {
		hei = city[pos][1];
		upsum = up[city[pos][0]];
		downsum = down[city[pos][0]];
		while (pos + 1 < n && city[pos + 1][1] == hei) {
			pos += 1;
			upsum += up[city[pos][0]];
			downsum += down[city[pos][0]];
		}
		sum += upsum;
		if (sum > max) { max = sum; }
		sum += downsum;
		if (sum > max) { max = sum; }
		pos += 1;

	}
	cout << max;
	return 0;
}