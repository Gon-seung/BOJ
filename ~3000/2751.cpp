#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> data(N);
	for (int i = 0; i < N; i++) {

		int input = 0;
		cin >> input;
		data[i] = input;
	}
	sort(data.begin(), data.end());
	for (int i = 0; i < N; i++) {
		cout << data[i] << "\n";
	}

	return 0;
}