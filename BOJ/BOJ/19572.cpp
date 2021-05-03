#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d1 = 0, d2 = 0, d3 = 0;
	cin >> d1 >> d2 >> d3;
	double a = 0, b = 0, c = 0;
	double sum = (double)(d1 + d2 + d3) / 2;
	a = sum - d3;
	b = sum - d2;
	c = sum - d1;
	if (a <= 0 || b <= 0 || c <= 0) { cout << -1; }
	else {
		cout << 1 << endl;
		printf("%.1f %.1f %.1f", a, b, c);
	}
	return 0;
}