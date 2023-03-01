#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> data;
	if (n % 2 == 0) {
		data.push_back({ 1,2 });
	}
	else {
		data.push_back({ 1,3 });
	}

	int x, y, len = 0;

	for (int i = 2; i <= n; i++) {

		if ((n + i) % 2 == 0) {
			len = data.size();
			data.push_back({ 1,3 });
			for (int j = 0; j < len; j++) {
				x = (data[j][0] + 1) % 3;
				y = (data[j][1] + 1) % 3;
				if (x == 0) { x = 3; }
				if (y == 0) { y = 3; }
				data.push_back({ x,y });
			}
		}
		else {
			len = data.size();
			data.push_back({ 1,2 });
			for (int j = 0; j < len; j++) {
				x = (data[j][0] + 2) % 3;
				y = (data[j][1] + 2) % 3;
				if (x == 0) { x = 3; }
				if (y == 0) { y = 3; }
				data.push_back({ x,y });
			}
		}
	}

	cout << data.size() << "\n";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i][0] << " " << data[i][1] << "\n";
	}

	return 0;
}
