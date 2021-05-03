#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string a = "";
	string b = "";
	cin >> a >> b;


	vector<vector<int>> data(a.size() + 1, vector<int>(b.size() + 1, 0));
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			int n = data[i][j];
			if (i < a.size() && j < b.size() && a[i] == b[j] && n + 1 > data[i + 1][j + 1]) { data[i + 1][j + 1] = data[i][j] + 1; }

			if (j < b.size() && n > data[i][j + 1]) { data[i][j + 1] = data[i][j]; }
			if (i < a.size() && n > data[i + 1][j]) { data[i + 1][j] = data[i][j]; }


		}
	}
	int max = data[a.size()][b.size()];
	if (max < data[a.size() - 1][b.size()]) { max = data[a.size() - 1][b.size()]; }
	if (max < data[a.size()][b.size() - 1]) { max = data[a.size()][b.size() - 1]; }
	cout << max << endl;
	return 0;
}