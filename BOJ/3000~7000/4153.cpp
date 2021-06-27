#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int x = 0, y = 0, z = 0;
	while (true) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) { break; }

		if (x < z && y < z && x * x + y * y == z * z) { cout << "right" << "\n"; }
		else if (x < y && z < y && x * x + z * z == y * y) { cout << "right" << "\n"; }
		else if (z < x && y < x && z * z + y * y == x * x) { cout << "right" << "\n"; }
		else { cout << "wrong" << "\n"; }
	}

	return 0;
}