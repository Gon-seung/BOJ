#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Expend(vector<vector<bool>>& answer, int start, int end) {
	int n = answer.size();
	int count = 0;
	while (start - count >= 0 && end + count < n) { answer[start - count][end + count] = false; count += 1; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> data(n, 1);
	vector<vector<bool>> answer(n, vector<bool>(n, true));
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		data[i] = input;
		for (int j = 0; j < i; j++) {
			if (data[j] != data[i] && answer[j][i]) { Expend(answer, j, i); }
		}
	}

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s = 0, e = 0;
		cin >> s >> e;
		s -= 1;
		e -= 1;
		cout << answer[s][e] << "\n";
	}

}