#include <iostream>
#include <vector>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<vector<int>> data(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		data[i][0] = x;
		data[i][1] = y;
	}
	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (data[j][0] > data[i][0] && data[j][1] > data[i][1]) { rank += 1; }

		}
		cout << rank << " ";
	}
	return 0;
}