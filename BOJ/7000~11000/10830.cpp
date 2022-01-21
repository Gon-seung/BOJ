#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> remain(vector<vector<int>> data, long long b) {
	int n = data.size();
	vector<vector<int>> answer(n, vector<int>(n, 0));
	if (b == 1) {
		return data;
	}
	else if (b % 2 == 1) {
		vector<vector<int>> newdata = remain(data, b - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int a = 0; a < n; a++) {
					sum += newdata[a][j] * data[i][a];
				}
				sum %= 1000;
				answer[i][j] = sum;
			}
		}
		return answer;
	}
	else {
		vector<vector<int>> newdata = remain(data, b / 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int a = 0; a < n; a++) {
					sum += newdata[a][j] * newdata[i][a];
				}
				sum %= 1000;
				answer[i][j] = sum;
			}
		}
		return answer;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long a = 0, b = 0;
	cin >> a >> b;
	vector<vector<int>> data(a, vector<int>(a, 0));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> data[i][j];
		}
	}

	vector<vector<int>> answer = remain(data, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << answer[i][j] % 1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}