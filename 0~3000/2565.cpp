#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) { return a.first < b.first; }
	else { return a.second < b.second; }
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<pair<int, int>> data(n);
	for (int i = 0; i < n; i++) {
		int input1 = 0, input2 = 0;
		cin >> input1 >> input2;
		data[i] = { input1,input2 };
	}
	sort(data.begin(), data.end(), Compare);
	vector<int> size(n);
	for (int i = 0; i < n; i++) {
		size[i] = 1;
		for (int j = 0; j < i; j++) {
			if (data[j].second < data[i].second && size[i] < size[j] + 1) { size[i] = size[j] + 1; }
		}
	}
	int max = 0, pos = 0;
	for (int i = 0; i < n; i++) {
		if (max < size[i]) { max = size[i]; pos = i; }
	}
	cout << n - size[pos];
	return 0;
}