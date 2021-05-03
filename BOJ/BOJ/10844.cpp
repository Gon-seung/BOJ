#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	//data[i][j] = i길이의 마지막이 j일때 나오는 경우의 수
	vector<vector<long long>> data(n, vector<long long>(10, 0));
	data[0][0] = 0;
	for (int i = 1; i < 10; i++) { data[0][i] = 1; }

	for (int i = 1; i < n; i++) {
		data[i][0] = data[i - 1][1];
		for (int j = 1; j < 9; j++) {
			data[i][j] = (data[i - 1][j - 1] + data[i - 1][j + 1]) % 1000000000;
		}
		data[i][9] = data[i - 1][8];
	}


	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += data[n - 1][i];
	}
	cout << answer % 1000000000;
	return 0;
}