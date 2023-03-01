#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	long long a = 0;
	long long b = 1;

	if (n == 1) { cout << 1 << endl; }
	else {
		for (int i = 2; i <= n; i++) {
			long long temp = b;
			b = a + b;
			a = temp;
		}
		cout << b << endl;
	}
	return 0;
}