#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<int> data(10001);
	for (int i = 0; i < N; i++) {

		int input = 0;
		cin >> input;
		data[input] += 1;
	}

	int count = 0;
	for (int i = 0; i <= 10000; i++) {
		for (int j = 0; j < data[i]; j++) {
			cout << i << "\n";
		}
		count += data[i];
		if (count == N) { break; }
	}

	return 0;
}