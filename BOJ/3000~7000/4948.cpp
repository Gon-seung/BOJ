#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//n ¹Þ±â
	int n = -1;
	while (true) {
		cin >> n;
		if (n == 0) { break; }
		vector<bool> check(2 * n + 1, false);

		check[0] = true;

		check[1] = true;

		for (int i = 2; i <= sqrt(2 * n); i++) {
			if (check[i] == false) {
				for (int j = i + i; j <= 2 * n; j += i) {
					check[j] = true;
				}
			}
		}
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (check[i] == false) {
				//cout << i << endl;
				count += 1;
			}
		}
		cout << count << "\n";
	}
	return 0;
}

