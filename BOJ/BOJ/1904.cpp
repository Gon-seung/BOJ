#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	int bef = 1;
	int aft = 1;
	if (n == 1) { cout << 1 << endl; }
	else {
		for (int i = 2; i <= n; i++) {
			int temp = aft;
			aft = (aft + bef) % 15746;
			bef = temp;
		}
		cout << aft << endl;
	}

	return 0;
}