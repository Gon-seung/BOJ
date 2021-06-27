#include <iostream>
#include <vector>
#include <map>
using namespace std;

int root[201][201];

int find(int x, vector<int>& data) {

	while (data[x] != x) {
		int temp = x;
		x = data[x];
		if (x == -1) { return -1; }
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
	vector<int> gate(n);
	for (int i = 0; i < n; i++) {
		gate[i] = i;
	}

	int answer = 0;
	int count = 0;
	while (count < m) {
		count += 1;
		int input;
		cin >> input;
		int pos = find(input - 1, gate);
		if (pos == -1) { break; }
		else { gate[pos] = pos - 1; answer += 1; }
	}
	while (count < m) {
		count += 1;
		int input;
		cin >> input;
	}
	cout << answer;
	return 0;
}

