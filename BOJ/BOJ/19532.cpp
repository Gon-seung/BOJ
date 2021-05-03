#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	cin >> a >> b >> c >> d >> e >> f;
	int x = (e * c - b * f) / (a * e - b * d);
	int y = (-c * d + a * f) / (a * e - b * d);
	cout << x << " " << y << "\n";
	return 0;
}

