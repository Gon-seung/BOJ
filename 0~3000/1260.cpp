#include <iostream>
#include <vector>
using namespace std;

vector<int> Do(vector<bool> done, vector<int> fri, vector<vector<int>> data) {
	vector<int> answer;
	answer = {};
	for (int i = 0; i < fri.size(); i++) {
		for (int j = 0; j < data.size(); j++) {
			if (!done[j] && data[fri[i]][j]) {
				answer.push_back(j);
				//cout << fri[i] << " " << j << endl;
			}
		}
	}

	return answer;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	vector<vector<bool>> data(n, vector<bool>(n, false));
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		data[x - 1][y - 1] = true;
		data[y - 1][x - 1] = true;
	}

	vector<bool> check(n, true);
	vector<int> answer(1, v - 1);
	check[v - 1] = false;
	int size = 0;
	int pos = 0;
	do {
		size -= 1;
		for (int i = 0; i < n; i++) {
			if (data[answer[size + 1]][i] && check[i]) {
				check[i] = false;
				answer.push_back(i);
				size = answer.size() - 1;
				break;
			}
		}
	} while (size != -1);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] + 1 << " ";
	}
	cout << "\n";

	answer = { v - 1 };
	check = vector<bool>(n, true);
	check[v - 1] = false;
	pos = 0;
	do {
		for (int i = 0; i < n; i++) {
			if (data[answer[pos]][i] && check[i]) {
				check[i] = false;
				answer.push_back(i);
			}
		}
		pos += 1;
	} while (pos != answer.size());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] + 1 << " ";
	}

	return 0;
}

