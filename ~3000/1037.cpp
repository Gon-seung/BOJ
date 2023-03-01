#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	int a = 1 << 30, b = 0;
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		if (input < a) { a = input; }
		if (input > b) { b = input; }
	}

	cout << a * b;

	return 0;
}