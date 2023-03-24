#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;
	vector<int> data(N);

	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		data[i] = input;
	}

	int max = 0;
	sort(data.begin(), data.end());
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (data[i] + data[j] + data[k] > M) { break; }
				else if (data[i] + data[j] + data[k] > max) { max = data[i] + data[j] + data[k]; }
			}
		}
	}
	cout << max;
	return 0;
}