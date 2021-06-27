#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<bool> check(n + 1, false);
	vector<int> data;

	data = { n };
	check[n] = true;
	vector<int> new_data;
	int count = 0;
	while (!check[1]) {
		count += 1;
		new_data.clear();
		for (int i = 0; i < data.size(); i++) {
			if (data[i] % 3 == 0 && !check[data[i] / 3]) { new_data.push_back(data[i] / 3); }
			if (data[i] % 2 == 0 && !check[data[i] / 2]) { new_data.push_back(data[i] / 2); }
			if (!check[data[i] - 1]) { new_data.push_back(data[i] - 1); }
		}

		for (int i = 0; i < new_data.size(); i++) {
			check[new_data[i]] = true;
		}
		data = new_data;
	}
	cout << count;
	return 0;
}