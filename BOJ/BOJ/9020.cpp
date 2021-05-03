#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	int input = 0;
	int* data = new int[T];
	int max = 0;
	for (int i = 0; i < T; i++) {
		cin >> input;
		data[i] = input;
		if (max < input) { max = input; }
	}

	bool* prime = new bool[max + 1]{ false };

	for (int i = 2; i < sqrt(max); i++) {
		if (prime[i]) { continue; }
		else {
			int j = 2;
			while (i * j <= max) { prime[i * j] = true; j += 1; }
		}
	}
	for (int i = 0; i < T; i++) {

		int count = 0;
		int x = data[i];
		while (prime[x / 2 + count] || prime[x / 2 - count]) { count += 1; }
		cout << x / 2 - count << " " << x / 2 + count << "\n";
	}

	delete[] data;
	delete[] prime;
	return 0;
}