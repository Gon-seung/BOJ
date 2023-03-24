#include <iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	bool find = false;
	for (int i = N / 2; i < N; i++) {
		int check = i;
		int sum = check;
		while (check > 0) { sum += check % 10; check /= 10; }
		if (sum == N) { find = true; cout << i; break; }
	}
	if (!find) {
		cout << 0;
	}
	return 0;
}