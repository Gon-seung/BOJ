#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int n, k, m;

vector<int> city;

bool Compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int uni(int a) {
	while (city[a] != a) {
		int tmp = city[a];
		city[a] = city[tmp];
		a = tmp;
	}
	return a;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	vector<int> factory(k);
	for (int i = 0; i < k; i++) {
		int input = 0;
		cin >> input;
		factory[i] = input;
	}

	vector<vector<int>> line(m, vector<int>(3, 0));
	for (int i = 0; i < m; i++) {
		cin >> line[i][0];
		cin >> line[i][1];
		cin >> line[i][2];
	}
	sort(line.begin(), line.end(), Compare);

	city = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		city[i] = i;
	}

	for (int i = 0; i < k; i++) {
		city[factory[i]] = factory[0];
	}

	int answer = 0;
	for (int i = 0; i < m; i++) {
		int city1 = uni(line[i][0]);
		int city2 = uni(line[i][1]);
		if (city1 != city2) {
			city[city2] = city[city1];
			answer += line[i][2];
		}
	}

	cout << answer << "\n";
	return 0;
}