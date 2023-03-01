#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int	x1 = 0, x2 = 0, y1 = 0, y2 = 0, r1 = 0, r2 = 0;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int rplus = (r1 + r2) * (r1 + r2);
		int rminus = (r1 - r2) * (r1 - r2);

		if (rminus == 0 && dis == 0) { cout << -1 << "\n"; }
		else if (rplus < dis) { cout << 0 << "\n"; }
		else if (rplus == dis) { cout << 1 << "\n"; }
		else if (rminus < dis) { cout << 2 << "\n"; }
		else if (rminus == dis) { cout << 1 << "\n"; }
		else if (rminus > dis) { cout << 0 << "\n"; }
	}

	return 0;
}