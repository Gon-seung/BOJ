#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int* data = new int[6];
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		data[i] = x;
		data[i + 3] = y;
	}

	if (data[0] == data[2]) { cout << data[1]; }
	else if (data[0] == data[1]) { cout << data[2]; }
	else if (data[1] == data[2]) { cout << data[0]; }

	cout << " ";

	if (data[3] == data[4]) { cout << data[5]; }
	else if (data[3] == data[5]) { cout << data[4]; }
	else if (data[5] == data[4]) { cout << data[3]; }


	delete[] data;
	return 0;
}