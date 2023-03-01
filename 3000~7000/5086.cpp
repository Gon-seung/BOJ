#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a = 0, b = 0;
	cin >> a >> b;
	while (a != 0 && b != 0) {
		if (b % a == 0) { cout << "factor" << "\n"; }
		else if (a % b == 0) { cout << "multiple" << "\n"; }
		else { cout << "neither" << "\n"; }
		cin >> a >> b;
	}

	return 0;
}