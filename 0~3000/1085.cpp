#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int x = 0, y = 0, w = 0, h = 0;
	cin >> x >> y >> w >> h;
	int min = x;
	if (w - x < min) { min = w - x; }
	if (y < min) { min = y; }
	if (h - y < min) { min = h - y; }

	cout << min;
	return 0;
}