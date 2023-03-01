//양식 저장용

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	int X = 0;
	cin >> X;

	int sum = 2;
	while (sum * (sum - 1) / 2 < X) {
		sum += 1;
	}
	int x = 0;
	int y = 0;
	if (sum % 2 == 1) {
		x = sum - 1;
		y = 1;
	}
	else { x = 1; y = sum - 1; }
	int count = 0;
	for (int i = 0; i < sum; i++) {
		if (sum * (sum - 1) / 2 - count == X) { break; }
		else {
			count += 1;
		}
	}
	if (x > y) { x -= count; y += count; }
	else { x += count; y -= count; }
	cout << x << "/" << y;

	return 0;
}
