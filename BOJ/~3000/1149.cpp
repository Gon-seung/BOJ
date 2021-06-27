#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<vector<int>> data;
	vector<vector<int>> min;
	for (int i = 0; i < n; i++) {
		int r = 0, g = 0, b = 0;
		cin >> r >> g >> b;
		data.push_back({ r,g,b });
	}
	min = { data[0] };
	for (int i = 1; i < n; i++) {
		int r_min, g_min, b_min;
		if (min[i - 1][1] > min[i - 1][2]) { r_min = min[i - 1][2] + data[i][0]; }
		else { r_min = min[i - 1][1] + data[i][0]; }

		if (min[i - 1][0] > min[i - 1][2]) { g_min = min[i - 1][2] + data[i][1]; }
		else { g_min = min[i - 1][0] + data[i][1]; }

		if (min[i - 1][0] > min[i - 1][1]) { b_min = min[i - 1][1] + data[i][2]; }
		else { b_min = min[i - 1][0] + data[i][2]; }

		min.push_back({ r_min,g_min,b_min });
	}

	int answer = min[n - 1][0];
	if (answer > min[n - 1][1]) { answer = min[n - 1][1]; }
	if (answer > min[n - 1][2]) { answer = min[n - 1][2]; }

	cout << answer;
	return 0;
}