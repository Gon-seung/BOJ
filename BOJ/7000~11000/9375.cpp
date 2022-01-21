#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		int answer = 1;
		map<string, int> data;
		for (int j = 0; j < m; j++) {
			string a = "", b = "";
			cin >> a >> b;
			data[b] += 1;
		}
		for (auto j = data.begin(); j != data.end(); j++) {
			answer *= (*j).second + 1;
		}
		cout << answer - 1 << "\n";
	}
	return 0;
}

